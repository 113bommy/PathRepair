#include <bits/stdc++.h>
using namespace std;
int dp[2][300005], x[300005], y[300005];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
  for (int i = 1; i <= n; i++) {
    if (!(~dp[0][i - 1])) {
      dp[0][i] = -1;
      dp[1][i] = -1;
      continue;
    }
    if (x[i] > y[i]) {
      long long h = (long long)k * ((long long)y[i] + 1LL);
      if (x[i] + dp[0][i - 1] > h) {
        dp[0][i] = -1;
        dp[1][i] = -1;
        continue;
      }
      dp[1][i] = 0;
      h = (long long)k * (long long)y[i];
      if (x[i] + dp[0][i - 1] <= h) {
        dp[0][i] = 0;
        continue;
      } else
        dp[0][i] = x[i] + dp[0][i - 1] - k * y[i];
    }
    if (y[i] > x[i]) {
      long long h = (long long)k * ((long long)x[i] + 1LL);
      if (y[i] + dp[1][i - 1] > h) {
        dp[0][i] = -1;
        dp[1][i] = -1;
        continue;
      }
      dp[0][i] = 0;
      h = (long long)k * (long long)x[i];
      if (y[i] + dp[1][i - 1] <= h) {
        dp[1][i] = 0;
        continue;
      } else
        dp[1][i] = y[i] + dp[1][i - 1] - k * x[i];
    }
    if (x[i] == y[i]) {
      if (x[i] == 1) {
        if (max(dp[0][i - 1], dp[1][i - 1]) == k) {
          dp[(dp[0][i - 1] > dp[1][i - 1] ? 1 : 0)][i] = 0;
          dp[(dp[0][i - 1] > dp[1][i - 1] ? 0 : 1)][i] = 1;
        } else
          continue;
      } else {
        if (k == 1 && max(dp[0][i - 1], dp[1][i - 1]) == k) {
          dp[(dp[0][i - 1] > dp[1][i - 1] ? 1 : 0)][i] = 0;
          dp[(dp[0][i - 1] > dp[1][i - 1] ? 0 : 1)][i] = 1;
        } else
          continue;
      }
    }
  }
  if (~dp[0][n])
    printf("YES");
  else
    cout << printf("NO");
  return 0;
}
