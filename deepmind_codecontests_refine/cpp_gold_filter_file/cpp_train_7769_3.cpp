#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long inv_pow(long long x, long long mod) {
  long long res = 1, n = mod - 2;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long dp[2048][2048];
int main() {
  int k;
  long long pa, emplace_back;
  cin >> k >> pa >> emplace_back;
  long long d = inv_pow(pa + emplace_back, mod);
  long long t = inv_pow((1 - pa * d) % mod + mod, mod);
  long long sum = 0;
  dp[1][0] = 1;
  for (int i = (1); i < (k + 1); ++i)
    for (int j = (0); j < (k + 1); ++j) {
      if (i + j >= k) {
        sum += dp[i][j] * (i + j) % mod;
        sum += dp[i][j] * (t - 1 + mod) % mod;
        sum %= mod;
      } else {
        dp[i + 1][j] += dp[i][j] * pa % mod * d % mod;
        dp[i][j + i] += dp[i][j] * emplace_back % mod * d % mod;
        dp[i + 1][j] %= mod;
        dp[i][j + i] %= mod;
      }
    }
  cout << sum << endl;
  return 0;
}
