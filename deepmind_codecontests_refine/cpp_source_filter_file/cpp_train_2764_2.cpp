#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
long long dp[N];
long long n, x, y;
int main() {
  cin >> n >> x >> y;
  for (int i = 2; i < N; i++) {
    dp[i] = 1e18;
  }
  dp[1] = x;
  for (int i = 1; i <= n; i++) {
    if (i % 2)
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y + x);
    else
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
  }
  cout << dp[n];
  return 0;
}
