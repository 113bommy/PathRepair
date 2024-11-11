#include <bits/stdc++.h>
using namespace std;
const int max_n = 300033, max_m = 41, inf = 1011111111;
int n, a[max_n], dp[2][max_m];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] /= 100;
  }
  int q1 = 0, q2 = 1;
  for (int j = 0; j < max_m; ++j) {
    dp[q1][j] = inf;
  }
  dp[q1][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < max_m; ++j) {
      dp[q2][j] = inf;
    }
    for (int j = 0; j < max_m; ++j) {
      if (dp[q1][j] == inf) {
        continue;
      }
      if (j + a[i] / 10 < max_m) {
        dp[q2][j + a[i] / 10] = min(dp[q2][j + a[i] / 10], dp[q1][j] + a[i]);
      }
      int y = min(j, a[i]);
      dp[q2][j - y] = min(dp[q2][j - y], dp[q1][j] + a[i] - y);
    }
    swap(q1, q2);
  }
  int ans = inf;
  for (int i = 0; i < max_m; ++i) {
    ans = min(ans, dp[q1][i]);
  }
  printf("%d\n", ans * 100);
  return 0;
}
