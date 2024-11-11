#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10, mod = 1e9 + 7;
int t, n, k;
long long dp[maxn];
int main() {
  dp[1] = dp[2];
  dp[3] = 4;
  dp[4] = 4, dp[5] = 12;
  for (int i = 6; i < maxn; ++i) {
    if (i % 3 == 0)
      dp[i] = (dp[i - 1] + 2 * dp[i - 2] + 4) % mod;
    else
      dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % mod;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}
