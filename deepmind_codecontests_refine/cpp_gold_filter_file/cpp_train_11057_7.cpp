#include <bits/stdc++.h>
using namespace std;
template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
int n;
vector<vector<pair<int, int>>> g;
vector<int> ssz;
long long dfs1(int x, int p = -1) {
  ssz[x] = 1;
  long long cost = 0;
  for (auto [y, wei] : g[x]) {
    if (y == p) continue;
    cost += dfs1(y, x);
    ssz[x] += ssz[y];
    if (ssz[y] & 1) {
      cost += wei;
    }
  }
  return cost;
}
long long get_lo() { return dfs1(0); }
long long dfs2(int x, int p = -1) {
  long long cost = 0;
  for (auto [y, wei] : g[x]) {
    if (y == p) continue;
    cost += dfs2(y, x);
    cost += wei * 1ll * min(ssz[y], 2 * n - ssz[y]);
  }
  return cost;
}
long long get_hi() { return dfs2(0); }
void solve() {
  cin >> n;
  g.assign(2 * n, {});
  ssz.assign(2 * n, 0);
  for (int i = 0; i < 2 * n - 1; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    --a;
    --b;
    g[a].push_back({b, t});
    g[b].push_back({a, t});
  }
  cout << get_lo() << " " << get_hi() << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
