#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;
int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> v(100);
  map<ll, ll> m;
  ll temp_val = 1;
  for (ll i = 0; temp_val <= 1e17; i++) {
    m[temp_val] = i;
    temp_val *= 2;
  }
  for (ll i = 0; i < n; i++) {
    ll t;
    cin >> t;
    v[m[t]]++;
  }
  for (ll i = 0; i < q; i++) {
    ll t;
    cin >> t;
    vector<ll> b;
    while (t > 0) {
      b.push_back(t % 2);
      t /= 2;
    }
    ll cur = 0, ans = 0;
    for (ll i = b.size() - 1; i >= 0; i--) {
      b[i] += cur;
      cur = 0;
      if (b[i] == v[i]) {
        ans += b[i];
        cur = 0;
        continue;
      } else if (b[i] < v[i]) {
        ans += (b[i]);
        if (cur < 0) cur = 0;
        cur = 0;
        continue;
      } else {
        ans += v[i];
        cur = b[i] - v[i];
        cur *= 2;
        continue;
      }
    }
    if (cur == 0) {
      cout << ans << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
