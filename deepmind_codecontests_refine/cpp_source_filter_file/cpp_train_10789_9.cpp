#include <bits/stdc++.h>
using namespace std;
int n, q[10005];
long long W, B, X, f[10005], g[10005], cost[1005], c[1005];
int main() {
  int i, j;
  cin >> n >> W >> B >> X;
  for (i = 1; i <= n; ++i) cin >> c[i];
  for (i = 1; i <= n; ++i) cin >> cost[i];
  for (i = 0; i <= 10000; ++i) f[i] = -1;
  for (i = 0; i <= c[1] && i * cost[i] <= W; ++i) f[i] = W - i * cost[1];
  for (i = 2; i <= n; ++i) {
    int h = 0, t = -1;
    for (j = 0; j <= 10000; ++j) {
      if (f[j] < 0)
        g[j] = -1;
      else
        g[j] = min(f[j] + X, W + j * B);
      for (; h <= t && g[j] - g[q[t]] >= (q[t] - j) * cost[i]; --t)
        ;
      q[++t] = j;
      for (; h <= t && q[h] < j - c[i]; ++h)
        ;
      if (g[q[h]] < 0)
        f[j] = -1;
      else
        f[j] = g[q[h]] - (j - q[h]) * cost[i];
    }
  }
  for (i = 10000; ~i; --i)
    if (~f[i]) break;
  cout << i;
  return 0;
}
