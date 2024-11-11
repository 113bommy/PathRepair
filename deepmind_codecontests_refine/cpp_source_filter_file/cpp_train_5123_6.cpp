#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll MOD = 998244353, N = 1e5 + 10;
ll power(ll x, ll y) {
  ll ans = 1;
  if (y == 1) return x % MOD;
  x = x % MOD, y = y % (MOD - 1);
  while (y) {
    if (y & 1) ans = (ans * x) % MOD;
    x *= x;
    x = x % MOD;
    y >>= 1;
  }
  return ans;
}
ll inv(ll x) { return power(x, MOD - 2); }
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  vector<ll> ff(n + 1);
  ff[1] = 100 * inv(a[1]);
  ff[1] = ff[1] % MOD;
  for (ll i = 2; i < n + 1; i++) {
    ff[i] = (100 * (ff[i - 1] + 1)) * inv(a[i]);
    ff[i] = ff[i] % MOD;
  }
  cout << ff[n] << '\n';
  return 0;
}
