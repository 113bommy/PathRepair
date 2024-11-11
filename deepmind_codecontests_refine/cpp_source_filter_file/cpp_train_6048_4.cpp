#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
struct Edge {
  int to;
  int64 cost;
  Edge() {}
  Edge(int to, int64 cost) : to{to}, cost{cost} {}
};
const int MAX_N = 300005;
vector<Edge> F[MAX_N];
int64 distFromS[MAX_N], distFromT[MAX_N];
void dfs(int v, int64 d, int64* dist) {
  dist[v] = d;
  for (auto& e : F[v]) {
    if (dist[e.to] >= 0) continue;
    dfs(e.to, d + e.cost, dist);
  }
}
void calcDistance(int s, int t) {
  memset(distFromS, -1, sizeof(distFromS));
  memset(distFromT, -1, sizeof(distFromT));
  dfs(s, 0, distFromS);
  dfs(t, 0, distFromT);
}
pair<int, int> findProfitablePair(int s, int t) {
  int n = t + 1;
  calcDistance(s, t);
  vector<pair<int64, int>> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i] = make_pair(distFromS[i] - distFromT[i], i);
  }
  sort(nodes.begin(), nodes.end());
  int u, v;
  int64 d = 0;
  set<pair<int64, int>> partners;
  for (int i = n - 1; i >= 0; i--) {
    int id = nodes[i].second;
    vector<pair<int64, int>> pool;
    for (auto& e : F[id]) {
      auto p = make_pair(distFromT[e.to], e.to);
      if (partners.count(p)) {
        partners.erase(p);
        pool.push_back(p);
      }
    }
    if (!partners.empty() and distFromS[id] + partners.rbegin()->first > d) {
      u = id;
      v = partners.rbegin()->second;
      d = distFromS[id] + partners.rbegin()->first;
    }
    partners.insert(make_pair(distFromT[id], id));
    while (!pool.empty()) {
      partners.insert(pool.back());
      pool.pop_back();
    }
  }
  return make_pair(u, v);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    F[u].emplace_back(v, w);
    F[v].emplace_back(u, w);
  }
  int s = 0, t = n - 1;
  auto res = findProfitablePair(s, t);
  for (int i = 0; i < m; i++) {
    int64 x;
    cin >> x;
    cout << min({distFromS[t],
                 distFromS[res.first] + distFromT[res.second] + x})
         << '\n';
  }
  return 0;
}
