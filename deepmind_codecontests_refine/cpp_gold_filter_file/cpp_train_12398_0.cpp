#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const long long inf = 1e9;
long long dp[2511 << 1][2511][2];
long long h[2511 << 1];
int n;
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%I64d", &h[i]);
  h[0] = h[n + 1] = -inf;
  k = n / 2 + n % 2;
  for (i = 0; i <= n; ++i) {
    for (j = 0; j <= k; ++j) {
      dp[i][j][0] = dp[i][j][1] = inf;
    }
  }
  for (i = 0; i <= n; ++i) dp[i][0][0] = 0;
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= k && j <= i; ++j) {
      dp[i][j][0] = min(dp[i][j][0], min(dp[i - 1][j][1], dp[i - 1][j][0]));
      if (i > 1) {
        dp[i][j][1] =
            min(dp[i - 2][j - 1][0] + h[i - 1] - min(h[i - 1], h[i] - 1) +
                    h[i + 1] - min(h[i + 1], h[i] - 1),
                dp[i - 2][j - 1][1] + h[i + 1] - min(h[i + 1], h[i] - 1) +
                    min(h[i - 2] - 1, h[i - 1]) -
                    min(h[i] - 1, min(h[i - 2] - 1, h[i - 1])));
      } else {
        dp[i][j][1] =
            min(dp[i - 1][j - 1][0] + h[2] - min(h[2], h[1] - 1), dp[i][j][1]);
      }
    }
  }
  for (i = 1; i <= k; ++i) {
    printf("%I64d ", min(dp[n][i][0], dp[n][i][1]));
  }
  return 0;
}
