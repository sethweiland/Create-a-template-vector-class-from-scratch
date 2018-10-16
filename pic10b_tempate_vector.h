
//create a template vector class from scratch focusing on operator overloading and constructors
#ifndef pic10b_vector_h
#define pic10b_vector_h


#include <string>
#include <iostream>
#include <cmath>
namespace Pic10b{
    template<typename T>
    class vector;
    
    
    template<typename T> class vector{
    private:
        T* the_data;
        size_t the_size;
        size_t the_capacity;
        
        static const int INIT_CAP = 10;
        
        
    public:
        // The big 4
        vector();
        vector( const vector<T>& source);
        vector(int n);
        vector<T>& operator=( const vector<T>& rhs);
        ~vector();
        
        //T operator*(const vector<T>&rhs);
        
        //vector<T> operator*(T rhs);
        
        vector<T>& operator+=(const vector<T>&rhs);
        vector<T> operator+(const vector<T>&rhs);
        
        // Other members [public]
        
        
        bool operator<(const vector<T>& rhs);
         bool operator<=(const vector<T>& rhs);
         bool operator>(const vector<T>& rhs);
         bool operator>=(const vector<T>& rhs);
         bool operator==(const vector<T>& rhs);
         bool operator!=(const vector<T>& rhs);
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        //T front() const;
        //T back() const;
        //T at( size_t index ) const;
        T& operator[]( size_t index );
        T operator[]( size_t index ) const;
      //  void dump_data_to( std::ostream& out ) const;
        //void dump_data() const;
        void push_back( T new_value );
        void pop_back();
        
    private:
        //Other members [private]
        void reserve( size_t new_capacity );
        
    }; // end Pic10b::vector
    
    
    /** ************************* THE BIG 4 *************************(just what the teacher calls them for some reason) **/
    template<typename T> vector<T>::vector() : the_data(nullptr), the_size(0), the_capacity(INIT_CAP) {
        
        the_data = new T[the_capacity];
        std::cout<<"xxx: Default Constructor :xxx"<<std::endl;
    }
    
    template<typename T> vector<T>::vector( const vector<T>& source ) : the_data(nullptr), the_size(source.the_size), the_capacity(source.the_capacity) {
        
        the_data = new T[the_capacity];
        
        // Deep copy of internal array
        for ( int i = 0 ; i < the_size ; ++i ){
            the_data[i] = source.the_data[i];
        }
    std::cout<<"xxx: Copy Constructor :xxx"<<std::endl;

}
    
    template<typename T> vector<T>& vector<T>::operator=( const vector<T>& rhs ) {
        if ( this != &rhs ) {     // Self-assignment?
            // Release old memory and request more
            delete[] the_data;
            the_data = new T[rhs.the_capacity];
            
            // Shallow copy non-pointers
            the_size = rhs.the_size;
            the_capacity = rhs.the_capacity;
            
            // Deep copy internal array
            for ( int i = 0 ; i < the_size ; ++i )
                the_data[i] = rhs.the_data[i];
        }
            std::cout<<"xxx: Assignment Operator :xxx"<<std::endl;
        return *this;
    

    }
    
    template<typename T> vector<T>::~vector() {
        delete[] the_data;
        std::cout<<"xxx: Destructor :xxx"<<std::endl;
    }
    
    /** *********************** OTHER MEMBERS *********************** **/
  
    template<typename T> vector<T>::vector(int n)  {
        the_capacity=INIT_CAP;
        the_size=0;
        the_data=new T[the_capacity];
            the_data[0]=n;
    }
    
   template <typename T> size_t vector<T>::size() const {
        return the_size;
    }
    
    template <typename T> size_t vector<T>::capacity() const {
        return the_capacity;
    }
    
    
    template <typename T> T& vector<T>::operator[]( size_t index ){
        return the_data[index];
    }
    template <typename T> T vector<T>::operator[]( size_t index ) const {
        return the_data[index];
    }
    
    template<typename T> void vector<T>::push_back( T new_value ){
        if ( the_size == the_capacity )
            reserve( the_capacity + 1 );     // `the_data` is reassigned
        
        the_data[the_size++] = new_value;
    }
    
    // This implementation does not shrink the vector (ever)
    template <typename T> void vector<T>::pop_back(){
        if ( the_size > 0 )
            --the_size;
    }
    
    
    template <typename T> void vector<T>::reserve( size_t new_capacity ){
        if ( new_capacity > the_capacity ) {
            if ( new_capacity <= 2 * the_capacity )
                new_capacity = 2 * the_capacity;
            
            T* old_location = the_data;
            
            the_data = new T[new_capacity];
            the_capacity = new_capacity;
            
            for ( size_t i = 0 ; i < the_size ; ++i )
                the_data[i] = old_location[i];
            
            delete old_location;
        }
    }
    
   
     
    
    
