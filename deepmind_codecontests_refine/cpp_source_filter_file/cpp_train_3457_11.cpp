#include <bits/stdc++.h>
using namespace std;
vector<long long int> a((long long int)(5e3 + 5)), b((long long int)(5e3 + 5)),
    c((long long int)(5e3 + 5)),
    mx((long long int)(5e3 + 5)), p[(long long int)(5e3 + 5)];
vector<vector<long long int>> dp((long long int)(5e3 + 5),
                                 vector<long long int>((long long int)(5e3 + 5),
                                                       -1));
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int sum = k;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    mx[i] = i;
  }
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    mx[y] = max(mx[y], x);
  }
  for (long long int i = 1; i <= n; i++) p[mx[i]].push_back(i);
  dp[0][k] = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = a[i]; j <= sum; j++) dp[i][j + b[i]] = dp[i - 1][j];
    sum += b[i];
    for (auto x : p[i]) {
      for (long long int j = a[i]; j <= sum; j++)
        dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + c[x]);
    }
  }
  long long int ans = *max_element(dp[n].begin(), dp[n].end());
  if (dp[n][sum] == -1) ans = -1;
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
