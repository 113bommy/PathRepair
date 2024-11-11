#include <bits/stdc++.h>
using namespace std;
int a[105];
int m1[105][105];
long long int dp[105][105][105];
int main() {
  int n, m, k;
  long long int flag;
  while (~scanf("%d %d %d", &n, &m, &k)) {
    flag = 999999999999;
    for (int i = 0; i < 105; i++) {
      for (int j = 0; j < 105; j++) {
        for (int k = 0; k < 105; k++) dp[i][j][k] = 999999999999;
      }
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) scanf("%d", &m1[i][j]);
    }
    if (a[1] == 0) {
      for (int i = 1; i <= m; i++) dp[1][i][1] = m1[1][i];
    } else
      dp[1][a[1]][1] = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] != 0) {
        for (int j = 1; j <= k; j++) {
          for (int j1 = 1; j1 <= m; j1++) {
            if (dp[i - 1][j1][j] != 999999999999) {
              if (a[i] != j1)
                dp[i][a[i]][j + 1] = min(dp[i][a[i]][j + 1], dp[i - 1][j1][j]);
              else
                dp[i][a[i]][j] = min(dp[i][a[i]][j], dp[i - 1][j1][j]);
            }
          }
        }
      } else {
        for (int i1 = 1; i1 <= m; i1++) {
          for (int j = 1; j <= k; j++) {
            for (int j1 = 1; j1 <= m; j1++) {
              if (dp[i - 1][j1][j] != 999999999999) {
                if (i1 != j1)
                  dp[i][i1][j + 1] =
                      min(dp[i][i1][j + 1], dp[i - 1][j1][j] + m1[i][i1]);
                else
                  dp[i][i1][j] =
                      min(dp[i][i1][j], dp[i - 1][j1][j] + m1[i][i1]);
              }
            }
          }
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      if (dp[n][i][k] < flag) flag = dp[n][i][k];
    }
    if (flag == 999999999)
      printf("-1\n");
    else
      printf("%I64d\n", flag);
  }
  return 0;
}
