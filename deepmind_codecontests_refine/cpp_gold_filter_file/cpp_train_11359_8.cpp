#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m, a, b, c;
  cin >> n;
  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  cin >> b >> c;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll t = v[i] / (b + c);
    if (v[i] > b && t == 0) t++;
    ans += t;
    if (v[i] - t * (b + c) > b && t != 0) ans++;
  }
  cout << ans * c;
  return 0;
}
