#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e3 + 10, N = 1e3 + 5, mod = 1e9 + 7;
long long fact[MX], inv[MX], invfact[MX];
long long mult(long long a, long long b) {
  a %= mod;
  b %= mod;
  return (a * b) % mod;
}
void init_INV() {
  fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
  for (long long i = 2; i <= N; i++) {
    fact[i] = mult(fact[i - 1], i);
    inv[i] = mult(inv[mod % i], mod - mod / i);
    invfact[i] = mult(invfact[i - 1], inv[i]);
  }
}
long long ncr(long long n, long long r) {
  long long den = invfact[r] * invfact[n - r];
  den %= mod;
  return (fact[n] * den) % mod;
}
int32_t main() {
  init_INV();
  long long n, m;
  cin >> n >> m;
  cout << ncr(n + 2 * m - 1, 2 * m);
}
