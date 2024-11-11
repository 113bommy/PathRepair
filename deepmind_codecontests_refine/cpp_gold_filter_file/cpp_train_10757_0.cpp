#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  int n, dp[1000], sum, len, i, j, ans = 0;
  const int mod = 1000000007;
  cin >> s1 >> s2 >> n;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1, len = ((int)s1.size());
  for (i = 0; i < n; i++) {
    sum = 0;
    for (j = 0; j < len; j++) {
      sum += dp[j];
      if (sum >= mod) sum -= mod;
    }
    for (j = 0; j < len; j++) {
      dp[j] = sum - dp[j];
      if (dp[j] < 0) dp[j] += mod;
      if (dp[j] >= mod) dp[j] -= mod;
    }
  }
  for (i = 0; i < len; i++) {
    if (s1.substr(i) + s1.substr(0, i) == s2) {
      ans += dp[i];
      if (ans >= mod) ans -= mod;
    }
  }
  cout << ans << endl;
}
