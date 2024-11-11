#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll fpow(ll b, ll p) {
  if (p == 0) return 1;
  ll h = fpow(b, p / 2);
  if (p % 2) return h * b % (ll)(998244353) * h % (ll)(998244353);
  return h * h % (ll)(998244353);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> v(m);
  for (auto &i : v) cin >> i;
  ll now = k, i = 0, ans = 0;
  while (i < m) {
    ll cnt;
    for (cnt = 0; i < m && v[i] <= now; i++) cnt++;
    if (cnt == 0) {
      now += (v[i] - now + k - 1) / k * k;
    } else {
      now += cnt;
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
