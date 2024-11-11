#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long expo_pow(long long x, long long y) {
  if (y == 0) return 1;
  y = y % (mod - 1);
  x %= mod;
  if (y == 0) y = mod - 1;
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return res;
}
long long add() { return 0; }
template <typename T, typename... Types>
T add(T var1, Types... var2) {
  return (((((long long)(var1)) % mod + (long long)(add(var2...))) % mod) +
          mod) %
         mod;
}
long long mul() { return 1; }
template <typename T, typename... Types>
T mul(T var1, Types... var2) {
  return (((long long)(var1)) % mod * (long long)(mul(var2...))) % mod;
}
const long long mx = 3e5;
long long fact[mx];
long long inv_fact[mx];
long long inv(long long x) { return expo_pow(x, mod - 2); }
void compute() {
  fact[0] = 1;
  for (long long i = 1; i < mx; ++i) fact[i] = mul(fact[i - 1], i);
  for (long long i = 0; i < mx; ++i) inv_fact[i] = inv(fact[i]);
}
void solve() {
  compute();
  long long n;
  cin >> n;
  long long a[2 * n];
  for (long long i = 0; i < 2 * n; ++i) cin >> a[i];
  sort(a, a + 2 * n);
  long long tmp = mul(fact[2 * n - 1], inv_fact[n], inv_fact[n - 1]);
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    ans = add(ans, a[2 * n - 1 - i] - a[i]);
  }
  ans = mul(ans, tmp, 2);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  long long i = 1;
  while (test--) {
    solve();
  }
}
