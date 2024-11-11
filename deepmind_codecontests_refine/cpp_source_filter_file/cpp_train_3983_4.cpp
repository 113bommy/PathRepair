#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool ckmin(T& a, T b) {
  if (a > b) a = b;
  return b == a;
}
template <class T>
inline bool ckmax(T& a, T b) {
  if (a < b) a = b;
  return b == a;
}
const int MOD = 1e9 + 7;
const int mxN = 2e5 + 10;
int n, m, a[mxN], b[mxN], ans = 1;
int mul(int a, int b) { return a * (int64_t)b % MOD; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  bool good = 1;
  int p1 = n - 1, p2 = n - 1, mn = a[n - 1];
  for (int i = m - 1; i >= 0; i--) {
    while (p2 > 0 && mn > b[i]) {
      ckmin(mn, a[--p2]);
    }
    if (mn != b[i]) {
      good = 0;
      break;
    }
    p1 = p2;
    while (p1 > 0 && a[p1 - 1] >= b[i]) --p1;
    if (i == 0) break;
    ans = mul(ans, p2 - p1 + 1);
  }
  for (int i = p2 - 1; i >= 0; i--) {
    if (a[i] < mn) {
      good = 0;
    }
  }
  if (good)
    cout << ans << '\n';
  else {
    cout << 0 << '\n';
  }
  return 0;
}
