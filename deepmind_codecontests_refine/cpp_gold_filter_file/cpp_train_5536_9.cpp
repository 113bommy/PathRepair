#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll mod = 1000000007;
const ll M = 1000000000000000000ll;
inline ll add(ll a, ll b) { return ((a % mod + b % mod) % mod); }
inline ll sub(ll a, ll b) { return ((a % mod - b % mod + mod) % mod); }
inline ll mult(ll a, ll b) { return (((a % mod) * (b % mod)) % mod); }
inline ll power(ll n, ll x) {
  ll p = 1;
  while (x != 0) {
    if (x % 2 == 0) {
      n = mult(n, n);
      x = x / 2;
    }
    p = mult(p, n);
    x--;
  }
  return p;
}
inline ll recurmult(ll a, ll b) {
  ll r = 0;
  while (b) {
    if (b & 1) r = add(r, a);
    a = mult(2, a);
    b >>= 1;
  }
  return r % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  ll arr[n + 1];
  for (ll i = 1; i <= n; i++) cin >> arr[i];
  ll q;
  cin >> q;
  map<ll, ll> m1;
  map<ll, pair<ll, ll>> m2;
  for (ll i = 1; i <= q; i++) {
    ll x, y, z;
    cin >> x;
    if (x == 2) {
      cin >> y;
      m1[i] = y;
    } else {
      cin >> y >> z;
      m2[i] = {y, z};
    }
  }
  ll z = 0;
  map<ll, ll> ans;
  map<ll, ll> done;
  for (ll i = q; i >= 1; i--) {
    if (m1.find(i) != m1.end())
      z = max(z, m1[i]);
    else {
      ll x, y;
      x = m2[i].first;
      y = m2[i].second;
      if (done[x] == 0) {
        ans[x] = max(y, z);
        done[x] = 1;
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (done[i] == 0) ans[i] = max(z, arr[i]);
    cout << ans[i] << " ";
  }
}
