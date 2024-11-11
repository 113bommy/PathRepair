#include<iostream>
#include<string>
using namespace std;
int main()
{
  int a,b,i;
  cin>>a>>b;
  string s[a];
  for(i=0;i<a;i++)
  {
      cin>>s[i];
  }
  sort(s,s+a);
  for(i=0;i<a;i++)
  {
      cout<<s[i];
  }








}
