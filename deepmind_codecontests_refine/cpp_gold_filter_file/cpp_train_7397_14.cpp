#include<iostream>
using namespace std;
int main(){
int a,b;
string op;

while(1){
cin>>a>>op>>b;
if(op=="?") break;
if(op=="+")
cout<<a+b<<endl;
if(op=="-")
cout<<a-b<<endl;
if(op=="/")
cout<<a/b<<endl;
if(op=="*")
cout<<a*b<<endl;

}
return 0;
}
