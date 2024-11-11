#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e6 + 10;
long long n, m, f[N], inv[N];
long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % MOD;
    b >>= 1;
    a = (a * a) % MOD;
  }
  return r % MOD;
}
long long comb(long long n, long long k) {
  return (f[n] * ((inv[k] * inv[n - k]) % MOD)) % MOD;
}
long long A(long long n, long long k) { return (f[n] * inv[n - k]) % MOD; }
long long cayley(long long x, long long y) {
  return (y * qpow(x, x - y - 1)) % MOD;
}
int main() {
  cin >> n >> m;
  f[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < N; i++)
    f[i] = (f[i - 1] * i) % MOD, inv[i] = qpow(f[i], MOD - 2);
  long long res = 0;
  for (int k = 1; k < n; k++) {
    long long ac = 1;
    if (k > m) break;
    ac = (ac * A(n - 2, k - 1)) % MOD;
    ac = (ac * comb(m - 1, k - 1)) % MOD;
    ac = ac * qpow(m, n - k - 1);
    if (k + 1 < n) ac = (ac * cayley(n, k + 1)) % MOD;
    res = (res + ac) % MOD;
  }
  cout << res << endl;
}
