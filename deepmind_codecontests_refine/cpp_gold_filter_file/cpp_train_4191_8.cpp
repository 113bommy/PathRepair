#include <bits/stdc++.h>
using namespace std;
const int MAXN = 555;
const long long INF = 1e18;
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<pair<long long, long long>>> dp(
      MAXN, vector<pair<long long, long long>>(MAXN, {-INF, 0}));
  dp[0][0] = {0, 0};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < k; j++)
      if (dp[i][j].first >= 0) {
        for (int z = 0; z < k && z <= a; z++) {
          long long baskets = dp[i][j].first;
          baskets += (j + z) / k;
          int rem_red = (j + z) % k;
          int all = a - z + b;
          baskets += all / k;
          all %= k;
          int rem_blue = dp[i][j].second + min(all, b);
          baskets += rem_blue / k;
          rem_blue %= k;
          dp[i + 1][rem_red] = max(dp[i + 1][rem_red], {baskets, rem_blue});
        }
      }
  }
  long long res = -INF;
  for (int i = 0; i < k; i++) {
    res = max(res, dp[n][i].first);
  }
  cout << res << "\n";
  return 0;
}
