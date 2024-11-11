#include <bits/stdc++.h>
using namespace std;
int n;
int t[2000 + 5];
long long c[2000 + 5];
long long dp[2000 + 5][2000 + 5], ans;
void chmin(long long &x, long long y) { x = min(x, y); }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i] >> c[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 2000 + n; j++) dp[i][j] = 1e18;
  dp[0][2000] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 2000 + n; j++)
      if (dp[i][j] != 1e18) {
        chmin(dp[i + 1][min(2000 + n, j + t[i + 1])], dp[i][j] + c[i + 1]);
        if (j) chmin(dp[i + 1][j - 1], dp[i][j]);
      }
  ans = 1e18;
  for (int i = 2000; i <= 2000 + n; i++) ans = min(ans, dp[n][i]);
  cout << ans << '\n';
  return 0;
}
