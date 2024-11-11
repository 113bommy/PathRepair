#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
int N, M, root, d[MN], p[MN], h[MN], mark[MN], good[MN];
vector<int> adj[MN];
queue<int> q;
inline bool have_3k_vertex() {
  for (int u = 0; u < N; ++u)
    if (d[u] % 3 < 1 && N > 1) return good[u] = true;
  return false;
}
inline bool dfs1(int u) {
  int mx = -1;
  mark[u] = true;
  for (int v : adj[u])
    if (mark[v] && h[v] < h[u] - 1 && (!~mx || h[v] > h[mx])) mx = v;
  if (~mx && h[u] - h[mx] + 1 < N && h[mx] % 3 > 1) {
    for (; u ^ p[mx]; u = p[u]) good[u] = true;
    return true;
  }
  for (int v : adj[u])
    if (!mark[v]) {
      h[v] = h[p[v] = u] + 1;
      if (dfs1(v)) return true;
    }
  return false;
}
inline bool have_121_path() {
  for (p[root] = -1, mark[root] = true, q.push(root); !q.empty(); q.pop()) {
    int u = q.front();
    if (u ^ root && d[u] % 3 == 1 && h[u] < N - 1) {
      for (; ~u; good[u] = true, u = p[u])
        ;
      for (; !q.empty(); q.pop())
        ;
      return true;
    }
    for (int v : adj[u])
      if (!mark[v]) q.push(v), mark[v] = true, h[v] = h[p[v] = u] + 1;
  }
  return false;
}
inline void dfs2(int u) {
  mark[u] = true;
  for (int v : adj[u])
    if (!mark[v]) dfs2(v);
  return;
}
inline bool have_2_cycle() {
  return p[root < N ? root : 0] = -1, fill(mark, mark + N, false),
                             dfs1(root < N ? root : 0);
}
inline bool have_122_components() {
  bool flag = false;
  fill(mark, mark + N, false), mark[root] = good[root] = true,
                               sort(adj[root].begin(), adj[root].end(),
                                    [](int u, int v) { return h[u] < h[v]; });
  for (int u : adj[root])
    if (!mark[u] && h[u] > 1) {
      int v = u;
      for (good[u] = true; p[v] ^ root; good[v = p[v]] = true)
        ;
      if (flag) break;
      dfs2(v), flag = true;
    }
  return true;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      adj[u].emplace_back(v), adj[v].emplace_back(u);
      ++d[u], ++d[v];
    }
    for (root = 0; root < N && d[root] % 3 ^ 1; ++root)
      ;
    if (have_3k_vertex() || (root < N && have_121_path()) || have_2_cycle() ||
        (root < N && d[root] > 4 && have_122_components())) {
      vector<int> vec;
      for (int i = 0; i < N; ++i)
        if (!good[i]) vec.emplace_back(i);
      printf("Yes\n%d\n", vec.size());
      for (auto x : vec) printf("%d ", x + 1);
      printf("\n");
    } else
      printf("No\n");
    for (int u = 0; u < N; ++u)
      d[u] = h[u] = 0, adj[u].clear(), mark[u] = good[u] = false;
  }
  return 0;
}
