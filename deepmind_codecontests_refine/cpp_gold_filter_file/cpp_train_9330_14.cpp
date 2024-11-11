#include <bits/stdc++.h>
using namespace std;
const long long N = 5e6 + 101;
long long jc[N], f[N], s[N], inv[N];
const long long mod = 1e9 + 7;
long long n, k;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  return jc[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
  cin >> n >> k;
  jc[0] = 1;
  for (long long i = 1; i <= n; i++) jc[i] = (jc[i - 1] * i) % mod;
  inv[n] = ksm(jc[n], mod - 2);
  for (long long i = n - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;
  f[0] = s[0] = 1;
  for (long long i = 1; i <= n; i++) {
    f[i] = (jc[i - 1] * (s[i - 1] - (i - k - 1 >= 0 ? s[i - k - 1] : 0))) % mod;
    s[i] = (s[i - 1] + f[i] * inv[i] % mod) % mod;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    ans = (ans + f[i - 1] * C(n - 1, i - 1) % mod * jc[n - i] % mod) % mod;
  cout << ((jc[n] - ans) % mod + mod) % mod << endl;
}
