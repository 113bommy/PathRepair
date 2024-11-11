#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5;
vector<pair<int, ll>> gr[N];
vector<ll> cost;
int n, m;
void add_edge(int a, int b, ll w) {
  gr[a].emplace_back(b, w);
  gr[b].emplace_back(a, w);
}
void Solve() {
  cin >> n >> m;
  for (int i = 0, a, b, w; i < m; i++) {
    cin >> a >> b >> w;
    add_edge(a, b, w);
  }
  cost.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> cost[i];
  set<pair<ll, int>> q;
  for (int i = 1; i <= n; i++) q.emplace(cost[i], i);
  while (q.size()) {
    auto [val, id] = *q.begin();
    q.erase(q.begin());
    for (auto [u, w] : gr[id]) {
      if (cost[u] > val + (w << 1)) {
        q.erase({cost[u], u});
        cost[u] = val + (w << 1);
        q.emplace(cost[u], u);
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << cost[i] << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
