#include <bits/stdc++.h>
using namespace std;
long long a[5005] = {0}, sum[5005] = {0};
long long dp[5005][4] = {0}, pre[5005][4] = {0};
int main() {
  int n, ans[5];
  scanf("%d", &n);
  sum[0] = 0;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  long long mx = sum[n];
  ans[3] = 0;
  pre[1][0] = pre[1][1] = pre[1][2] = pre[1][3] = 0;
  mx = -sum[n];
  pre[0][0] = pre[0][1] = pre[0][2] = pre[0][3] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + a[i - 1];
    pre[i][0] = 0;
    if (dp[i - 1][0] - a[i] > dp[i - 1][1] - a[i]) {
      pre[i][1] = i - 1;
      dp[i][1] = dp[i - 1][0] - a[i];
    } else {
      pre[i][1] = pre[i - 1][1];
      dp[i][1] = dp[i - 1][1] - a[i];
    }
    if (dp[i][1] < dp[i][0]) {
      dp[i][1] = dp[i][0];
      pre[i][1] = i;
    }
    if (dp[i - 1][1] + a[i] > dp[i - 1][2] + a[i]) {
      dp[i][2] = dp[i - 1][1] + a[i];
      pre[i][2] = i - 1;
    } else {
      dp[i][2] = dp[i - 1][2] + a[i];
      pre[i][2] = pre[i - 1][2];
    }
    if (dp[i][2] < dp[i][1]) {
      dp[i][2] = dp[i][1];
      pre[i][2] = i;
    }
    dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - (sum[n] - sum[i - 1]));
    pre[i][3] = i - 1;
    if (dp[i][3] < dp[i][2] - sum[n] + sum[i]) {
      dp[i][3] = dp[i][2] - sum[n] + sum[i];
      pre[i][3] = i;
    }
    if (dp[i][3] > mx) {
      mx = dp[i][3];
      ans[3] = i;
    }
  }
  int te = 3;
  while (te--) {
    ans[te] = pre[ans[te + 1]][te];
  }
  printf("%d %d %d\n", ans[1], ans[2], ans[3]);
}
