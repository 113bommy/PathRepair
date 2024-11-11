#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll mod1 = 998244353;
const ll N = 1e6 + 5;
ll modpow(ll a, ll b, ll c) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % c;
    }
    a = (a * a) % c;
    b >>= 1;
  }
  return res;
}
ll modinv(ll m, ll n) { return modpow(m, n - 2, n); }
void solve() {
  ll n, q;
  cin >> n >> q;
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0, j = 0, t = 0;
  for (ll i = 0; i < n; i++) {
    if (j % 2 == 0) {
      while (i < n - 1 && a[i] <= a[i + 1]) {
        i++;
      }
      ans += a[i];
    } else {
      while (i < n - 1 && a[i] >= a[i + 1]) {
        i++;
      }
      ans -= a[i];
      t = a[i];
    }
    j++;
  }
  if (j % 2 == 0) {
    ans += t;
  }
  cout << ans << endl;
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
