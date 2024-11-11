#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int main() {
  int n, a[maxn + 5], b[maxn + 5], c[maxn + 5];
  long long dp[maxn + 5][3];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  dp[1][0] = a[0];
  dp[1][1] = -1e18;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = a[i - 1] + max(dp[i - 1][0] - a[i - 2] + b[i - 2],
                              dp[i - 1][1] - b[i - 2] + c[i - 2]);
    dp[i][1] = b[i - 1] + max(dp[i - 1][0], dp[i - 1][1]);
  }
  cout << max(dp[n][0], dp[n][1]);
  return 0;
}
