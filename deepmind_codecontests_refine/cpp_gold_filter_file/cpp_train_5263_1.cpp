#include <bits/stdc++.h>
using namespace std;
struct lca {
  int L, N;
  vector<int> depth, size, link;
  lca() {}
  lca(const vector<vector<int> >& graph, int root = 0) {
    N = graph.size();
    for (L = 0; (1 << L) <= N; L++)
      ;
    depth.resize(N);
    size.resize(N);
    link.resize(L * N);
    init(root, root, graph);
  }
  void init(int loc, int par, const vector<vector<int> >& graph) {
    link[loc] = par;
    for (int l = 1; l < L; l++)
      link[l * N + loc] = link[(l - 1) * N + link[(l - 1) * N + loc]];
    for (int nbr : graph[loc]) {
      if (nbr == par) continue;
      depth[nbr] = depth[loc] + 1;
      init(nbr, loc, graph);
      size[loc] += size[nbr];
    }
    size[loc]++;
  }
  int above(int loc, int dist) {
    for (int l = 0; l < L; l++)
      if ((dist >> l) & 1) loc = link[l * N + loc];
    return loc;
  }
  int find(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = above(v, depth[v] - depth[u]);
    if (u == v) return u;
    for (int l = L - 1; l >= 0; l--) {
      if (link[l * N + u] != link[l * N + v])
        u = link[l * N + u], v = link[l * N + v];
    }
    return link[u];
  }
  int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[find(u, v)]; }
};
void dfs(int v, vector<vector<int> >& E, vector<int>& visited,
         vector<int>& vertices, vector<int>& isU) {
  visited[v] = 1;
  for (int x : E[v])
    if (!visited[x]) dfs(x, E, visited, vertices, isU);
  if (isU[v]) vertices.push_back(v);
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> U(2 * k);
  for (int i = (0); i < (2 * k); ++i) {
    cin >> U[i];
    U[i]--;
  }
  vector<vector<int> > E(n);
  vector<int> isU(n);
  for (int i = (0); i < (2 * k); ++i) isU[U[i]] = 1;
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  lca LCA(E);
  vector<int> visited(n), vertices;
  dfs(0, E, visited, vertices, isU);
  long long ans = 0;
  for (int i = (0); i < (k); ++i) {
    int dist = LCA.dist(vertices[i], vertices[i + k]);
    ans += dist;
  }
  cout << ans;
  return 0;
}
