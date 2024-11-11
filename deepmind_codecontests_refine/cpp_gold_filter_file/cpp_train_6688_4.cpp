#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
template <class T>
inline bool ckmin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool ckmax(T& a, T b) {
  return b > a ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const char nl = '\n';
const int mxN = 2e5 + 10;
const int MOD = 1e9 + 7;
const long long infLL = 1e18;
void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = (0); i < (n); i++) cin >> a[i];
  vi b(n);
  vi l, m, r;
  for (int i = (0); i < (n); i++) {
    if (a[i] == k) {
      m.push_back(a[i]);
      b[i] = 2;
    } else if (a[i] < k) {
      l.push_back(a[i]);
      b[i] = 0;
    } else {
      r.push_back(a[i]);
      b[i] = 1;
    }
  }
  if (m.size()) {
    if (n == 1)
      cout << "yes\n";
    else {
      for (int i = (0); i < (n); i++) {
        for (int j = (-2); j < (3); j++) {
          if (j == 0) continue;
          if (i + j >= 0 && i + j < n && b[i] && b[i + j]) {
            cout << "yes\n";
            return;
          }
        }
      }
      cout << "no\n";
    }
  } else {
    cout << "no\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
