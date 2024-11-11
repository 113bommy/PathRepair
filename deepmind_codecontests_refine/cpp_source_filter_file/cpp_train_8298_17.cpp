#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000005, P = 998244353;
int n;
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ret;
}
ll fac[N], inv[N];
inline ll C(ll m, ll n) { return fac[m] * inv[n] % P * inv[m - n] % P; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  ll ans = 0, anss = 0;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
  inv[n] = qpow(fac[n], P - 2);
  for (int i = n; i > 0; --i) inv[i - 1] = inv[i] * i % P;
  for (int i = 1; i <= n; i++)
    ans = (ans +
           C(n, i) * qpow(-1, i + 1) % P * qpow(3, n * 1ll * (n - i) + i) % P) %
          P;
  ans = (ans * 2 + P) % P;
  for (int i = 0; i < n; i++) {
    ll tt = -qpow(3, i);
    ll tmp =
        C(n, i) * qpow(-1, i + 1) % P * (qpow(1 + tt, n) - qpow(tt, n) + P) % P;
    anss = ((anss + tmp) % P + P) % P;
  }
  anss = (anss * 3 % P + P) % P;
  cout << (ans + anss) % P << endl;
  return 0;
}
