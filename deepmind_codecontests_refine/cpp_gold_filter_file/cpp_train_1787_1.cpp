#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long INF = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-8;
const long double pi = acos(-1.0);
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<int> r(n, inf);
  for (int k = 1; k <= 4; ++k) {
    for (int x = 0; x < n; x++) {
      if (x + 2 * k < n && s[x] == s[x + k] && s[x] == s[x + 2 * k]) {
        chmin(r[x], x + 2 * k);
      }
    }
  }
  int tmp = inf;
  for (int i = n - 1; i >= 0; --i) {
    chmin(tmp, r[i]);
    r[i] = tmp;
  }
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    if (r[i] != inf) cnt += (long long)(n - r[i]);
  }
  cout << cnt << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
