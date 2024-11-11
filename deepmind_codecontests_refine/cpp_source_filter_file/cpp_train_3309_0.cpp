include <bits/stdc++.h>
using namespace std;
string s,t,u;
long long a,b;
int main()
{
  cin>>s>>t>>a>>b>>u;
  if(u==s) a--;
  else b--;
  cout<<a<<' '<<b;
  return 0;
}