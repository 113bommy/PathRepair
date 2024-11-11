#include <bits/stdc++.h>
using namespace std;
const int MAXN = 21, MAX = 1 << MAXN;
int dp[MAX][MAXN];
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  char a1;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a1;
      a[j] = (a[j] << 1) + a1 - '0';
    }
  for (int i = 0; i < m; ++i) dp[a[i]][0] = 1;
  int t = 1 << n;
  for (int d = 1; d <= n; ++d)
    for (int mask = 0; mask < t; ++mask) {
      for (int i = 0; i < n; ++i) dp[mask][d] += dp[mask ^ (1 << i)][d - 1];
      if (d > 1) dp[mask][d] -= dp[mask][d - 2] * (n - d + 2);
      dp[mask][d] /= d;
    }
  int ans = n * m;
  for (int mask = 0; mask < t; ++mask) {
    int res = 0;
    for (int i = 0; i <= n; ++i) res += min(i, n - i) * dp[mask][i];
    ans = min(ans, res);
  }
  cout << ans;
  return 0;
}
