#include <bits/stdc++.h>
using namespace std;
long long dp[2][505][505];
long long a[505];
int main() {
  int n, m, b, md;
  cin >> n >> m >> b >> md;
  dp[0][0][0] = 1;
  for (int i = 0; i < (int)(n); ++i) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int ii = i & 1;
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= b; k++) {
        dp[ii][j][k] = dp[ii ^ 1][j][k];
        if (j > 0 && k >= a[i - 1]) {
          dp[ii][j][k] += dp[ii][j - 1][k - a[i - 1]];
        }
        while (dp[ii][j][k] >= md) dp[ii][j][k] -= md;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= b; i++) {
    ans += dp[n & 1][m][i];
    while (ans >= md) ans -= md;
  }
  cout << ans << endl;
}
