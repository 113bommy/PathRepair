#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  long long dp[n + 1];
  dp[1] = x;
  for (int i = 2; i <= n; ++i) {
    if (i % 2 == 0)
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
    else
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y + x);
  }
  cout << dp[n];
  return 0;
}
