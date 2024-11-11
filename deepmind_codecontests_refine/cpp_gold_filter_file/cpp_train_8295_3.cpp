#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long mod2 = 1e9 + 9;
const int N = 1e6;
long long fpow(long long base, long long expo) {
  long long res = 1;
  base %= mod;
  while (expo > 0) {
    if (expo & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    expo >>= 1;
  }
  return res;
}
long long inv(long long a) { return fpow(a, mod - 2); }
long long fact[N + 1];
long long ifact[N + 1];
void init() {
  fact[0] = 1;
  for (int i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % mod;
  ifact[0] = 1;
  for (int i = 1; i <= N; i++) ifact[i] = (ifact[i - 1] * inv(i)) % mod;
}
long long nCr(long long n, long long r) {
  r = min(r, n - r);
  long long res = fact[n];
  res *= ifact[r];
  res %= mod;
  res *= ifact[n - r];
  res %= mod;
  return res;
}
int main(void) {
  init();
  long long n;
  cin >> n;
  long long res = 0;
  for (int k = 1; k <= n; k++) {
    long long mag = fpow(3, n * (n - k) + k);
    mag %= mod;
    mag *= 2 * nCr(n, k);
    mag %= mod;
    if ((1 + k) & 1) mag = -mag;
    res += mag;
    if (res < 0)
      res += mod;
    else if (res > mod)
      res -= mod;
  }
  for (int i = 0; i <= n - 1; i++) {
    long long term = -fpow(3, i) + mod;
    term = fpow((1 + term), n) - fpow(term, n);
    if (term < 0) term += mod;
    term *= (3 * nCr(n, i)) % mod;
    term %= mod;
    if ((i + 1) & 1) term = -term;
    res += term;
    if (res < 0)
      res += mod;
    else if (res > mod)
      res -= mod;
  }
  cout << res << "\n";
}
