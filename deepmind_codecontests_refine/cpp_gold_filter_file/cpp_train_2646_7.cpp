#include <bits/stdc++.h>
using namespace std;
int n, m, x, ans = 0;
int MUL(int u, int v) { return (int)((1LL * u * v) % (int)(1e9 + 7)); }
int main() {
  scanf("%d%d%d", &n, &m, &x);
  if (n > m) {
    cout << 0 << endl;
    return 0;
  }
  int dp[m + 10][n + 10][n + 10][2];
  dp[m + 1][n][0][1] = 1;
  for (int i = m; i >= 1; i--) {
    for (int k = 0; k <= n; k++) {
      for (int ng = 0; ng <= n; ng++) {
        for (int pre = 0; pre <= 1; pre++) {
          int ans = 0;
          ans = (ans + dp[i + 1][k][ng + 1][pre || (i == x)]) % (int)(1e9 + 7);
          ans = (ans + dp[i + 1][k][ng][pre]) % (int)(1e9 + 7);
          ans = (ans + dp[i + 1][k + 1][ng - 1][pre]) % (int)(1e9 + 7);
          ans = (ans + dp[i + 1][k + 1][ng][pre || (i == x)]) % (int)(1e9 + 7);
          dp[i][k][ng][pre] = ans;
        }
      }
    }
  }
  int ans = dp[1][0][0][0];
  for (int i = 1; i <= n; i++) ans = MUL(ans, i);
  cout << ans << endl;
}
