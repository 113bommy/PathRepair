#include <bits/stdc++.h>
const int N = 50005, B = 256;
int n, q, a[N], x, y, f[N][B], max[N][B], dep[N], fa[N], tot, top[N], vis[B];
struct twt {
  int son[2];
} t[1 << 10];
std::vector<int> g[N];
void ckmax(int &x, int y) { x = std::max(x, y); }
void Insert(int x) {
  int u = 0;
  for (int i = 7; i >= 0; i--) {
    if (!t[u].son[(x >> i) & 1])
      t[u].son[(x >> i) & 1] = ++tot, t[tot] = (twt){{0, 0}};
    u = t[u].son[(x >> i) & 1];
  }
}
int Query(int x, int u) {
  int v = 0, an = 0, now = 0;
  for (int i = 7; i >= 0; i--) {
    int d = ((x >> i) & 1) ^ 1;
    if (t[now].son[d])
      now = t[now].son[d], an |= 1 << i;
    else
      now = t[now].son[d ^ 1];
    v |= d << i;
  }
  return an << 8 | max[u][v];
}
void dfs(int u, int par, int d) {
  dep[u] = d, fa[u] = par;
  if (dep[u] >= B) {
    tot = 0, t[0] = (twt){{0, 0}};
    int i = u;
    for (; dep[u] - dep[i] < B; i = fa[i]) {
      ckmax(max[u][a[i] >> 8], ((dep[u] - dep[i]) ^ a[i]) & 255);
      if (vis[a[i] >> 8] != u) Insert(a[i] >> 8), vis[a[i] >> 8] = u;
    }
    top[u] = i;
    for (int i = 0; i < B; i++) f[u][i] = Query(i, u);
  }
  for (int i = 0; i < (signed)g[u].size(); i++) {
    int v = g[u][i];
    if (v == par) continue;
    dfs(v, u, d + 1);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++)
    scanf("%d%d", &x, &y), g[x].push_back(y), g[y].push_back(x);
  dfs(1, 0, 1);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    int dis = 0, ans = 0;
    for (; dep[y] - dep[x] >= B; y = top[y], dis++) ckmax(ans, f[y][dis]);
    for (dis <<= 8; y != fa[x]; y = fa[y], dis++) ckmax(ans, a[y] ^ dis);
    printf("%d\n", ans);
  }
  return 0;
}
