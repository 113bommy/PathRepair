#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using TP = tuple<ll, ll, ll>;
void init_io() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
ll fac[510000], finv[510000], inv[510000];
ll pw[510000];
void COMinit() {
  pw[0] = 1;
  pw[1] = 2;
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < 510000; i++) {
    fac[i] = fac[i - 1] * i % 998244353;
    inv[i] = 998244353 - inv[998244353 % i] * (998244353 / i) % 998244353;
    finv[i] = finv[i - 1] * inv[i] % 998244353;
    pw[i] = (pw[i - 1] * 2) % 998244353;
  }
}
long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % 998244353) % 998244353;
}
signed main() {
  init_io();
  ll n, m, ans = 0;
  cin >> n >> m;
  COMinit();
  if (n == 2) {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = n - 1; i <= m; i++) {
    ll tmp = ((i - 1) * COM(i - 2, n - 3)) % 998244353;
    ans += tmp;
    ans %= 998244353;
  }
  ans *= pw[n - 3];
  ans %= 998244353;
  cout << ans << endl;
}
