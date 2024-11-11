#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m, x, y, f = 1, i = 1;
  cin >> n >> m >> x >> y;
  map<pair<ll, ll>, ll> mp;
  cout << x << ' ' << y << endl;
  mp[{x, y}] = 1;
  if (!mp[{1, y}]) cout << 1 << ' ' << y << endl;
  mp[{1, y}] = 1;
  for (; i <= n;) {
    for (ll j = 1; j <= m; j++) {
      if (!mp[{i, j}]) cout << i << ' ' << j << endl;
      mp[{i, j}] = 1;
    }
    i++;
    if (i > n) break;
    for (ll j = m; j >= 1; j--) {
      if (!mp[{i, j}]) cout << i << ' ' << j << endl;
      mp[{i, j}] = 1;
    }
    i++;
  }
}
