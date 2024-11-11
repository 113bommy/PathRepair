#include <bits/stdc++.h>
using namespace std;
vector<long long> dp(1e7 + 10, 0ll);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(0);
  long long n, a, b;
  cin >> n >> a >> b;
  dp[1] = a;
  for (int i = 1; i <= n; ++i) {
    if (i % 2) {
      dp[i] = min(dp[i - 1] + a, dp[(i + 1) / 2] + a + b);
      continue;
    }
    dp[i] = min(dp[i - 1] + a, dp[i / 2] + b);
  }
  { std::cout << dp[n] << '\n'; };
  return 0;
}
