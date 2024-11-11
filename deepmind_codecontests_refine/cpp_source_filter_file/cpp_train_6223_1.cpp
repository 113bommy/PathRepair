#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;
  cin>>s>>t;
  int n=s.length();
  int m=t.length();
  int i,j,c,ans=0;
  for(i=0;i<=n-m;i++)
  {
    c=0;
    for(j=i;j<i+m;j++)
    {
      if(s[j]==t[j-i]
         c++;
    }
    ans=max(ans,c);
  }
  cout<<m-ans;
  return 0;
}