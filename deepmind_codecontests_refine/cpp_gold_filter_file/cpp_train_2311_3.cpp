#include <bits/stdc++.h>
using namespace std;
int n = 10;
int g[15][15], a[110];
double dp[110];
int main() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) scanf("%d", &g[i][j]);
  }
  int cnt = 0;
  for (int i = n; i >= 1; --i) {
    if (i & 1) {
      for (int j = n; j >= 1; --j) {
        ++cnt;
        if (!g[i][j]) continue;
        int num = (g[i][j] - 1) * 10 + (j - 1);
        if (g[i][j] & 1)
          num += j;
        else
          num += 10 - j + 1;
        a[cnt] = cnt + num;
      }
    } else {
      for (int j = 1; j <= n; ++j) {
        ++cnt;
        if (!g[i][j]) continue;
        int num = (g[i][j] - 1) * 10 + (10 - j);
        if (g[i][j] & 1)
          num += 10 - j + 1;
        else
          num += j;
        a[cnt] = cnt + num;
      }
    }
  }
  dp[100] = 0;
  dp[101] = dp[102] = dp[103] = dp[104] = dp[105] = 6.0;
  for (int i = 99; i >= 1; --i) {
    dp[i] = (dp[i + 1] + dp[i + 2] + dp[i + 3] + dp[i + 4] + dp[i + 5] +
             dp[i + 6]) /
                6.0 +
            1.0;
    int j = a[i];
    if (j > 0 && j < 100)
      dp[i] = (dp[i] < (dp[j + 1] + dp[j + 2] + dp[j + 3] + dp[j + 4] +
                        dp[j + 5] + dp[j + 6]) /
                               6.0 +
                           1.0
                   ? dp[i]
                   : (dp[j + 1] + dp[j + 2] + dp[j + 3] + dp[j + 4] +
                      dp[j + 5] + dp[j + 6]) /
                             6.0 +
                         1.0);
    else if (j == 100)
      dp[i] = 0;
  }
  printf("%.10lf\n", dp[1]);
  return 0;
}
