#include<iostream>
#include<bits/stdc++.h>
using namespaces std;
int main()
{
  string s;cin>>s;
  for(int i=0;i<s.length();i+=2)
  {
    if(s[i]!='h' || s[i+1]!='i')
    { cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes";
}
      