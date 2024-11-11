#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long qpow(long long a, long long b, long long m) {
  long long r = 1;
  a %= m;
  for (; b; b >>= 1) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
  }
  return r;
}
const int inf = 0x7fffffff;
const long long mod = 1e9 + 7;
const int maxn = 300;
long long fac[maxn], inv[maxn];
long long f[maxn];
int n, k;
void init() {
  inv[0] = fac[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = qpow(fac[i], mod - 2, mod);
  }
}
long long C(long long n, long long m) {
  return (((fac[n] * inv[m]) % mod) * inv[n - m]) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  init();
  for (int i = 1; i <= n; i++)
    f[i] = qpow((qpow(k, i, mod) - qpow(k - 1, i, mod) + mod) % mod, n, mod);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long x = (i & 1) ? 1 : -1, res = 1;
    res *= qpow(k - 1, n * (i - 1), mod);
    res *= C(n, i - 1);
    res %= mod;
    res *= f[n - i + 1];
    res %= mod;
    ans += res * x;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
