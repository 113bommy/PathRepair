#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
long long dp[3211][101][2];
int n, l;
int a[101], b[101];
int res;
int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n >> l) {
    for (int i = (0); i < ((n)); ++i) cin >> a[i] >> b[i];
    memset(dp, 0, sizeof(dp));
    for (int i = (0); i < ((n)); ++i) {
      dp[a[i]][i][0] = 1;
      if (a[i] != b[i]) dp[b[i]][i][1] = 1;
    }
    for (int len = (0); len < ((3001)); ++len)
      for (int i = (0); i < ((n)); ++i)
        for (int j = (0); j < ((n)); ++j)
          if (i != j) {
            if (a[i] == a[j])
              dp[len + a[i] + b[j]][j][1] += dp[len + a[i]][i][0] %= mod;
            if (a[j] != b[j] && a[i] == b[j])
              dp[len + a[i] + a[j]][j][0] += dp[len + a[i]][i][0] %= mod;
            if (b[i] == a[j])
              dp[len + b[i] + b[j]][j][1] += dp[len + b[i]][i][1] %= mod;
            if (a[j] != b[j] && b[i] == b[j])
              dp[len + b[i] + a[j]][j][0] += dp[len + b[i]][i][1] %= mod;
          }
    int res = 0;
    for (int i = (0); i < ((n)); ++i)
      for (int j = (0); j < ((2)); ++j) res += dp[l][i][j] %= mod;
    res %= mod;
    cout << res << endl;
  }
  return 0;
}
