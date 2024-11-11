#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
inline long long pow_mod(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return r;
}
inline long long pow_(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x);
    x = (x * x);
    n >>= 1;
  }
  return r;
}
inline void solve() {
  int n, m;
  cin >> n >> m;
  long long max_sweets_sum = 0;
  long long res = 0;
  int b[n], g[m];
  for (int i = 0; i < n; i++) cin >> b[i], res += b[i];
  for (int i = 0; i < m; i++) cin >> g[i], max_sweets_sum += g[i];
  sort(b, b + n);
  sort(g, g + m);
  if (b[n - 1] > g[0]) {
    cout << "-1\n";
    return;
  }
  res *= m;
  res -= (m - 1LL) * b[n - 1];
  if (binary_search(g, g + m, b[n - 1]))
    res -= b[n - 1];
  else
    res -= b[n - 2];
  cout << res + max_sweets_sum;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
}
