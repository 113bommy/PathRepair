#include <bits/stdc++.h>
using namespace std;
long long dp[2][2000], a[2000][2000], o[2000][2000];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int j = 1; j <= m; j++) o[i][j] = o[i][j - 1] + a[i][j - 1];
  }
  dp[1][0] = dp[1][1] = dp[0][m] = -1000000;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      long long x = 1;
      for (int j = (i % 2) + 1; j <= m; j++) {
        dp[i % 2][j] = dp[1 - i % 2][x] + o[i][j];
        if (dp[1 - i % 2][j] > dp[1 - i % 2][x]) x = j;
      }
    } else {
      long long x = m;
      for (int j = m - 1; j; j--) {
        dp[i % 2][j] = dp[1 - i % 2][x] + o[i][j];
        if (dp[1 - i % 2][j] > dp[1 - i % 2][x]) x = j;
      }
    }
  }
  long long ans = -1LL * 2000 * 2000 * 2000 * 2000;
  for (int i = 1; i <= m; i++) ans = (ans < dp[n % 2][i] ? dp[n % 2][i] : ans);
  cout << ans << endl;
}
