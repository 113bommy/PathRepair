#include <bits/stdc++.h>
using namespace std;
int i, i0, n, m, ans, a[50005][6];
long long dp[6][50005];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int i0 = 1; i0 <= m; i0++) scanf("%d", &a[i][i0]);
  for (int i = 1; i <= m; i++) {
    for (int i0 = 1; i0 <= n; i0++) {
      dp[i][i0] = max(dp[i][i0 - 1], dp[i - 1][i0]) + a[i0][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld%c", dp[m][i], i == n ? '\n' : ' ');
  }
  return 0;
}
