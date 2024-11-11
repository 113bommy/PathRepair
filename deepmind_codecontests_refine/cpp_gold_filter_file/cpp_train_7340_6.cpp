#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct edge {
  int next, to;
} e[maxn * 2], w[maxn * 2];
int h[maxn], g[maxn], cnt, cnt2, n, m, pos, f[maxn][18], lg2[maxn], d[maxn],
    p[maxn], st[maxn], top, zc[maxn], zcnt;
bool book[maxn];
bool cmp(int x, int y) { return p[x] < p[y]; }
void addedge(int x, int y) {
  e[++cnt].next = h[x];
  e[cnt].to = y;
  h[x] = cnt;
}
void addedge2(int x, int y) {
  w[++cnt2].next = g[x];
  w[cnt2].to = y;
  g[x] = cnt2;
}
void dfs(int u, int fa) {
  f[u][0] = fa, d[u] = d[fa] + 1, p[u] = ++pos;
  for (register int i = 1; i <= lg2[d[u]]; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (register int i = h[u]; i; i = e[i].next) {
    int j = e[i].to;
    if (j == fa) continue;
    dfs(j, u);
  }
}
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  while (d[x] > d[y]) x = f[x][lg2[d[x] - d[y]] - 1];
  if (x == y) return x;
  for (register int i = lg2[d[x]] - 1; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
pair<int, bool> dp(int u) {
  int sum = 0, pd = 0;
  for (register int i = g[u]; i; i = w[i].next) {
    pair<int, bool> p = dp(w[i].to);
    sum += p.first, pd += p.second;
  }
  g[u] = 0;
  return book[u] ? pair<int, bool>(sum + pd, 1)
                 : (pd <= 1 ? pair<int, bool>(sum, pd)
                            : pair<int, bool>(sum + 1, 0));
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++)
    lg2[i] = lg2[i - 1] + ((1 << lg2[i - 1]) == i);
  for (register int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
  dfs(1, 0);
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &y);
    for (register int i = 1; i <= y; i++) scanf("%d", &zc[i]), book[zc[i]] = 1;
    for (register int i = 1; i <= y; i++)
      if (book[f[zc[i]][0]]) {
        puts("-1");
        goto shik;
      }
    sort(zc + 1, zc + y + 1, cmp);
    st[top = 1] = zc[1], cnt2 = 0;
    for (register int i = 2; i <= y; i++) {
      int lc = lca(st[top], zc[i]);
      while (top) {
        if (d[lc] >= d[st[top - 1]]) {
          if (lc != st[top]) {
            addedge2(lc, st[top]);
            lc != st[top - 1] ? st[top] = lc : top--;
          }
          break;
        }
        addedge2(st[top - 1], st[top]);
        top--;
      }
      st[++top] = zc[i];
    }
    while (--top) addedge2(st[top], st[top + 1]);
    printf("%d\n", dp(st[1]).first);
  shik:
    for (register int i = 1; i <= y; i++) book[zc[i]] = 0;
  }
  return 0;
}
