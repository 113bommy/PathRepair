#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
char str[30][30];
int change[30][30], cost[30][30];
int dp[1 << 21], best[30][30];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> str[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> cost[i][j];
    memset(change, 0, sizeof(change));
    for (int k = 0; k < n; k++)
      for (int i = 0; i < m; i++) {
        best[k][i] = INF;
        int sum = 0;
        int maxx = 0;
        for (int j = 0; j < n; j++)
          if (str[k][i] == str[j][i]) {
            sum += cost[j][i];
            maxx = std::max(maxx, cost[j][i]);
            change[k][i] |= 1 << j;
          }
        best[k][i] = std::min(best[k][i], sum - maxx);
      }
    std::fill(dp + 1, dp + 25, INF);
    dp[0] = 0;
    for (int st = 0; st < (1 << n); st++)
      for (int i = 0; i < n; i++)
        if ((st & (1 << i)) == 0) {
          for (int j = 0; j < m; j++) {
            dp[st | change[i][j]] =
                std::min(dp[st | change[i][j]], dp[st] + best[i][j]);
            dp[st | (1 << i)] =
                std::min(dp[st | (1 << i)], dp[st] + cost[i][j]);
          }
          break;
        }
    cout << dp[(1 << n) - 1] << endl;
  }
  return 0;
}
