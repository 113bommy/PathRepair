#include <bits/stdc++.h>
using namespace std;
const int N = 5019;
int a[N], dp[N][N][2];
int main() {
  int n;
  int T = 1;
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0][0] = dp[2][0][0] = dp[1][1][1] = 0;
    dp[2][1][0] = max(0, a[2] - a[1] + 1);
    dp[2][1][1] = max(0, a[1] - a[2] + 1);
    for (int i = 3; i <= n; i++)
      for (int j = 0; j <= i; j++) {
        dp[i][j + 1][1] =
            min(dp[i][j + 1][1],
                dp[i - 2][j][1] +
                    max(0, max(a[i - 1] - a[i - 2] + 1, a[i - 1] - a[i] + 1)));
        dp[i][j + 1][1] =
            min(dp[i][j + 1][1], dp[i - 2][j][0] + max(0, a[i - 1] - a[i] + 1));
        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
        dp[i][j][0] =
            min(dp[i][j][0], dp[i - 1][j][1] + max(0, a[i - 1] - a[i] + 1));
      }
    for (int i = 1; i <= (n + 1) / 2; i++)
      printf("%d%c", min(dp[n][i][1], dp[n][i][0]), " \n"[i == (n + 1) / 2]);
  }
  return 0;
}
