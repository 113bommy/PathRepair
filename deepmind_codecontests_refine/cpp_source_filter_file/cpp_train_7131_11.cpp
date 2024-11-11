#include <bits/stdc++.h>
using namespace std;
int dp[2][160][12000];
int a[200];
int main() {
  int i, j, k, n, l, s;
  scanf("%d %d %d", &n, &k, &s);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (s > 12000) {
    sort(a + 1, a + n + 1);
    int sum = 0;
    for (i = 1; i <= k; i++) sum += a[i];
    printf("%d\n", sum);
    return 0;
  }
  int m = (n * n) / 2;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= m; j++) dp[0][i][j] = dp[1][i][j] = 1000000000;
  dp[0][0][0] = 0;
  int c = 1;
  for (int i1 = 1; i1 <= n; i1++) {
    for (i = 0; i <= n; i++)
      for (j = 0; j < m; j++) dp[c][i][j] = 1000000000;
    dp[c][0][0] = 0;
    for (i = 1; i <= i1; i++) {
      dp[c][i][0] = 1000000000;
      for (j = 1; j <= m; j++) {
        dp[c][i][j] = min(dp[c][i][j - 1], dp[!c][i][j]);
        if (i1 <= j)
          dp[c][i][j] = min(dp[c][i][j], dp[!c][i - 1][j - i1] + a[i1]);
      }
    }
    c = !c;
  }
  int ans = 1000000000;
  for (i = 0; i <= m; i++) {
    int y = i - ((k * (k + 1)) / 2);
    if (y <= s) ans = min(ans, dp[!c][k][i]);
  }
  cout << ans << endl;
  return 0;
}
