#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int N = 2e5 + 5;
ll n, h[N], k, fact[N];
ll powmod(ll a, ll b) {
  ll x = a, res = 1LL;
  while (b) {
    if (b & 1LL) (res *= x) %= MOD;
    (x *= x) %= MOD;
    b >>= 1LL;
  }
  return res;
}
inline ll inversemod(ll a) { return powmod(a, MOD - 2); }
ll C(ll k, ll n) {
  return (((fact[n] * inversemod(fact[k])) % MOD) * inversemod(fact[n - k])) %
         MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  cin >> n >> k;
  for (ll i = 1; i <= n; ++i) {
    cin >> h[i];
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  ll num = 0;
  for (ll i = 1; i <= n; ++i) num += (h[i] != h[i % n + 1]);
  ll res = 0;
  for (ll i = 0; i < num; ++i) {
    ll tmp = 0, t = num - i;
    if (t & 1)
      tmp = powmod(2, t - 1);
    else
      tmp = (((powmod(2, t) - C(t / 2, t) + MOD) % MOD) * inversemod(2)) % MOD;
    res += (((tmp * powmod(k - 2, i)) % MOD) * C(i, num)) % MOD;
  }
  (res *= powmod(k, n - num)) %= MOD;
  cout << res;
  return 0;
}
