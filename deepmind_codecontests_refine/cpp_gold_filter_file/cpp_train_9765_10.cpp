#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  cin>>n;
  map<string, int> mp;
  long long ans=0;
  rep(i,n){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(mp[s]>0) ans+=mp[s];
    mp[s]++;
  }
  cout<<ans<<endl;
}