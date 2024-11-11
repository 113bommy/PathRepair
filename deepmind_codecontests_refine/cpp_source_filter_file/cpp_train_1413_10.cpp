#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, nxt, w;
} e[500010 << 1];
int n, a[500010], h[500010], cnt;
int size[500010], son[500010], pos[500010], dfn[500010], tim, dep[500010];
int f[(1 << 23) + 10], ans[500010];
void add(int u, int v, int w) {
  e[++cnt] = (edge){v, h[u], w};
  h[u] = cnt;
}
void Deal_first(int x, int fa) {
  dep[pos[dfn[x] = ++tim] = x] = dep[fa] + 1;
  size[x] = 1;
  for (int i = h[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    a[v] = a[x] ^ (1 << e[i].w);
    Deal_first(v, x);
    size[x] += size[v];
    if (size[v] > size[son[x]]) son[x] = v;
  }
}
void gets(int rt, int x) {
  ans[rt] = max(ans[rt], f[a[x]] + dep[x]);
  for (int i = 0; i < 22; i++)
    ans[rt] = max(ans[rt], f[a[x] ^ (1 << i)] + dep[x]);
}
void insert(int x) { f[a[x]] = max(f[a[x]], dep[x]); }
void clear(int x) {
  for (int i = dfn[x]; i <= dfn[x] + size[x] - 1; i++) f[a[i]] = -1000000000;
}
void dfs(int x, int fa, int flag) {
  for (int i = h[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || v == son[x]) continue;
    dfs(v, x, 0);
  }
  if (son[x]) dfs(son[x], x, 1);
  for (int i = h[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || v == son[x]) continue;
    for (int j = dfn[v]; j <= dfn[v] + size[v] - 1; j++) gets(x, pos[j]);
    for (int j = dfn[v]; j <= dfn[v] + size[v] - 1; j++) insert(pos[j]);
  }
  gets(x, x), insert(x);
  ans[x] -= dep[x] << 1;
  for (int i = h[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    ans[x] = max(ans[x], ans[v]);
  }
  if (!flag) clear(x);
}
int main() {
  scanf("%d", &n);
  char ch;
  for (int i = 2, fat; i <= n; i++)
    scanf("%d", &fat), cin >> ch, add(i, fat, ch - 'a'), add(fat, i, ch - 'a');
  Deal_first(1, 0);
  memset(f, -63, sizeof(f));
  dfs(1, 1, 1);
  for (int i = 1; i <= n; i++) printf("%d ", max(0, ans[i]));
  return 0;
}
