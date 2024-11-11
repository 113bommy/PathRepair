#include<iostream>
#include<string>
using namespace std;
int main()
{int k;
 cin>>k;
 string s;
 cin>>s;
 if(s.length()>k)
   s=s.substr(0,k)+"...";
     cout<<s;
 return 0;}