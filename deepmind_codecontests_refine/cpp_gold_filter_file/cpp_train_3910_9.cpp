#include <bits/stdc++.h>
inline int F() {
  register int aa, bb, ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while (ch = getchar(), ch >= '0' && ch <= '9') aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
const int Maxn = 1000100;
int n, k, a[Maxn], cnt = 0, flag[Maxn], isroot[Maxn], f[Maxn], size[Maxn], root,
                   vis[Maxn], to[Maxn], next[Maxn], g[Maxn], ecnt = 0,
                   dep[Maxn];
long long ans;
void ins(int a, int b) {
  to[++ecnt] = b;
  next[ecnt] = g[a];
  g[a] = ecnt;
}
void dfs1(int x) {
  vis[x] = 1;
  size[x] = flag[x];
  isroot[x] = 1;
  for (int i = g[x]; i; i = next[i]) {
    if (vis[to[i]]) continue;
    dfs1(to[i]);
    if (size[to[i]] > k) isroot[x] = 0;
    size[x] += size[to[i]];
  }
  if (k > size[x]) isroot[x] = 0;
}
void dfs2(int x, int d) {
  vis[x] = 1;
  dep[x] = d + 1;
  if (flag[x]) ans += dep[x];
  for (int i = g[x]; i; i = next[i]) {
    if (vis[to[i]]) continue;
    dfs2(to[i], dep[x]);
  }
}
int main() {
  n = F();
  k = F();
  for (int i = 1; i <= k; ++i) {
    a[++cnt] = F();
    flag[a[cnt]] = 1;
    a[++cnt] = F();
    flag[a[cnt]] = 1;
  }
  for (int i = 1; i < n; ++i) {
    int t1 = F(), t2 = F();
    ins(t1, t2);
    ins(t2, t1);
  }
  dfs1(1);
  for (int i = 1; i <= n; ++i) {
    if (isroot[i]) {
      root = i;
      break;
    }
  }
  memset(vis, 0, sizeof(vis));
  dfs2(root, -1);
  printf("%I64d\n", ans);
}
