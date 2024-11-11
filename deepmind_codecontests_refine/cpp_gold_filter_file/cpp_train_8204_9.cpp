#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, m = 0;
  string s;
  cin >> n >> s;
  rep(i, n-1){
    unordered_set<char> a, b;
    int c = 0;
    rep(j, n){
      if(j <= i) a.insert(s[j]);
      else b.insert(s[j]);
    }
    for(auto d: a){
      if(b.count(d)) ++c;
    }
    m = max(m, c);
  }
  cout << m << endl;
  return 0;
}