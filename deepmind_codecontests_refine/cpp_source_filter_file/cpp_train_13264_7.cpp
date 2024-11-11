#include <bits/stdc++.h>
using namespace std;
long long int a[1001][1001], sum[1001][1001], dp[41][41][41][41];
int main() {
  long long int i, j, k, l, n, m, q, ni, nj, nk, nl, mask, sign;
  string s;
  cin >> n >> m >> q;
  for (i = 1; i <= n; i++) {
    cin >> s;
    s = " " + s;
    for (j = 1; j <= m; j++) a[i][j] = s[j] - '0';
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
  }
  for (i = n; i >= 1; i--) {
    for (j = m; j >= 1; j--) {
      for (k = i; k <= n; k++) {
        for (l = j; l <= m; l++) {
          if (sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1] ==
              0)
            dp[i][j][k][l]++;
          for (mask = 1; mask < (1 << 4); mask++) {
            if ((__builtin_popcount(mask)) % 2) {
              sign = 1;
              ni = i;
              nj = j;
              nk = k;
              nl = l;
              if (mask & (1 << 0)) ni = i + 1;
              if (mask & (1 << 1)) nj = j + 1;
              if (mask & (1 << 2)) nk = k - 1;
              if (mask & (1 << 3)) nl = l - 1;
              dp[i][j][k][l] += sign * dp[ni][nj][nk][nl];
            } else {
              sign = -1;
              ni = i;
              nj = j;
              nk = k;
              nl = l;
              if (mask & (1 << 0)) ni = i + 1;
              if (mask & (1 << 1)) nj = j + 1;
              if (mask & (1 << 2)) nk = k - 1;
              if (mask & (1 << 3)) nl = l - 1;
              dp[i][j][k][l] += sign * dp[ni][nj][nk][nl];
            }
          }
        }
      }
    }
  }
  while (q--) {
    cin >> i >> j >> k >> l;
    cout << dp[i][j][k][l] << "\n";
  }
  return 0;
}
