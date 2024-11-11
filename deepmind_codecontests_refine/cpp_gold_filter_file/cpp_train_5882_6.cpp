#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long fact[100000];
long long ex(long long a, long long e) {
  long long res = 1;
  for (; e; e /= 2) {
    if (e & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
  }
  return res;
}
long long ncr(long long n, long long k) {
  long long q = fact[n];
  q *= ex(fact[k], MOD - 2);
  q %= MOD;
  q *= ex(fact[n - k], MOD - 2);
  q %= MOD;
  return q;
}
long long dp[4444][4444];
int main() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 100000; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  dp[1][1] = 1;
  for (int i = 1; i < 4444; ++i) {
    for (int j = 1; j < 4444; ++j) {
      if (i == 1 && j == 1) continue;
      dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1] * i) % MOD;
    }
  }
  long long n;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    long long q = ncr(n, i);
    long long w = n - i;
    for (int j = 1; j <= w; ++j) {
      res += q * dp[j][w] % MOD;
    }
  }
  res += 1;
  res %= MOD;
  res += MOD;
  res %= MOD;
  cout << res << '\n';
}
