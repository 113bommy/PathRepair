#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 * 1000 + 19;
const int Mod = 1e9 + 7;
const int inf = 1 << 30;
int n, dp[MAX_N][4], a[MAX_N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (a[i] == 1) {
        if (!(j & 1)) {
          if (j)
            dp[i + 1][j] = max(dp[i][j], dp[i][j - 1]) + 1;
          else
            dp[i + 1][j] = dp[i][j] + 1;
        } else
          dp[i + 1][j] = dp[i][j];
      } else {
        if (j & 1)
          dp[i + 1][j] = max(dp[i][j], dp[i][j - 1]) + 1;
        else
          dp[i + 1][j] = dp[i][j];
      }
    }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++) ans = max(ans, dp[i + 1][j] * 1ll);
  cout << ans;
  return 0;
}
