#include<iostream> 
#include<string>
using namespace std; 
int main()
{
string s; 
cin>>s;
for(int i=0;i<s.size();i++)
{
if(s[i]=='1')
cout<<9;
else 
cout<<1;
}
}