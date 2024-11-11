#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 3e5 + 11;
int fa[MAXN][21], dep[MAXN], dfn[MAXN], N, Fa[MAXN];
vector<int> vec1[MAXN], vec2[MAXN];
void dfs(int u, int fath) {
  dep[u] = dep[fath] + 1;
  fa[u][0] = fath;
  for (int i = 1; (1 << i) <= dep[u]; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (auto v : vec1[u])
    if (v != fath) dfs(v, u);
  return;
}
void dfs1(int u, int fath) {
  dfn[++dfn[0]] = u;
  Fa[u] = fath;
  for (auto v : vec2[u])
    if (v != fath) dfs1(v, u);
}
struct Union {
  int f[MAXN];
  void init() {
    for (int i = 1; i <= N; i++) f[i] = i;
    return;
  }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void del(int x) {
    f[x] = fa[x][0];
    return;
  }
} U;
int Lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 20; i >= 0; i--)
    if (dep[u] - (1 << i) >= dep[v]) u = fa[u][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
int main() {
  N = read();
  for (int i = 1; i < N; i++) {
    int u = read(), v = read();
    vec1[u].push_back(v), vec1[v].push_back(u);
  }
  for (int i = 1; i < N; i++) {
    int u = read(), v = read();
    vec2[u].push_back(v), vec2[v].push_back(u);
  }
  dfs(1, 0);
  dfs1(1, 0);
  U.init();
  printf("%d\n", N - 1);
  for (int i = N; i > 1; i--) {
    int u = dfn[i], v = Fa[u], p = Lca(u, v), pp = U.find(u);
    if (dep[pp] > dep[p]) {
      printf("%d %d %d %d\n", pp, fa[pp][0], u, v);
      U.del(pp);
      continue;
    }
    int V = v;
    for (int j = 20; j >= 0; j--)
      if (U.find(fa[V][j]) > dep[p]) V = fa[V][j];
    printf("%d %d %d %d\n", V, fa[V][0], u, v);
    U.del(V);
  }
  return 0;
}
