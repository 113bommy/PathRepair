#include<iostream>
using namespace std;
string s;
int c;
int main(){
getline(cin,s);
while(c<s.length()){
if(s[c]!='0'&&s[c]!='1')
if(c>0) s.erase(c-1,2),c--;
else s.erase(c,1);
else c++;}
cout<<s<<endl;}