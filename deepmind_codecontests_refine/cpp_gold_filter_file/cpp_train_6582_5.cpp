#include <bits/stdc++.h>
using namespace std;
int SET(int n, int pos) { return n = n | (1 << pos); }
int RESET(int n, int pos) { return n = n & ~(1 << pos); }
int CHECK(int n, int pos) { return (bool)(n & (1 << pos)); }
int bigMod(int n, int power, int MOD) {
  if (power == 0) return 1;
  if (power % 2 == 0) {
    int ret = bigMod(n, power / 2, MOD);
    return ((ret % MOD) * (ret % MOD)) % MOD;
  } else
    return ((n % MOD) * (bigMod(n, power - 1, MOD) % MOD)) % MOD;
}
int modInverse(int n, int MOD) { return bigMod(n, MOD - 2, MOD); }
int POW(int x, int y) {
  int res = 1;
  for (; y;) {
    if ((y & 1)) {
      res *= x;
    }
    x *= x;
    y >>= 1;
  }
  return res;
}
int inverse(int x) {
  double p = ((double)1.0) / x;
  return (p) + 1e-9;
}
int gcd(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
int nC2(int n) { return n * (n - 1) / 2; }
int MOD(int n, int mod) {
  if (n >= 0)
    return n % mod;
  else if (-n == mod)
    return 0;
  else
    return mod + (n % mod);
}
long long int dp[35][65];
long long int call(long long int n, long long int r) {
  if (n == r) return 1;
  if (r == 1) return n;
  long long int &ret = dp[n][r];
  if (ret != -1) return ret;
  ret = call(n - 1, r) + call(n - 1, r - 1);
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int t, cas = 0;
  long long int n, m, tt;
  cin >> n >> m >> tt;
  long long int ans = 0;
  for (long long int i = 4; i <= n; i++) {
    if (tt - i > m || tt - i <= 0) continue;
    ans += call(n, i) * call(m, tt - i);
  }
  cout << ans << endl;
  return 0;
}
