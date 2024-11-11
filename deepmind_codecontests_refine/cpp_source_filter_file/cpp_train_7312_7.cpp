#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
vector<vector<long long>> heights;
int n, m;
long long mx = 1e16;
long long solve() {
  long long ans = LLONG_MAX;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      long long need = heights[i][j] - i - j;
      if (need > heights[0][0]) continue;
      long long a00 = need;
      vector<vector<long long>> dp(n, vector<long long>(m, mx));
      dp[0][0] = heights[0][0] - need;
      for (int k = 0; k < n; k++)
        for (int l = 0; l < m; l++) {
          if (k == 0 && l == 0) continue;
          long long need = a00 + k + l;
          if (heights[k][l] < need) continue;
          need = heights[k][l] - need;
          if (k > 0) dp[k][l] = min(dp[k][l], dp[k - 1][l] + need);
          if (l > 0) dp[k][l] = min(dp[k][l], dp[k][l - 1] + need);
        }
      ans = min(ans, dp[n - 1][m - 1]);
    }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    heights.assign(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%lld", &heights[i][j]);
    long long res = solve();
    printf("%lld\n", res);
  }
  return 0;
}
