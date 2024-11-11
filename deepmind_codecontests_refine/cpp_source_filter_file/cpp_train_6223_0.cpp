#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size(), a = 1e9;
  rep(i, n-m+1){
    int t = 0;
    rep(j, m) if(s[i+j] == t[j]) ++t;
    a = min(a, t);
  }
  cout << a << endl;
  return 0;
}