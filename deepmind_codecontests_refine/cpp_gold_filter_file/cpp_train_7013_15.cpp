#include <bits/stdc++.h>
using namespace std;
const int N = 52;
long long n, a[N], p, dp[N][N][N], c[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &p);
  dp[0][0][0] = 1;
  c[0][0] = 1;
  for (int i = 0; i <= 50; i++)
    for (int j = 0; j <= 50; j++) {
      if (i) c[i][j] += c[i - 1][j];
      if (i && j) c[i][j] += c[i - 1][j - 1];
    }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= 50; ++k) {
        if (k - a[i] >= 0)
          if (j - 1 >= 0) dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
        dp[i][j][k] += dp[i - 1][j][k];
      }
    }
  }
  double ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 1; j <= p; ++j) dp[n][i][j] += dp[n][i][j - 1];
  for (int i = 1; i <= n; ++i) ans += dp[n][i][p] * 1.0 / c[n][i];
  cout.precision(10);
  cout << fixed << ans << '\n';
}
