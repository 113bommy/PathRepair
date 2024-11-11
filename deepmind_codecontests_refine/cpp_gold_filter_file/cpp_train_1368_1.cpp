#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e6 + 7;
int dp[maxx][3][3], num[maxx];
int main() {
  ios::sync_with_stdio(0);
  int n, m, cnt = 0;
  cin >> n >> m;
  for (int i = 1, u; i <= n; i++) {
    cin >> u;
    num[u]++;
  }
  memset(dp, -0x3f, sizeof dp);
  dp[0][0][0] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++)
          if (j + k + l <= num[i])
            dp[i][j][k] = max(dp[i][j][k],
                              dp[i - 1][l][j] + l + (num[i] - k - j - l) / 3);
  cout << dp[m][0][0] << endl;
}
