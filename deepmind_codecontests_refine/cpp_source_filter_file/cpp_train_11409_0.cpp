#include <bits/stdc++.h>
using namespace std;
vector<long long> a, b, dp;
int main() {
  int n, i;
  long long ans;
  cin >> n;
  a.resize(n);
  b.resize(n);
  dp.resize(n);
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n - 1; i++) b[i] = abs(a[i + 1] - a[i]);
  dp[0] = b[0];
  ans = dp[0];
  for (i = 1; i < n - 1; i++) {
    if (i & 1)
      dp[i] = dp[i - 1] - b[i];
    else
      dp[i] = max(dp[i - 1] + b[i], b[i]);
    ans = max(ans, dp[i]);
  }
  dp[0] = 0;
  if (n > 3) {
    dp[1] = b[1];
    ans = max(dp[1], ans);
  }
  for (i = 2; i < n - 1; i++) {
    if (i & 1)
      dp[i] = max(dp[i - 1] + b[i], b[i]);
    else
      dp[i] = dp[i - 1] - b[i];
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
