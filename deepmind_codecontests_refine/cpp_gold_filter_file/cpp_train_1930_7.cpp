#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, MOD = 1e9 + 7;
long long dp[MAXN], h[MAXN], ans;
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      ans += (dp[i - 1] * (min(h[i - 1], h[i]) - 1)) % MOD;
      ans %= MOD;
    }
    ans += (h[i] - 1);
    ans %= MOD;
    if (i + 1 < n && h[i] < h[i + 1]) {
      dp[i] += h[i] - 1;
      if (i > 0) dp[i] += (dp[i - 1] * (min(h[i], h[i - 1]) - 1)) % MOD;
    } else if (i + 1 < n) {
      dp[i] += h[i + 1] - 1;
      if (i > 0) dp[i] += (dp[i - 1] * (min(h[i - 1], h[i + 1]) - 1)) % MOD;
    }
    dp[i] %= MOD;
  }
  cout << ans;
}
