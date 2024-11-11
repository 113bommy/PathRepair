#include<iostream>
using namespace std;
string s;
int c;
int main(){
getline(cin,s);
while(c<s.length()){
if(s[i]!='0'&&s[i]!='1')
if(i>0) s.erase(c-1,2),c--;
else s.erase(c,1);
else c++;}
cout<<s<<endl;}