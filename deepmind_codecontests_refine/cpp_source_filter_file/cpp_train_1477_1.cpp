#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = mod * mod;
const long double eps = 1e-8;
long long num[10000];
void init() {
  for (int i = 2; i < 10000; i++) {
    num[i] = i * (i - 1) / 2;
  }
}
const int sz = 10000;
void solve() {
  int n;
  cin >> n;
  string ans;
  vector<int> c(sz, 0);
  for (int i = sz - 1; i > 0; i--) {
    if (num[i] > 0) {
      c[i] += n / num[i];
      n %= num[i];
    }
  }
  ans.push_back('1');
  for (int i = 0; i < sz - 1; i++) {
    for (int j = 0; j < c[i]; j++) {
      ans.push_back('7');
    }
    ans.push_back('3');
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
