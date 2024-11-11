#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, dp[N][21];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int mx = -1;
  for (int i = 1; i <= n; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    dp[t1][0] = max(dp[t1][0], t2);
    mx = max(mx, t2);
  }
  for (int i = 1; i <= mx; i++) dp[i][0] = max(dp[i][0], dp[i - 1][0]);
  for (int i = 1; i <= 20; i++)
    for (int j = 0; j <= mx; j++) dp[j][i] = dp[dp[j][i - 1]][i - 1];
  while (m--) {
    int t1, t2;
    cin >> t1 >> t2;
    int ans = 0;
    for (int i = 20; i >= 0; --i)
      if (dp[t1][i] < t2) {
        ans += 1 << i;
        t1 = dp[t1][i];
      }
    if (dp[t1][0] >= t2)
      cout << ans + 1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
