#include <bits/stdc++.h>
using namespace std;
int a[100005];
int dp[2][505][505];
int n, m, b, md;
void solve() {
  dp[0][0][0] = 1;
  int it, i, j, k;
  for (it = 1; it <= n; it++) {
    i = it & 1;
    for (j = 0; j <= m; j++) {
      for (k = 0; k <= b; k++) {
        dp[i][j][k] = dp[i ^ 1][j][k];
        if ((k >= a[it]) && (j > 0)) dp[i][j][k] += dp[i][j - 1][k - a[it]];
        while (dp[i][j][k] > md) dp[i][j][k] -= md;
      }
    }
  }
  return;
}
int main() {
  int i, j, k, t;
  cin >> n >> m >> b >> md;
  for (i = 1; i <= n; i++) cin >> a[i];
  solve();
  int ans = 0;
  for (i = 0; i <= b; i++) {
    ans = (ans + dp[n & 1][m][i]) % md;
  }
  cout << ans << endl;
  return 0;
}
