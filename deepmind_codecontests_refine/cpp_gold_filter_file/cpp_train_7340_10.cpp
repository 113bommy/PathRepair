#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge {
  int to, nxt;
} e[N << 1];
bool vis[N];
int h[N], tot, p[N][17], dfn[N], d[N], idx, ky[N], s[N], top, ans;
bool cmp(int a, int b) { return dfn[a] < dfn[b]; }
inline void add(int a, int b) {
  e[++tot].to = b;
  e[tot].nxt = h[a];
  h[a] = tot;
}
void dfs1(int u, int pre) {
  p[u][0] = pre;
  dfn[u] = ++idx;
  d[u] = d[pre] + 1;
  for (register int i = 1; i <= 16; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == pre) continue;
    dfs1(v, u);
  }
}
int lca(int a, int b) {
  register int i;
  if (d[a] > d[b]) swap(a, b);
  for (i = 16; i >= 0; --i)
    if (d[a] <= d[b] - (1 << i)) b = p[b][i];
  if (a == b) return a;
  for (i = 16; i >= 0; --i)
    if (p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  return p[a][0];
}
bool dfs2(int u, int pre) {
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == pre) continue;
    if (!dfs2(v, u) || (vis[v] && vis[u] && p[v][0] == u)) return false;
  }
  return true;
}
void dfs3(int u, int pre) {
  int cnt = 0;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == pre) continue;
    dfs3(v, u);
    if (vis[v]) ++cnt;
  }
  if (!vis[u])
    (cnt ^ 1) && cnt ? ++ans : vis[u] = cnt;
  else
    ans += cnt;
  h[u] = 0;
}
void insert(int x) {
  vis[x] = true;
  if (!top) {
    s[++top] = x;
    return;
  }
  int LCA = lca(x, s[top]);
  while (d[s[top - 1]] > d[LCA]) add(s[top - 1], s[top]), --top;
  if (d[s[top]] > d[LCA]) add(LCA, s[top--]);
  if (s[top] != LCA) s[++top] = LCA, vis[LCA] = false;
  s[++top] = x;
}
int main() {
  int n, a, b, T, m;
  register int i;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  dfs1(1, 0);
  scanf("%d", &T);
  memset(h, 0, sizeof h);
  while (T--) {
    tot = top = ans = 0;
    scanf("%d", &m);
    for (i = 1; i <= m; ++i) scanf("%d", &ky[i]);
    sort(ky + 1, ky + m + 1, cmp);
    if (ky[1] != 1) s[++top] = 1, vis[1] = false;
    for (i = 1; i <= m; ++i) insert(ky[i]);
    while (top > 1) add(s[top - 1], s[top]), --top;
    bool flag = dfs2(1, 0);
    dfs3(1, 0);
    if (flag)
      printf("%d\n", ans);
    else
      printf("-1\n");
  }
  return 0;
}
