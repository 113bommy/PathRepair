#include <bits/stdc++.h>
const long long mo = 998244353;
const int maxn = 3000;
int n, k, h[maxn];
long long d[maxn][maxn * 2];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", h + i);
  d[0][0 + maxn] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = -i; j <= i; ++j) {
      if (h[i - 1] == h[i % n]) {
        d[i][j + maxn] += d[i - 1][j + maxn] * (long long)k % mo;
        d[i][j + maxn] %= mo;
      } else {
        d[i][j + 1 + maxn] += d[i - 1][j + maxn];
        d[i][j + 1 + maxn] %= mo;
        d[i][j - 1 + maxn] += d[i - 1][j + maxn];
        d[i][j - 1 + maxn] %= mo;
        d[i][j + maxn] += d[i - 1][j + maxn] * (long long)(k - 2ll) % mo;
        d[i][j + maxn] %= mo;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans = (ans + d[n][i + maxn]) % mo;
  printf("%lld\n", ans);
  return 0;
}
