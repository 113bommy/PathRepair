#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  string s;
  cin>>n;
  cin>>s;
  int c=0,t=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='.') c++;
  }
  t=c;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='#') c++;
    else c--;
    if(c<t) t=c;
  }
  cout<<t;
  return 0;
}
