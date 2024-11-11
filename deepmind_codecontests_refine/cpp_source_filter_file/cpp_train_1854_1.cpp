#include<iostream>
using namespace std;
int main()
{
    string s;
  cin>>s;
    if(s[0]!=s[1] && s[1]!=s[2] && s[2]!=s[3])
      cout<<Good;
  else
    cout<<Bad;
  return 0;
      
}