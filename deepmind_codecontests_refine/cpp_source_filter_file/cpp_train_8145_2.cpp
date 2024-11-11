#include <bits/stdc++.h>
int N, TC, gu, gv;
std::vector<int> E[100001];
int q[100001], dep[100001], fa[100001], f[100001], g[100001];
int J[17][100001], LOG;
void BFS() {
  int H = 0, T = 1;
  q[1] = 1;
  dep[1] = 0;
  while (H < T) {
    int u = q[++H];
    for (int v : E[u])
      if (v != fa[u]) {
        fa[q[++T] = v] = u;
        dep[v] = dep[u] + 1;
      }
  }
  for (int i = N; i; i--) {
    int u = q[i];
    f[u] = 0;
    for (int v : E[u])
      if (v != fa[u]) f[u] = std::max(f[u], f[v] + 1);
  }
  g[1] = -1;
  for (int i = 1; i <= N; i++) {
    int u = q[i];
    int M1 = g[u], M2 = -1000000000;
    for (int v : E[u])
      if (v != fa[u]) {
        if (f[v] > M1)
          M2 = M1, M1 = f[v];
        else if (f[v] > M2)
          M2 = f[v];
      }
    for (int v : E[u])
      if (v != fa[u]) g[v] = (f[v] == M1 ? M2 : M1) + 1;
  }
  for (int i = 1; i <= N; i++) J[0][i] = fa[i];
  LOG = 0;
  while (2 << LOG < N) LOG++;
  for (int i = 1; i <= LOG; i++)
    for (int j = 1; j <= N; j++) J[i][j] = J[i - 1][J[i - 1][j]];
}
int jump(int x, int y) {
  for (int i = 0; i <= LOG; i++)
    if (y >> i & 1) x = J[i][x];
  return x;
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = LOG; i >= 0; i--)
    if (dep[x] - dep[y] >= 1 << i) x = J[i][x];
  if (x == y) return x;
  for (int i = LOG; i >= 0; i--)
    if (J[i][x] != J[i][y]) {
      x = J[i][x];
      y = J[i][y];
    }
  return fa[x];
}
int DIS(int u, int v) { return dep[u] + dep[v] - dep[LCA(u, v)] * 2; }
int toward(int x, int y, int d) {
  int lca = LCA(x, y);
  if (dep[x] - dep[lca] < d)
    return jump(y, dep[y] - dep[lca] - (dep[x] - dep[lca] - d));
  else
    return jump(x, d);
}
int in_subtree(int x, int y) {
  int lca = LCA(x, y);
  if (x == lca) {
    int near = jump(y, dep[y] - dep[x] - 1);
    return g[near];
  } else
    return f[x];
}
int main() {
  for (scanf("%d", &TC); TC--;) {
    scanf("%d%d%d", &N, &gu, &gv);
    for (int i = 1; i <= N; i++) E[i].clear();
    for (int i = 1, u, v; i < N; i++) {
      scanf("%d%d", &u, &v);
      E[u].push_back(v);
      E[v].push_back(u);
    }
    BFS();
    int LEN = DIS(gu, gv);
    int du = 0, tu = gu, dv = 0, tv = gv;
    bool FULL = false;
    for (int T = N * 2; T--;) {
      dv = in_subtree(tu, gv) - du;
      if (du + dv >= LEN) {
        FULL = true;
        break;
      }
      tv = toward(gv, gu, dv);
      du = in_subtree(tv, gu) - dv;
      if (du + dv >= LEN) {
        FULL = true;
        break;
      }
      tu = toward(gu, gv, du);
    }
    bool ok = false;
    if (FULL)
      for (int i = 1; i <= N; i++) {
        int c = i > 1 ? (g[i] + 1 >= LEN) : 0;
        for (int v : E[i])
          if (v != fa[i] && f[v] + 1 >= LEN) c++;
        if (c >= 3) {
          ok = true;
          break;
        }
      }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