    template <typename T> vector<T>& vector<T>::operator+=(const vector<T>& rhs) {

        
        for(size_t i= 0; i<the_size; i++) {
            the_data[i] = the_data[i]+rhs.the_data[i];
        }
        return *this;
    }
    
    
    template< typename T> vector<T> vector<T>::operator+(const vector<T>& rhs) {

        vector<T> v1(*this);
        
        for(size_t i = 0; i<the_size; i++) {
            v1.the_data[i] = v1.the_data[i]+rhs.the_data[i];
        }
        return v1;
    }
    template <typename T> bool vector<T>::operator<(const vector<T>& rhs) {
        T implicitCompare = 0;
        T explicitCompare= 0;
        for(size_t i =0;i<the_size;i++) {
            implicitCompare += (the_data[i]*the_data[i]);
        }
        implicitCompare = sqrt(implicitCompare);
        for(size_t i =0;i<rhs.the_size;i++) {
            explicitCompare += (rhs.the_data[i]*rhs.the_data[i]);
        }
        explicitCompare=sqrt(explicitCompare);
        if(implicitCompare<explicitCompare) {
            return true;
        }
        else {
            return false;
        }
    }
    template <typename T> bool vector<T>::operator<=(const vector<T>& rhs) {
        T implicitCompare=0;
        T explicitCompare=0;
        for(size_t i =0;i<the_size;i++) {
            implicitCompare += (the_data[i]*the_data[i]);
        }
        implicitCompare = sqrt(implicitCompare);
        for(size_t i =0;i<rhs.the_size;i++) {
            explicitCompare += (rhs.the_data[i]*rhs.the_data[i]);
        }
        explicitCompare=sqrt(explicitCompare);
        if(implicitCompare<explicitCompare || implicitCompare == explicitCompare) {
            return true;
        }
        else {return false;}
    }
    template <typename T> bool vector<T>::operator>(const vector<T>& rhs) {
        T implicitCompare=0;
        T explicitCompare=0;
        for(size_t i =0;i<the_size;i++) {
            implicitCompare += (the_data[i]*the_data[i]);
        }
        implicitCompare = sqrt(implicitCompare);
        for(size_t i =0;i<rhs.the_size;i++) {
            explicitCompare += (rhs.the_data[i]*rhs.the_data[i]);
        }
        explicitCompare=sqrt(explicitCompare);
        if(implicitCompare>explicitCompare) {
            return true;
        }
        else {
            return false;
        }
    }
    
    template <typename T> bool vector<T>::operator>=(const vector<T>& rhs) {
        T implicitCompare=0;
        T explicitCompare=0;
        for(size_t i =0;i<the_size;i++) {
            implicitCompare += (the_data[i]*the_data[i]);
        }
        implicitCompare = sqrt(implicitCompare);
        for(size_t i =0;i<rhs.the_size;i++) {
            explicitCompare += (rhs.the_data[i]*rhs.the_data[i]);
        }
        explicitCompare=sqrt(explicitCompare);
        if(implicitCompare>explicitCompare || implicitCompare == explicitCompare) {
            return true;
        }
        else {
            return false;
        }
    }
    
    template <typename T> bool vector<T>::operator==(const vector<T>& rhs) {
        
        T implicitCompare=0;
        T explicitCompare=0;
        for(size_t i =0;i<the_size;i++) {
            implicitCompare += (the_data[i]*the_data[i]);
        }
        implicitCompare = sqrt(implicitCompare);
        for(int i =0;i<rhs.the_size;i++) {
            explicitCompare += (rhs.the_data[i]*rhs.the_data[i]);
        }
        explicitCompare=sqrt(explicitCompare);
        if(implicitCompare==explicitCompare) {
            return true;
        }
        else {
            return false;
        }
         

    }
    template <typename T> bool vector<T>::operator!=(const vector<T>& rhs) {
    
        
        T implicitCompare=0;
        T explicitCompare=0;
        for(int i =0;i<the_size;i++) {
            implicitCompare += (the_data[i]*the_data[i]);
        }
        implicitCompare = sqrt(implicitCompare);
        for(int i =0;i<rhs.the_size;i++) {
            explicitCompare += (rhs.the_data[i]*rhs.the_data[i]);
        }
        explicitCompare=sqrt(explicitCompare);
        if(implicitCompare==explicitCompare) {
            return false;
        }
        else {
            return true;
        }
         
         
    }
    
    vector<std::string> operator*(std::string lhs, const vector<std::string>& rhs){
        vector<std::string> result(rhs);
        
        for (int i = 0; i < rhs.size(); i++){
            result[i] = lhs + " " + result[i];
        }
        
        return result;
    }
    
    vector<std::string> operator*(const vector<std::string>& lhs, std::string rhs){
        vector<std::string> result(lhs);
        
        for (int i = 0; i < rhs.size(); i++){
            result[i] = result[i] + " " + rhs;
        }
        
        return result;
    }
    
    
    template <typename T>
    vector<T> operator*(T lhs, const vector<T>& rhs){
        vector<T>result(rhs);
        
        for (int i = 0; i < result.size();i++){
            result[i] *= lhs;
        }
        
        
        return result;
    }
    template <typename T>
    vector<T> operator*(const vector<T>& lhs, T rhs){
        return operator*(rhs, lhs);
    }
    
    //dot product function
    template <typename T>
    T operator*(const vector<T>& lhs, const vector<T>& rhs) {
        
        T result = 0;
        
        // NOT SURE WHAT TO DO WHEN lhs size doesn't equal rhs (stop at smaller one for now)
        for (int i = 0; i < lhs.size() && i < rhs.size(); i++){
            result += lhs[i] * rhs[i];
        }
        
        return result;
    }
    
    template <typename T>
    std::ostream& operator<<( std::ostream& out, const vector<T>& v ){
        out<<"{";
        for ( size_t i = 0 ; i < v.size() ; ++i ) {
            out <<v[i];
            if(i<v.size()-1) {
                out<<", ";
            }
            else {
                break;
            }
        }
        out<<"}";
        return out;
    }
    
    std::ostream& operator<<( std::ostream& out, const vector<std::string>& v ){
      
        out<<"[ ";
        for ( size_t i = 0 ; i < v.size() ; ++i ) {
            out <<v[i];
            if(i<v.size()-1.0) {
                out<<", ";
            }
            else {
                break;
            }
        }
        out<<" ]";
        return out;
    }


} // end Pic10b namespace




#endif
