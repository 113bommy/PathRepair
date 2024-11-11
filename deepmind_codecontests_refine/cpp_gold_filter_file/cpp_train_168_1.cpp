#include <bits/stdc++.h>
using namespace std;
struct Scc {
  int n, nScc, vst[100005], bln[100005];
  vector<int> E[100005], rE[100005], vec;
  void init(int _n) {
    n = _n;
    for (int i = 0; i < 100005; i++) {
      E[i].clear();
      rE[i].clear();
    }
  }
  void add_edge(int u, int v) {
    E[u].push_back(v);
    rE[v].push_back(u);
  }
  void DFS(int u) {
    vst[u] = 1;
    for (auto v : E[u])
      if (!vst[v]) DFS(v);
    vec.push_back(u);
  }
  void rDFS(int u) {
    vst[u] = 1;
    bln[u] = nScc;
    for (auto v : rE[u])
      if (!vst[v]) rDFS(v);
  }
  void solve() {
    nScc = 0;
    vec.clear();
    memset(vst, 0, sizeof(vst));
    for (int i = 1; i <= n; i++)
      if (!vst[i]) DFS(i);
    reverse(vec.begin(), vec.end());
    memset(vst, 0, sizeof(vst));
    for (auto v : vec) {
      if (!vst[v]) {
        rDFS(v);
        nScc++;
      }
    }
  }
} graph;
int u[100005], siz[100005], out[100005];
int main() {
  int n, m, h, fr, to;
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &u[i]);
  }
  graph.init(n);
  while (m--) {
    scanf("%d%d", &fr, &to);
    if ((u[fr] + 1) % h == u[to]) graph.add_edge(fr, to);
    if ((u[to] + 1) % h == u[fr]) graph.add_edge(to, fr);
  }
  graph.solve();
  for (int i = 1; i <= n; i++) {
    siz[graph.bln[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (auto j : graph.E[i]) {
      if (graph.bln[j] != graph.bln[i]) out[graph.bln[i]]++;
    }
  }
  int ans = 1e9, id;
  for (int i = 0; i < graph.nScc; i++) {
    if (out[i]) continue;
    if (siz[i] < ans) {
      id = i;
      ans = siz[i];
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (graph.bln[i] == id) printf("%d ", i);
  }
  puts("");
}
