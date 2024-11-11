#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000 + 6;
const long long MOD = 998244353;
long long fact[MAX], invfact[MAX];
long long bigmod(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return ret;
}
long long modinv(long long x) { return bigmod(x, MOD - 2); }
long long nCr(long long n, long long r) {
  return ((fact[n] * invfact[r]) % MOD * invfact[n - r]) % MOD;
}
long long calc(long long p, long long q) {
  if (p < q) swap(p, q);
  long long ret = 0;
  for (long long i = 0; i <= q; i++) {
    ret += (fact[i] * ((nCr(p, i) * nCr(q, i)) % MOD)) % MOD;
    ret %= MOD;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1ll;
  for (long long i = 1; i < MAX; i++) fact[i] = (i * fact[i - 1]) % MOD;
  for (long long i = 0; i < MAX; i++) invfact[i] = modinv(fact[i]);
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 1ll;
  ans = (ans * calc(a, b)) % MOD;
  ans = (ans * calc(b, c)) % MOD;
  ans = (ans * calc(a, c)) % MOD;
  cout << ans;
}
