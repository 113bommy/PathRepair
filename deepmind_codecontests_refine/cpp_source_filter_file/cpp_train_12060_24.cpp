#include<iostream>
#include<string>
using namespace std;
int main(void){
string s;
cin>>s;
cout<<s.substr(0,s.length()?8)<<endl;
return 0;
}