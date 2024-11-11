#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
ll sol[6];
ll v[6];
ll p[6];
ll sc[6] = {3000, 2500, 2000, 1500, 1000, 500};
ll ar[6] = {32, 16, 8, 4, 2, 1};
ll n, x;
ll ans(ll id, ll add, ll num) {
  ll ac = sol[id] + add * num;
  ll all = n + num;
  for (ll i = 0; i < 6; i++) {
    if (ac * ar[i] <= all) {
      return sc[i];
    }
  }
  while (1)
    ;
  return -1;
}
ll ok(ll x) {
  ll sv = 0, sp = 0;
  for (ll i = 1; i <= 5; i++) {
    if (v[i] > -1 && p[i] > -1) {
      if (v[i] < p[i]) {
        ll maxsc = ans(i, 0, x);
        sv += maxsc - maxsc * v[i] / 250;
        sp += maxsc - maxsc * p[i] / 250;
      } else {
        ll maxsc = ans(i, 1, x);
        sv += maxsc - maxsc * v[i] / 250;
        sp += maxsc - maxsc * p[i] / 250;
      }
    } else if (v[i] > -1) {
      ll maxsc = ans(i, 0, x);
      sv += maxsc - maxsc * v[i] / 250;
    } else if (p[i] > -1) {
      ll maxsc = ans(i, 0, x);
      sp += maxsc - maxsc * p[i] / 250;
    }
  }
  return sv - sp;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n;
  for (ll j = 1; j <= 5; j++) {
    cin >> v[j];
    if (v[j] > -1) sol[j]++;
  }
  for (ll j = 1; j <= 5; j++) {
    cin >> p[j];
    if (p[j] > 1) sol[j]++;
  }
  for (ll i = 1; i <= n - 2; i++) {
    for (ll j = 1; j <= 5; j++) {
      cin >> x;
      if (x > -1) {
        sol[j]++;
      }
    }
  }
  for (ll i = 0; i <= 5000; i++) {
    if (ok(i) > 0) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
