#include <bits/stdc++.h>
using namespace std;
int dp[30010][600], cnt[30010];
int mark[30010][600];
int main() {
  int n, d;
  while (scanf("%d%d", &n, &d) != EOF) {
    int tmp;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      cnt[tmp]++;
    }
    memset(dp, 0, sizeof(dp));
    memset(mark, 0, sizeof(mark));
    dp[d][250] = cnt[d];
    mark[d][250] = 1;
    for (int i = d; i <= 30000; i++) {
      for (int j = 0; j <= 500; j++)
        if (mark[i][j] == 1) {
          int k = j - 250 + d;
          if (k < 0) continue;
          if (k - 1 > 0 && i + k - 1 <= 30000) {
            dp[i + k - 1][k - 1 - d + 250] =
                max(dp[i + k - 1][k - 1 - d + 250], dp[i][j] + cnt[i + k - 1]);
            mark[i + k - 1][k - 1 - d + 250] = 1;
          }
          if (k > 0 && i + k <= 30000) {
            dp[i + k][k - d + 250] =
                max(dp[i + k][k - d + 250], dp[i][j] + cnt[i + k]);
            mark[i + k][k - d + 250] = 1;
          }
          if (k + 1 > 0 && i + k + 1 <= 30000) {
            dp[i + k + 1][k + 1 - d + 250] =
                max(dp[i + k + 1][k + 1 - d + 250], dp[i][j] + cnt[i + k + 1]);
            mark[i + k + 1][k + 1 - d + 250] = 1;
          }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 30000; i++)
      for (int j = 0; j <= 500; j++) ans = max(ans, dp[i][j]);
    printf("%d\n", ans);
  }
  return 0;
}
