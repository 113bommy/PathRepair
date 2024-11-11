#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, k;
int dp[1 << N][2][2];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < (1 << n); ++i)
    dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1e9;
  for (int i = 1; i <= k; ++i) {
    int a;
    scanf("%d", &a);
    dp[(1 << n) - 1 + a][0][1] = 1;
  }
  for (int i = (1 << n) - 1; i >= (1 << (n - 1)); --i) {
    int tot = dp[i << 1][0][1] + dp[i << 1 | 1][0][1];
    if (tot == 0) dp[i][0][0] = 0;
    if (tot == 1) dp[i][0][1] = dp[i][1][0] = 1;
    if (tot == 2) dp[i][1][1] = 1;
  }
  for (int i = (1 << (n - 1)) - 1; i; --i) {
    for (int x1 = 0; x1 <= 1; ++x1)
      for (int x2 = 0; x2 <= 1; ++x2)
        for (int y1 = 0; y1 <= 1; ++y1)
          for (int y2 = 0; y2 <= 1; ++y2) {
            if (y1 | y2)
              dp[i][x1 | x2 | (y1 + y2 == 2)][1] =
                  max(dp[i][x1 | x2 | (y1 + y2 == 2)][1],
                      dp[i << 1][x1][y1] + dp[i << 1 | 1][x2][y2] + 1 +
                          (x1 | x2 | (y1 + y2 == 2)) * 2);
            if ((y1 & y2) == 0)
              dp[i][x1 | x2 | (y1 + y2 >= 1)][0] =
                  max(dp[i][x1 | x2 | (y1 + y2 >= 1)][0],
                      dp[i << 1][x1][y1] + dp[i << 1 | 1][x2][y2] +
                          (x1 | x2 | (y1 + y2 >= 1)) * 2);
          }
  }
  printf("%lld\n",
         max(max(0, dp[1][0][1] + 1), max(dp[1][1][1] + 1, dp[1][1][0] + 1)));
}
