#include <bits/stdc++.h>
using namespace std;
const long long sz = 2e6 + 5, mod = 1e9 + 7;
long long t, n, m, k, q;
long long power(long long a, long long b) {
  if (b < 0) b += mod - 1;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long Inv(long long a) { return power(a, mod - 2); }
long long fact[1000005], ifact[1000005];
inline long long ncr(long long n, long long r) {
  if (n < r || r < 0 || n < 0) return 0;
  return (((fact[n] * ifact[r]) % mod) * ifact[n - r]) % mod;
}
void init() {
  fact[0] = 1;
  for (long long i = 1; i < 1000001; i++) fact[i] = (fact[i - 1] * i) % mod;
  ifact[1000000] = power(fact[1000000], mod - 2);
  for (long long i = 999999; i >= 0; i--)
    ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  init();
  while (t--) {
    long long a, b;
    cin >> n >> m >> a >> b;
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
      long long tree = ((i + 1) * power(n, n - i - 2)) % mod;
      long long rem = n - i - 1;
      long long edge = (ncr(m - 1, i - 1) * power(m, rem)) % mod;
      long long inter = (ncr(n - 2, i - 1) * fact[i - 1]) % mod;
      long long tmp = (tree * ((edge * inter) % mod)) % mod;
      ans += tmp;
      ans %= mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
