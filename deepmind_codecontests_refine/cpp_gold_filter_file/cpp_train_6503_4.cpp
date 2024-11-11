#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int w, after;
  Edge(int w) : w(w) { after = 0; }
};
const int MAX = 2e5 + 5;
int n, x, y, w, m;
bool visited[MAX];
vector<pair<int, int> > adj[MAX];
vector<Edge> edges;
double ans = 0;
int dfs(int u) {
  visited[u] = true;
  int c = 1;
  for (const auto &v : adj[u]) {
    auto &e = edges[v.second];
    if (!visited[v.first]) {
      e.after = dfs(v.first);
      c += e.after;
    }
  }
  return c;
}
double cost(Edge &e) {
  double x = e.after;
  return (x * (n - x) * e.w * 6);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  edges.push_back(Edge(0));
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y >> w;
    adj[x].push_back({y, i});
    adj[y].push_back({x, i});
    edges.push_back(Edge(w));
  }
  dfs(1);
  for (int i = 1; i < n; i++) ans += cost(edges[i]);
  cin >> m;
  while (m--) {
    cin >> x >> w;
    ans -= cost(edges[x]);
    edges[x].w = w;
    ans += cost(edges[x]);
    cout << fixed << setprecision(12) << (ans / (n * (n - 1ll))) << "\n";
  }
  return 0;
}
