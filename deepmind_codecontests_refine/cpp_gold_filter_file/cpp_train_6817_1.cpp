#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  int r, s, p;
  cin >> r >> s >> p;
  double dp[r + 1][s + 1][p + 1];
  memset(dp, 0, sizeof(dp));
  dp[r][s][p] = 1;
  for (int i = r; i >= 0; i--) {
    for (int j = s; j >= 0; j--) {
      for (int k = p; k >= 0; k--) {
        double x = i * j + j * k + i * k;
        if (!x) continue;
        if (i) dp[i - 1][j][k] += (dp[i][j][k] * i * k) / x;
        if (j) dp[i][j - 1][k] += (dp[i][j][k] * i * j) / x;
        if (k) dp[i][j][k - 1] += (dp[i][j][k] * j * k) / x;
      }
    }
  }
  double ans[3] = {0};
  for (int i = 1; i <= r; i++) ans[0] += dp[i][0][0];
  for (int i = 1; i <= s; i++) ans[1] += dp[0][i][0];
  for (int i = 1; i <= p; i++) ans[2] += dp[0][0][i];
  cout << setprecision(10) << fixed << ans[0] << " " << ans[1] << " " << ans[2];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
}
