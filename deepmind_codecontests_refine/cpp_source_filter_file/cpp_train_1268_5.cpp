#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000007;
vector<long long> g[maxn];
vector<long long> gt[maxn];
vector<bool> used;
vector<long long> order, comp;
vector<bool> assignment;
void show_graph(long long n, const bool undirected = false) {
  ofstream os{"graph.dot"};
  os << (undirected ? "graph" : "digraph");
  os << " G {" << '\n';
  for (long long u = 0; u < n; ++u) {
    for (const auto v : g[u]) {
      if (!undirected || u <= v) {
        os << "\t" << u << (undirected ? " -- " : " -> ") << v << '\n';
      }
    }
  }
  os << "}" << '\n';
  system("dot -Tpng graph.dot -o graph.png && xdg-open graph.png");
}
void dfs1(long long v) {
  used[v] = true;
  for (long long u : g[v]) {
    if (!used[u]) dfs1(u);
  }
  order.push_back(v);
}
void dfs2(long long v, long long cl) {
  comp[v] = cl;
  for (long long u : gt[v]) {
    if (comp[u] == -1) dfs2(u, cl);
  }
}
bool solve_2SAT(long long n) {
  used.assign(n, false);
  for (long long i = 0; i < n; ++i) {
    if (!used[i]) dfs1(i);
  }
  comp.assign(n, -1);
  for (long long i = 0, j = 0; i < n; ++i) {
    long long v = order[n - i - 1];
    if (comp[v] == -1) dfs2(v, j++);
  }
  assignment.assign(n / 2, false);
  for (long long i = 0; i < n; i += 2) {
    if (comp[i] == comp[i + 1]) return false;
    assignment[i / 2] = comp[i] > comp[i + 1];
  }
  return true;
}
void add_edge(long long u, long long v, bool negU, bool negV) {
  g[(u * 2) + (negU ? 0 : 1)].push_back((v * 2) + (negV ? 1 : 0));
  gt[(v * 2) + (negV ? 1 : 0)].push_back((u * 2) + (negU ? 0 : 1));
  g[(v * 2) + (negV ? 0 : 1)].push_back((u * 2) + (negU ? 1 : 0));
  gt[(u * 2) + (negU ? 1 : 0)].push_back((v * 2) + (negV ? 0 : 1));
}
signed main() {
  long long t = 1, n, u, v, p, M, m, x, y, l, r;
  cin >> n >> p >> M >> m;
  long long N = p + M;
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    x--, y--;
    add_edge(x, y, 0, 0);
  }
  for (long long i = 0; i < M - 1; i++) {
    add_edge(p + i, p + i + 1, 0, 1);
  }
  for (long long i = 0; i < p; i++) {
    cin >> l >> r;
    add_edge(i, p + (l - 1), 1, 0);
    if (r < M) add_edge(i, p + r, 1, 1);
  }
  for (long long i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    add_edge(u, v, 1, 1);
  }
  if (!solve_2SAT(2 * N)) return cout << -1 << '\n', 0;
  vector<long long> ans;
  for (long long i = 0; i < p; i++)
    if (assignment[i]) ans.push_back(i + 1);
  long long i = 0;
  for (; i < M; i++)
    if (!assignment[p + i]) break;
  cout << ans.size() << " " << i + 1 << '\n';
  for (auto c : ans) cout << c << " ";
  cout << '\n';
  return 0;
}
