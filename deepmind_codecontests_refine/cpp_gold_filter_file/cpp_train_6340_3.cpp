#include<iostream>
using namespace std;
int main(){
int a,b;
while(cin>>a>>b){
if(a<b)swap(a,b);
while(b){
a=a%b;
swap(a,b);
}
cout<<a<<endl;
}
}