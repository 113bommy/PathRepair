#include <bits/stdc++.h>
using namespace std;
inline int fastmax(int a, int b) { return (((a - b) >> 22) & (a ^ b)) ^ a; }
int n, T;
pair<int, int> task[1013];
int dp[1013][2013];
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d%d", &task[i].first, &task[i].second);
  sort(task + 1, task + n + 1);
  reverse(task + 1, task + n + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n + 1; j++) dp[i][j] = -1e6;
  dp[0][1] = 0;
  for (int l = 1; l <= T; l++) {
    for (int j = 0; j <= n; j++)
      for (int k = n + 1; k > 0; k--) {
        dp[j][2 * k] = dp[j][k];
        dp[j][k] = -1e6;
      }
    for (int k = n + 1; k >= 0; k--) {
      for (int j = 1; j <= n; j++) {
        dp[j][k] = fastmax(dp[j][k], dp[j - 1][k]);
        if (k <= n && task[j].first + l <= T)
          dp[j][k] = fastmax(dp[j][k], dp[j - 1][k + 1] + task[j].second);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = fastmax(ans, task[i].second);
  ans = fastmax(ans, dp[n][0]);
  printf("%d\n", ans);
  return 0;
}
