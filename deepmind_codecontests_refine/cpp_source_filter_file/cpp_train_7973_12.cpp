#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 2e5 + 5;
const int MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n;
bool check(ll num_edges) {
  ll num_bridges = (num_edges + 1) / 2;
  ll rem_vertices = n - num_bridges;
  ll rem_edges = rem_vertices * (rem_vertices - 1) / 2;
  return rem_vertices >= 0 && rem_edges + num_bridges >= num_edges;
}
void solve() {
  cin >> n;
  ll l = 1, r = 1e18;
  ll ans = -1;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
