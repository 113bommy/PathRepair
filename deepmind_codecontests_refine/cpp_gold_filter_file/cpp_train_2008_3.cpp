#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
const long long MOD = 998244353;
long long ara[MX * 2];
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1LL) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1LL;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
long long fact[2 * MX];
void factors(long long n) {
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = modMul(fact[i - 1], i);
}
long long nCr(long long n, long long r) {
  long long ans = modDiv(fact[n], modMul(fact[r], fact[n - r]));
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  factors(2 * n);
  for (int i = 0; i < 2 * n; i++) cin >> ara[i];
  sort(ara, ara + 2 * n);
  long long small = 0, big = 0;
  for (int i = 0; i < n; i++) small = modAdd(small, ara[i]);
  for (int i = n; i < 2 * n; i++) big = modAdd(big, ara[i]);
  long long dif = modSub(big, small);
  long long p = nCr(2 * n, n);
  long long ans = modMul(dif, p);
  cout << ans << endl;
}
