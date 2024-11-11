#include <bits/stdc++.h>
using namespace std;
long long sum[1505][1505], dp[1505][1505];
long long minV = -(1LL << 60);
int main() {
  memset(sum, 0, sizeof(sum));
  memset(dp, 0, sizeof(dp));
  int n = 0, m = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%I64d", &sum[i][j]);
      if (j > 0) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  int flag = 0;
  for (int j = 0; j < m; ++j) {
    dp[0][j] = sum[0][j];
  }
  for (int i = 1; i < n; ++i) {
    if (flag == 0) {
      long long curMax = minV;
      dp[i][m - 1] = minV;
      for (int j = m - 1; j > 0; --j) {
        curMax = max(curMax, dp[i - 1][j]);
        dp[i][j - 1] = curMax + sum[i][j - 1];
      }
    } else {
      long long curMax = minV;
      dp[i][0] = minV;
      for (int j = 0; j + 1 < m; ++j) {
        curMax = max(curMax, dp[i - 1][j]);
        dp[i][j + 1] = curMax + sum[i][j + 1];
      }
    }
    flag = 1 - flag;
  }
  long long res = minV;
  for (int j = 0; j < m; ++j) {
    res = max(res, dp[n - 1][j]);
  }
  printf("%I64d", res);
  return 0;
}
