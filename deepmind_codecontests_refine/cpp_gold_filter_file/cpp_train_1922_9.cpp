#include <bits/stdc++.h>
using namespace std;
const long long int N = 5e3 + 15;
const long long int inf = 1e18;
long long int n, m, k;
vector<long long int> a(N);
void solve() {
  cin >> n >> m >> k;
  for (long long int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
  long long int dp[n + 10][k + 10];
  memset(dp, 0, sizeof(dp));
  for (long long int i = m; i <= n; i++) {
    for (long long int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + a[i] - a[i - m]);
    }
  }
  cout << dp[n][k];
}
void debug(long long int tt) {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
