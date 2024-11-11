#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main()
{
int n;
  cin>>n;
  string s;
  cin>>s;
  for(auto i:s)cnt[i-'a']++;
  long long ans=1;
  for(int i=0;i<26;i++)
  {
    ans*=(cnt[i]+1);
    ans%=(int)(1e9+7);
  }
cout<<ans-1;
}