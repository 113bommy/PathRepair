#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int c[maxn][maxn];
int dp[maxn][maxn], sum[maxn];
int main() {
  int n, d, m, ty;
  scanf("%d%d%d", &n, &d, &m);
  for (int i = (0), iend = (maxn - 1); i <= iend; i++) {
    c[0][i] = 1;
    for (int j = (1), jend = (i); j <= jend; j++)
      c[j][i] = (1ll * c[j - 1][i - 1] + c[j][i - 1]) % m;
  }
  dp[1][0] = 1, sum[1] = 1;
  for (int i = (2), iend = (n); i <= iend; i++) {
    for (int j = (1), jend = (d); j <= jend; j++)
      for (int k = (1), kend = (i - 1); k <= kend; k++) {
        dp[i][j] = (dp[i][j] +
                    1ll * dp[i - k][j - 1] * sum[k] % m * c[k - 1][i - 2] % m) %
                   m;
      }
    for (int u = (0), uend = (d - 1); u <= uend; u++)
      sum[i] = (1ll * sum[i] + dp[i][u]) % m;
  }
  int ans = 0;
  for (int i = (1), iend = (n); i <= iend; i++) {
    for (int j = (0), jend = (d); j <= jend; j++)
      for (int k = 0; j + k <= d; k++) {
        ans = (ans + 1ll * dp[i][j] * dp[n - i + 1][k]) % m;
      }
  }
  for (int i = (1), iend = (n); i <= iend; i++)
    for (int j = (0), jend = (d - 1); j <= jend; j++)
      for (int k = (0), kend = (d - 1); k <= kend; k++) {
        ans = (ans - 1ll * dp[i][j] * dp[n - i][k]) % m;
      }
  ans = (1ll * ans % m + m) % m;
  printf("%d", 2ll * ((n * 1ll * (n - 1)) % m) % m * ans % m);
  return 0;
}
