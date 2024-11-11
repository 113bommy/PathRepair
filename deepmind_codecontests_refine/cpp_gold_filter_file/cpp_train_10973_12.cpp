#include <bits/stdc++.h>
const int M = 2005;
long long f[M][M], g[M][M];
char S[M];
int n, m;
int main() {
  scanf("%d%d%s", &n, &m, S + 1);
  f[0][0] = g[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = g[i - 1][j] * (S[i] - 'a' + (i == n));
      int l = 1, r = i;
      while (l <= r && (i - l + 1) * (n - i + 1) <= j) ++l;
      while (l <= r && (i - r + 1) * (n - i + 1) <= j) --r;
      for (int k = 1; k < l; ++k)
        f[i][j] += f[k - 1][j - (i - k + 1) * (n - i + 1)] * ('z' - S[i]);
      for (int k = i; k > r; --k)
        f[i][j] += f[k - 1][j - (i - k + 1) * (n - i + 1)] * ('z' - S[i]);
      f[i][j] %= 1000000007;
    }
    for (int j = 0; j <= m; ++j) g[i][j] = (g[i - 1][j] + f[i][j]) % 1000000007;
  }
  printf("%lld\n", f[n][m]);
  return 0;
}
