#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size(), a = 1e9;
  rep(i, n-m+1){
    int u = 0;
    rep(j, m) if(s[i+j] != t[j]) ++u;
    a = min(a, u);
  }
  cout << a << "\n";
  return 0;
}