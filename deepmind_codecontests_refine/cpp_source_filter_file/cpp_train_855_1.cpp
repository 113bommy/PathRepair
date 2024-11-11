#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;
constexpr int mod = 998244353;
ll n, k;
ll fac[maxn], facinv[maxn];
ll qpow(ll a, ll b) {
  ll ret = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) ret = (ret * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ret;
}
inline void init() {
  fac[1] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  facinv[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; --i) facinv[i] = facinv[i + 1] * (i + 1) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  init();
  ll tmp = n - k;
  if (tmp <= 0) {
    cout << "0\n";
    return 0;
  }
  ll ans = 0;
  for (int i = 0; i <= tmp; ++i) {
    ll tmp1 = fac[tmp] * facinv[i] % mod * facinv[tmp - i] % mod *
              qpow(tmp - i, n) % mod;
    if (i % 2 == 1)
      ans -= tmp1;
    else
      ans += tmp1;
    ans += ans < 0 ? mod : 0;
    ans -= ans >= mod ? mod : 0;
  }
  ans = ans * fac[n] % mod * facinv[tmp] % mod * facinv[n - tmp] % mod;
  cout << (tmp != n ? ans * 2 % mod : ans) << '\n';
  return 0;
}
