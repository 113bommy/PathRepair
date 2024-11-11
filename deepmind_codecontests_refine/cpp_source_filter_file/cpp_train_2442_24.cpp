#include <bits/stdc++.h>
using namespace std;
int dp[6][1005][1005];
int ans[1005];
int a[1005];
int n, k;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[j]);
      for (int s = 1; s < j; s++) {
        dp[i][a[s]][a[j]] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[0][i][j] = dp[1][i][j];
      for (int s = 2; s <= k; s++) {
        dp[0][i][j] = dp[0][i][j] & dp[s][i][j];
      }
    }
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    ans[i] = 1;
    int tmp = a[i];
    for (int j = 1; j < i; j++) {
      if (dp[0][a[j]][tmp]) {
        ans[i] = max(ans[i], ans[j] + 1);
      }
      mx = max(mx, ans[i]);
    }
  }
  printf("%d\n", mx);
  return 0;
}
