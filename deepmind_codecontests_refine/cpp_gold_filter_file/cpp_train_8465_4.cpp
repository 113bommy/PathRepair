#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int N = 2 * 1e6 + 10;
ll res;
ll po[N];
ll a[N], h[N];
map<ll, ll> mp;
vector<pair<ll, ll> > v;
void solve() {
  ll n, m, x, y;
  cin >> n >> m;
  po[0] = 1;
  for (int i = 1; i <= n; ++i) {
    po[i] = po[i - 1] * 3;
  }
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    h[x] += po[y];
    h[y] += po[x];
    v.push_back({x, y});
  }
  for (auto i : v) {
    res += (h[i.first] + po[i.first] == h[i.second] + po[i.second]);
  }
  for (int i = 1; i <= n; ++i) ++mp[h[i]];
  for (auto i : mp) {
    res += (i.second - 1) * i.second / 2;
  }
  cout << res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  while (t--) {
    solve();
  }
}
