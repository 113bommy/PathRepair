#include <bits/stdc++.h>
long long a[3010];
long long dp[3010], dp2[3010];
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
int main(void) {
  int n, k, i, j;
  long long ans;
  long long temp;
  while (scanf("%d %d", &n, &k) != EOF) {
    ans = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) {
      dp[i] = 0;
    }
    for (j = 1; j <= k; j++) {
      temp = 0;
      for (i = 1; i <= n; i++) {
        dp2[i] = -a[i] + temp;
        temp = max(temp, dp[i]);
      }
      temp = -a[1];
      for (i = 1; i <= n; i++) {
        dp[i] = a[i] + temp;
        temp = max(temp, dp2[i]);
      }
    }
    for (i = 1; i <= n; i++) {
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
