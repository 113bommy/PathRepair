#include <bits/stdc++.h>
using namespace std;
const int mxn = 40, k = mxn / 2;
int n, m;
long long g[mxn], par[mxn << 1], rnk[mxn << 1];
long long dp[1 << k];
int fnd(int x) { return x == par[x] ? x : par[x] = fnd(par[x]); }
void unf(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) swap(x, y);
  rnk[x] += rnk[x] == rnk[y];
  par[y] = x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < 2 * n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x] |= 1ll << y, g[y] |= 1ll << x;
    unf(x, n + y), unf(n + x, y);
  }
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i < n) x += !g[i];
    if (fnd(i) == i) {
      int w = fnd((n + i) % (2 * n)) == i;
      y += 1 + w;
      z |= w;
    }
  }
  y /= 2;
  for (int i = 0; i < (1 << min(n, k)); i++) {
    dp[i] = 1;
    for (int j = 0; j < min(n, k); j++)
      if ((i >> j) & 1) dp[i] &= !(i & g[j]);
  }
  for (int i = 0; i < k; i++)
    for (int j = 0; j < (1 << k); j++) {
      if ((j >> i) & 1) dp[j] += dp[j ^ (1 << i)];
    }
  long long ret = !!m * (1ll << n) + 2 * (1ll << x) - z * (1ll << y);
  for (int i = 0; i < (1 << max(0, n - k)); i++) {
    int first = 0;
    for (int j = 0; j < max(0, n - k); j++)
      if ((i >> j) & 1) first |= g[k + j];
    ret -= !(i & (first >> k)) * 2 * dp[((1 << k) - 1) & ~first];
  }
  cout << ret << '\n';
  return 0;
}
