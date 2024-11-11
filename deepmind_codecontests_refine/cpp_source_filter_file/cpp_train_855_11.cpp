#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 5;
const long long mod = 998244353;
long long fac[maxn], ifac[maxn];
long long inv[maxn];
void genf() {
  fac[0] = inv[0] = ifac[0] = 1;
  fac[1] = inv[1] = ifac[1] = 1;
  for (int i = 2; i < maxn; i++) {
    fac[i] = (1LL * fac[i - 1] * i) % mod;
    inv[i] = (-(1LL * (mod / i) * inv[mod % i]) % mod + mod) % mod;
    ifac[i] = (1LL * ifac[i - 1] * inv[i]) % mod;
  }
}
long long nck(long long n, long long k) {
  if (n < k) return 0;
  return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}
long long pw(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) {
      res = res * x;
      res %= mod;
    }
    x = x * x;
    x %= mod;
    y = y / 2;
  }
  res %= mod;
  res += mod;
  return res % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  genf();
  long long n, k;
  cin >> n >> k;
  if (k == n) out(0);
  if (k == 0) out(fac[n]);
  long long c = n - k;
  long long ans = pw(c, n) % mod;
  for (int i = 1; i <= min(n - 1, c); i++) {
    long long cur = pw(c - i, n) * nck(c, i) % mod;
    if (i % 2) {
      ans -= cur;
    } else {
      ans += cur;
    }
    ans %= mod;
  }
  ans = ans * nck(n, c) % mod;
  ans = ans * 2;
  ans %= mod;
  ans += mod;
  ans %= mod;
  out(ans);
  return 0;
}
