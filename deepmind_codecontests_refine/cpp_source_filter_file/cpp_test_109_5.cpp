#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long mod = 998244353;
int n, b, w;
long long f[maxn][10], fac[maxn], inv[maxn];
string s;
long long fast_pow(long long p, long long q) {
  long long ans = 1;
  while (q) {
    if (q & 1) {
      ans = ans * p % mod;
    }
    p = p * p % mod;
    q >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    if (s == "??") {
      f[i][3] = (f[i - 1][3] * 2ll + f[i - 1][1] + f[i - 1][2]) % mod;
      f[i][2] = (f[i - 1][2] + f[i - 1][0]) % mod;
      f[i][1] = (f[i - 1][1] + f[i - 1][0]) % mod;
      f[i][0] = 0;
    }
    if (s == "?B" || s == "WB" || s == "W?") {
      f[i][3] = (f[i - 1][3] + f[i - 1][1]) % mod;
      f[i][2] = (f[i - 1][2] + f[i - 1][0]) % mod;
      f[i][1] = 0;
      f[i][0] = 0;
    }
    if (s == "BW" || s == "?W" || s == "B?") {
      f[i][3] = (f[i - 1][3] + f[i - 1][2]) % mod;
      f[i][2] = 0;
      f[i][1] = (f[i - 1][1] + f[i - 1][0]) % mod;
      f[i][0] = 0;
    }
    if (s[0] == 'B')
      ++b;
    else if (s[0] == 'W')
      ++w;
    if (s[1] == 'B')
      ++b;
    else if (s[1] == 'W')
      ++w;
  }
  int num = 2 * n - b - w;
  b = n - b;
  w = n - w;
  fac[0] = 1;
  for (int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % mod;
  inv[maxn - 1] = fast_pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
  if (num < w + b)
    printf("0\n");
  else
    printf(
        "%lld\n",
        (fac[num] * inv[num - b] % mod * inv[b] % mod - f[n][3] + mod) % mod);
  return 0;
}
