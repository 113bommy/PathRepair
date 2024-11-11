#include <bits/stdc++.h>
using namespace std;
long long dp[10000005];
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  dp[1] = x;
  dp[0] = 0;
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0)
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
    else
      dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + y);
  }
  cout << dp[n] << "\n";
  return 0;
}
