#include <bits/stdc++.h>
using namespace std;
const long long inf = 0xcfcfcfcfcfcfcfcf;
long long dp[2][200005];
long long a[310], b[310], t[310];
int que[200005];
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> t[i];
  memset(dp, inf, sizeof(dp));
  memset(que, 0, sizeof(que));
  for (int i = 1; i <= n; i++) dp[0][i] = 0;
  int k = 1;
  for (int i = 1; i <= m; i++) {
    int l = 1, r = 0;
    int h = 1;
    for (int j = 1; j <= n; j++) {
      for (; h <= min(1ll * n, j + d * (t[i] - t[i - 1])); h++) {
        while (l <= r && dp[k ^ 1][que[r]] <= dp[k ^ 1][h]) r--;
        que[++r] = h;
      }
      while (l <= r && que[l] < min(1ll * n, j + d * (t[i] - t[i - 1]))) l++;
      dp[k][j] = dp[k ^ 1][que[l]] - abs(a[i] - j) + b[i];
    }
    k = k ^ 1;
  }
  long long ans = inf;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[k ^ 1][i]);
  cout << ans << endl;
}
