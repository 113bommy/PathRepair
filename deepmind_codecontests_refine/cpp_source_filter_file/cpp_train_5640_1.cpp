#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  map<ll, ll> mp;
  ll a, b;
  for (ll i = 1; i <= n - 1; i++) {
    cin >> a >> b;
    mp[a]++;
    mp[b]++;
  }
  for (auto &i : mp) {
    if (i.second % 2 == 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
