#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010][10][2];
char s[1010], t[1010];
int main() {
  int n, m, w;
  cin >> n >> m >> w;
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = 0; i <= n; i++)
    for (int k = 0; k <= w; k++) dp[i][0][k][0] = dp[i][0][k][1] = -1e9;
  for (int i = 0; i <= m; i++)
    for (int k = 0; k <= w; k++) dp[0][i][k][0] = dp[0][i][k][1] = -1e9;
  for (int i = 0; i <= n; i++) dp[i][0][0][0] = 0;
  for (int i = 0; i <= m; i++) dp[0][i][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= w; k++) {
        if (s[i] == t[j]) {
          dp[i][j][k][1] = dp[i - 1][j - 1][k][1] + 1;
          if (k > 0)
            dp[i][j][k][1] =
                max(dp[i][j][k][1], dp[i - 1][j - 1][k - 1][0] + 1);
        } else
          dp[i][j][k][1] = -1e9;
        dp[i][j][k][0] = max(dp[i - 1][j][k][0], dp[i - 1][j][k][1]);
        dp[i][j][k][0] =
            max(dp[i][j][k][0], max(dp[i][j - 1][k][0], dp[i][j - 1][k][1]));
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= w; k++) {
        ans = max(ans, dp[i][j][k][0]);
        ans = max(ans, dp[i][j][k][1]);
      }
    }
  }
  cout << ans << endl;
}
