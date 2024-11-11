#include <bits/stdc++.h>
using namespace std;
const int maxn = 500300;
int n, m, head[maxn], to[maxn], nxt[maxn], root, cnt;
int N[maxn], T[maxn], H[maxn], Cnt, A, B;
int pass[maxn], ans_id = maxn, ans, tot, f[maxn];
bool vis[maxn];
inline void add_edge(int x, int y) {
  nxt[++cnt] = head[x], to[cnt] = y, head[x] = cnt;
  nxt[++cnt] = head[y], to[cnt] = x, head[y] = cnt;
}
inline void add_edge_new(int x, int y) {
  N[++Cnt] = H[x], T[Cnt] = y, H[x] = Cnt;
}
inline void dfs(int u, int fa) {
  if (vis[u]) pass[u]++;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    dfs(v, u);
    pass[u] += pass[v];
  }
}
inline void Dfs1(int u, int fa, int dep) {
  tot++;
  if (dep > ans)
    ans = dep, B = u;
  else if (dep == ans)
    B = min(B, u);
  for (int i = H[u]; i; i = N[i]) {
    int v = T[i];
    if (v == fa) continue;
    Dfs1(v, u, dep + 1);
  }
}
inline void Dfs2(int u, int fa, int dep) {
  if (dep > ans)
    ans = dep, B = u;
  else if (dep == ans)
    B = min(B, u);
  for (int i = H[u]; i; i = N[i]) {
    int v = T[i];
    if (v == fa) continue;
    Dfs2(v, u, dep + 1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    vis[x] = 1;
    root = x;
  }
  dfs(root, 0);
  for (int i = 1; i <= n; i++) {
    if (pass[i] == 0) continue;
    for (int j = head[i]; j; j = nxt[j]) {
      if (pass[to[j]] == 0) continue;
      add_edge_new(i, to[j]);
    }
  }
  A = root;
  Dfs1(A, 0, 0);
  A = B;
  Dfs2(A, 0, 0);
  ans_id = min(A, B);
  printf("%d\n%d\n", ans_id, tot - 2 + (tot - ans));
  return 0;
}
