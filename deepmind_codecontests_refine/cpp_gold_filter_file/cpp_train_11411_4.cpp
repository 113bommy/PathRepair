#include <bits/stdc++.h>
using namespace std;
int dp[12][105][105];
int main() {
  int n, q, c, x, y, s, x1, y1, t;
  memset(dp, 0, sizeof(dp));
  scanf("%d%d%d", &n, &q, &c);
  while (n--) {
    scanf("%d%d%d", &x, &y, &s);
    dp[s][x][y]++;
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int k = 0; k <= c; k++) {
        dp[k][i][j] += dp[k][i - 1][j] + dp[k][i][j - 1] - dp[k][i - 1][j - 1];
      }
    }
  }
  while (q--) {
    int sum[12], cnt = 0;
    scanf("%d%d%d%d%d", &t, &x, &y, &x1, &y1);
    for (int i = 0; i <= c; i++) {
      sum[i] = dp[i][x1][y1] + dp[i][x - 1][y - 1] - dp[i][x1][y - 1] -
               dp[i][x - 1][y1];
      cnt += ((i + t) % (c + 1)) * sum[i];
    }
    printf("%d\n", cnt);
  }
  return 0;
}
