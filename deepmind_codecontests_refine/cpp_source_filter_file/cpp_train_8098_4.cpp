#include<iostream>
using namespace std

int main(){
    int N,a;
    cin>>N;
    a = min(9,N)+min(900,max(0,N-99))+min(90000,max(0,N-9999));
    cout<<a;
return 0;
}