#include <bits/stdc++.h>
using namespace std;
int ans[1000];
double dp[20000][1000];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0),
      cout.precision(15);
  int k, q;
  while (cin >> k >> q) {
    memset(ans, 0, sizeof(ans));
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = int(1); i < int(20000); i++) {
      for (int j = int(1); j < int(k + 1); j++) {
        dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (k - j + 1)) / k;
      }
    }
    for (int p = 0, i = 1; p < 1000; p++) {
      for (; dp[i][k] * 2000 + 1e-7 < p; i++)
        ;
      ans[p] = i;
    }
    while (q--) {
      int p;
      cin >> p;
      cout << ans[p] << endl;
    }
  }
  return 0;
}
