#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long pow_mod(long long x, long long n, long long mod) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return r;
}
long long invp(long long r, long long mod) { return pow_mod(r, mod - 2, mod); }
long long comb_pmod(int n, int k, long long mod) {
  if (n < k || k < 0) return 0;
  long long r = 1;
  for (int i = 1; i <= k; i++) {
    r *= i;
    r %= mod;
  }
  r = invp(r, mod);
  for (int i = n - k + 1; i <= n; i++) {
    r = (r * i) % mod;
  }
  return r;
}
long long c[2000][2000];
int main() {
  long long n;
  cin >> n;
  long long d[2000];
  bool f[2000] = {};
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    if (d[i] != -1) {
      d[i]--;
      f[d[i]] = true;
    }
  }
  long long a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (!f[i]) {
      if (d[i] != -1) {
        a++;
      } else {
        b++;
      }
    }
  }
  long long dp[2000] = {}, p[2000] = {};
  p[0] = 1;
  for (int i = 1; i <= a + b; i++) {
    p[i] = (p[i - 1] * i) % mod;
  }
  dp[0] = p[a];
  for (int i = 0; i < 2000; i++) {
    c[i][0] = 1;
    c[0][i] = 0;
  }
  c[0][0] = 1;
  for (int i = 1; i < 2000; i++) {
    for (int j = 1; j < 2000; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 1; i <= b; i++) {
    long long buf = 0;
    for (int j = 0; j < i; j++) {
      buf += c[i][i - j] * dp[j];
      buf %= mod;
    }
    dp[i] = (p[a + i] + mod - buf) % mod;
  }
  cout << dp[b] << endl;
  return 0;
}
