#include <bits/stdc++.h>
using namespace std;
template <class T>
void minn(T &a, T b) {
  a = min(a, b);
}
template <class T>
void maxx(T &a, T b) {
  a = max(a, b);
}
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const long long MOD = 998244353LL;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mul(long long a, long long b) { return (1LL * a * b) % MOD; }
long long pow(long long a, long long p) {
  long long ret = 1LL;
  while (p) {
    if (p & 1LL) ret *= a;
    a *= a;
    ret %= MOD;
    a %= MOD;
    p >>= 1;
  }
  return ret;
}
long long inv(long long x) { return pow(x, MOD - 2); }
const long long MX = 10000;
long long fact[MX], ifact[MX];
long long choose(long long n, long long r) {
  long long ans;
  if (n < r)
    ans = 0;
  else if (n == r)
    ans = 1;
  else
    ans = (((fact[n] * ifact[n - r]) % MOD) * ifact[r]) % MOD;
  return ans;
}
long long parity(long long i) {
  if (i % 2 == 0)
    return 1;
  else
    return -1 + MOD;
}
long long g(long long s, long long p, long long m) {
  long long ans = 0;
  for (int i = 0; i <= (int)p; i++)
    ans = add(ans, mul(parity(i), mul(choose(p, i),
                                      choose(s + p - 1 - i * (m + 1), p - 1))));
  return ans;
}
int main() {
  io();
  long long n = 100;
  fact[0] = 1;
  for (int i = 1; i <= (int)n; i++) fact[i] = mul(i, fact[i - 1]);
  for (int i = 0; i <= (int)n; i++) ifact[i] = inv(fact[i]);
  long long p, s, r;
  cin >> p >> s >> r;
  long long ans = 0;
  for (int t = r; t <= (int)s; t++)
    for (int q = 1; q <= (int)p; q++)
      ans = add(ans, mul(choose(p - 1, q - 1),
                         mul(inv(q), g(s - q * t, p - q, t - 1))));
  ans = mul(ans, inv(choose(s - r + p - 1, p - 1)));
  cout << ans << "\n";
  return 0;
}
