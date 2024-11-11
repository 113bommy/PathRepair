#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[100005];
int dp[100005];
int main() {
  int t, n, k, i, j;
  scanf("%d", &t);
  while (t--) {
    int ans = -1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      dp[i] = 1;
      for (j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          if (a[i] > a[i / j]) {
            dp[i] = max(dp[i / j] + 1, dp[i]);
          }
          if (a[i] > a[j]) {
            dp[i] = max(dp[j] + 1, dp[i]);
          }
        }
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
