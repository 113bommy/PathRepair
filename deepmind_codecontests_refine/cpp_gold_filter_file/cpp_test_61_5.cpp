#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = n * (n - 1) * (n - 2);
    ans /= 6;
    map<ll, ll> m_a;
    map<ll, ll> m_b;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first >> v[i].second;
      m_a[v[i].first]++;
      m_b[v[i].second]++;
    }
    ll elem = 0;
    for (int i = 0; i < n; ++i) {
      elem += (m_a[v[i].first] - 1) * (m_b[v[i].second] - 1);
    }
    ans -= elem;
    cout << ans << '\n';
  }
}
