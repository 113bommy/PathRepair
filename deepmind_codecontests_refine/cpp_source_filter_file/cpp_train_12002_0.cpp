#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, K;
  cin >> n >> m >> K;
  long long **a = new long long *[n];
  for (long long i = 0; i < n; i++) {
    a[i] = new long long[m];
    for (long long j = 0; j < m; j++) cin >> a[i][j];
  }
  long long dp[n + 1][m + 1][m / 2 + 1][K + 1];
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= m; j++) {
      for (long long k = 0; k <= m / 2; k++)
        for (long long l = 0; l <= K; l++) dp[i][j][k][l] = -1;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j <= K; j++) dp[i][0][0][j] = dp[i - 1][m][m / 2][j];
    for (long long j = 1; j <= m; j++) {
      for (long long k = 0; k <= K; k++)
        dp[i][j][0][k] = dp[i - 1][m][m / 2][k];
      for (long long k = 1; k <= m / 2; k++) {
        for (long long l = 1; l <= K; l++) {
          dp[i][j][k][l] = max(dp[i][j - 1][k][l], dp[i][j][k - 1][1]);
          if (a[i - 1][j - 1] % K == 0 &&
              (dp[i][j - 1][k - 1][l] != -1 || l == K))
            dp[i][j][k][l] =
                max(dp[i][j][k][l],
                    max(0ll, dp[i][j - 1][k - 1][l]) + a[i - 1][j - 1]);
          else if (a[i - 1][j - 1] % K != 0) {
            long long pos = (l - a[i - 1][j - 1]) % K;
            if (pos <= 0) pos += K;
            if (dp[i][j - 1][k - 1][pos] == -1 and pos != K) continue;
            dp[i][j][k][l] =
                max(dp[i][j][k][l],
                    max(0ll, dp[i][j - 1][k - 1][pos]) + a[i - 1][j - 1]);
          }
        }
      }
    }
  }
  if (dp[n][m][m / 2][K] % K != 0)
    cout << 0;
  else
    cout << max(0ll, dp[n][m][m / 2][K]);
}
