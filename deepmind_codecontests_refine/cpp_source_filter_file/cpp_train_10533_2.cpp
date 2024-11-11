#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const ll inf = ll(1e18);
const double PI = acos(-1), eps = 1e-9;
const int mxn = 7e3, mxa = 1e5, mxk = 2e3;
int n;
pair<ll, int> a[mxn];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first;
  for (int i = 0; i < n; ++i) cin >> a[i].second;
  sort(a, a + n);
  ll ans = 0;
  vector<pair<ll, int>> vp;
  vector<ll> va;
  for (int i = 0; i < n;) {
    int cnt = 0;
    while (i < n && a[i].first == a[i - cnt].first) {
      ++i, ++cnt;
    }
    if (cnt == 1)
      vp.push_back({a[i - cnt].second, a[i - cnt].first});
    else {
      for (int j = i - cnt; j < i; ++j) ans += a[j].second;
      va.push_back(a[i - cnt].first);
    }
  }
  sort(vp.rbegin(), vp.rend());
  for (const auto &p : vp) {
    int i;
    for (i = 0; i < (int)(va).size(); ++i) {
      if ((va[i] & p.second) == p.second) break;
    }
    if (i < (int)(va).size()) {
      va.push_back(p.second);
      ans += p.first;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t-- > 0) solve();
}
