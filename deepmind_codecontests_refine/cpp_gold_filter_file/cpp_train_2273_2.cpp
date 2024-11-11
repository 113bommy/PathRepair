#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long n,i,a,c=0;
  map<long long,long long>mp;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a;
    mp[a]++;
  }
  for(auto u:mp)
  {
    if(u.first<u.second)
      c+=u.second-u.first;
    else if(u.first>u.second)
      c+=u.second;
  }
  cout<<c;
  return 0;
}