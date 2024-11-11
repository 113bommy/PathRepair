#include <bits/stdc++.h>
using namespace std;
using namespace std;
#pragma comment(linker, "/STACK:167177216")
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int cost[11][111], num[11][111], sell[11][111];
  for (int i = 0; i < n; ++i) {
    string trash;
    cin >> trash;
    for (int j = 0; j < m; ++j) {
      int a, b, c;
      cin >> cost[i][j] >> sell[i][j] >> num[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int dp[111];
      for (int s = 0; s < 111; ++s) dp[s] = -1e9;
      dp[0] = 0;
      for (int u = 0; u < m; ++u)
        for (int q = k; q >= 0; --q) {
          for (int w = 1; w <= num[i][u]; ++w) {
            if (q + w <= k) {
              dp[q + w] = max(dp[q] + (sell[j][u] - cost[i][u]) * w, dp[q + w]);
              ans = max(ans, dp[q + w]);
            }
          }
          ans = max(ans, dp[q]);
        }
    }
  cout << ans;
  return 0;
}
