#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 7;
const int INF = 1e9 + 7;
int n;
int a[maxn];
int dp[2][maxn][3];
int ans[maxn];
int main() {
  scanf("%d", &n);
  a[n + 1] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 3; j++) dp[0][i][j] = dp[1][i][j] = INF;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans[i] = INF;
  int no = 1;
  dp[0][0][2] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      dp[no][j][1] = dp[no ^ 1][j][0];
      dp[no][j][2] = min(dp[no ^ 1][j][1], dp[no ^ 1][j][2]);
      if (j >= 1) {
        dp[no][j][0] = INF;
        if (i > 1)
          dp[no][j][0] =
              min(dp[no][j][0],
                  dp[no ^ 1][j - 1][1] +
                      max(min(a[i - 1], a[i - 2] - 1) - (a[i] - 1), 0) +
                      max(0, a[i + 1] - (a[i] - 1)));
        dp[no][j][0] = min(dp[no][j][0], dp[no ^ 1][j - 1][2] +
                                             max(0, a[i - 1] - (a[i] - 1)) +
                                             max(0, a[i + 1] - (a[i] - 1)));
      }
      ans[j] = min(ans[j], dp[no][j][0]);
    }
    no ^= 1;
  }
  for (int i = 1; i <= (n - 1) / 2 + 1; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
