#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
  cin >> n;
  double f[n],ans;
  ans=0;
  string s[n];
  for(int i=0;i<n;++i)
  {
  cin >> f[i] >> s[i];
  if(s[i]=="JPY") ans=ans+f[i];
  else ans=ans+f[i]*380000;
  }
  cout << ans;
return 0;}