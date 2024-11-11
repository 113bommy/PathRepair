#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

int main(){
  string s,t;
  cin >> s >> t;
  int n = sz(s), m = sz(t);
  vector<vector<int>> dic(26);
  rep(i,n) dic[s[i]-'a'].push_back(i);
  rep(i,n) dic[s[i]-'a'].push_back(i+n);
  ll ans = 0;
  int p = 0;
  rep(i,m){
    int c = t[i]-'a';
    if(dic[c].size==0){
      puts("-1");
      return 0;
    }
    p = *lower_bound(dic[c].begin(),dic[c].end(),p)+1;
    if(p>=n){
      p -= n;
      ans += n;
    }
  }
  ans += p;
  cout << ans << endl;
}