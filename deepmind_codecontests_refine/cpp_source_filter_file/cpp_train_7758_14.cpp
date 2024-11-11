#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
ostream& operator<<(ostream& os, const pair<X, Y>& p) {
  return os << "[" << p.first << ", " << p.second << "]";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  const Container& x) {
  os << "{";
  bool f = 1;
  for (auto& y : x) {
    if (!f)
      os << ", ";
    else
      f = 0;
    os << y;
  }
  return os << "}";
}
struct Debug {
  template <class T>
  Debug& operator<<(const T& x) {
    return *this;
  }
};
struct edge {
  int to, cap;
};
const int N = 55;
int dist[N], p[N], src, max_node, snk;
vector<edge> edges;
vector<int> network[N];
void addAugEdge(int u, int v, int c) {
  max_node = max(max_node, max(u, v));
  network[u].push_back(edges.size());
  edges.push_back({v, c});
  network[v].push_back(edges.size());
  edges.push_back({u, 0});
}
bool BFS() {
  memset(dist, -1, (max_node + 1) * sizeof dist[0]);
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  while (q.size()) {
    int cur = q.front();
    q.pop();
    for (int ci : network[cur]) {
      auto& e = edges[ci];
      if (dist[e.to] == -1 && e.cap) {
        q.push(e.to);
        dist[e.to] = dist[cur] + 1;
      }
    }
  }
  return max_node >= snk && dist[snk] != -1;
}
int DFS(int node, int flow) {
  if (node == snk || !flow) return flow;
  for (; p[node] < network[node].size(); p[node]++) {
    auto& e = edges[network[node][p[node]]];
    auto& re = edges[network[node][p[node]] ^ 1];
    if (dist[node] + 1 != dist[e.to]) continue;
    int push = DFS(e.to, min(flow, e.cap));
    if (push) {
      e.cap -= push;
      re.cap += push;
      return push;
    }
  }
  return 0;
}
long long dinic() {
  long long flow = 0;
  while (BFS()) {
    memset(p, 0, sizeof p);
    while (int f = DFS(src, 1e9)) flow += f;
  }
  return flow;
}
void init() {
  edges.clear();
  for (int i = 0; i <= max_node; i++) network[i].clear();
  max_node = 0;
}
vector<array<int, 3> > edgeList;
bool can(double v, int need) {
  init();
  for (auto& e : edgeList) addAugEdge(e[0], e[1], e[2] / v);
  return dinic() >= need;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    edgeList.push_back({u, v, c});
  }
  src = 1, snk = n;
  double l = 1e-7, r = 1e6 + 6;
  for (int it = 0; it < 500; it++) {
    double mid = (l + r) / 2;
    if (can(mid, x)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(12) << l * x;
}
