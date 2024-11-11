#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, inv = 500000004;
long long n, k, c[100][100], dp[100][100][2];
int main() {
  scanf("%I64d%I64d", &n, &k);
  for (int i = 1; i <= n; i++) c[i][0] = c[i][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  dp[0][0][1] = dp[1][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= ((k) < (i - 1) ? (k) : (i - 1)); j++) {
      for (int p = 0; p <= j; p++)
        for (int l = 0, r = i - 1; l <= r; l++, r--) {
          long long tmp = c[i - 1][l];
          if (l == r) tmp = tmp * inv % mod;
          if (l)
            tmp = tmp * l * r % mod;
          else if (r)
            tmp = tmp * r % mod;
          dp[i][j][0] =
              (dp[i][j][0] + dp[l][p][1] * dp[r][j - p][1] % mod * tmp) % mod;
          if (p < j) {
            dp[i][j][1] =
                (dp[i][j][1] + dp[l][p][0] * dp[r][j - p - 1][0] % mod * tmp) %
                mod;
            dp[i][j][1] =
                (dp[i][j][1] + dp[l][p][1] * dp[r][j - p - 1][0] % mod * tmp) %
                mod;
            dp[i][j][1] =
                (dp[i][j][1] + dp[l][p][0] * dp[r][j - p - 1][1] % mod * tmp) %
                mod;
          }
        }
    }
  printf("%I64d", (dp[n][k][0] + dp[n][k][1]) % mod);
  return 0;
}
