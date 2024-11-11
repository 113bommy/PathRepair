#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, a[100005], dp[100005];
  while (scanf("%d", &n) == 1) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      dp[a[i]] = 1;
      for (int j = 2; j * a[i] < a[n - 1]; j++)
        dp[a[i]] = max(dp[j * a[i]] + 1, dp[a[i]]);
      res = max(res, dp[a[i]]);
    }
    printf("%d\n", res);
  }
  return 0;
}
