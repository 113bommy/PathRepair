#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
int c[111][111], n, m, k, nw;
long long dp[55][55][55][111], ans;
int main() {
  c[0][0] = 1;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= i; j++) {
      if (c[i][j] > 100) {
        c[i][j] = 101;
      }
      c[i + 1][j] += c[i][j];
      c[i + 1][j + 1] += c[i][j];
    }
  }
  cin >> n >> m >> k;
  n /= 2;
  nw = min(n, m);
  for (int i = 1; i <= n; i++) {
    dp[i][i][1][1] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int kk = 1; kk <= nw; kk++) {
        for (int l = 1; l <= k; l++) {
          if (dp[i][j][kk][l] == 0) {
            continue;
          }
          dp[i][j][kk][l] %= md;
          ans += (m - kk) * dp[i][j][kk][l] % md;
          ans %= md;
          for (int nn = n - i; nn >= 1; nn--) {
            if (l * c[j + nn - 1][j - 1] <= k) {
              dp[i + nn][nn][kk + 1][l * c[j + nn - 1][j - 1]] +=
                  dp[i][j][kk][l];
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
