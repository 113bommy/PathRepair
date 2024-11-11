#include <bits/stdc++.h>
using namespace std;
long long dp[1000 + 10][100 + 10];
long long ways[1000 + 10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, MOD, pow10 = 1;
  cin >> n >> k >> MOD;
  for (int i = n; i >= 1; i--) {
    for (int d = 0; d <= 9; d++) {
      long long val = (d * pow10) % k;
      if (i == n) {
        dp[i][(int)val]++;
        dp[i][(int)val] %= MOD;
        if (val == 0 && d != 0) {
          ways[i]++;
          ways[i] %= MOD;
        }
        continue;
      }
      for (int y = 1; y < k; y++) {
        dp[i][(y + (int)val) % k] += dp[i + 1][y];
        dp[i][(y + (int)val) % k] %= MOD;
        if (d != 0 && (y + (int)val) % k == 0) {
          ways[i] += dp[i + 1][y];
          ways[i] %= MOD;
        }
      }
      dp[i + 1][val % k]++;
      if (d != 0 && val % k == 0) ways[i]++;
    }
    pow10 *= 10LL;
    pow10 %= MOD;
  }
  long long ans = 0, dig = 1;
  for (int j = 1; j <= n; j++) {
    ans += dig * ways[j];
    ans %= MOD;
    if (j == 1)
      dig *= 9LL;
    else
      dig *= 10LL;
    dig %= MOD;
  }
  cout << ans << endl;
  return 0;
}
