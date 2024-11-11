#include <bits/stdc++.h>
using namespace std;
const int N = 15005;
struct edge {
  int to, next;
} e[N * 2];
int fa[N], dep[N], q[N * 2], vis[N];
int n, m, tot, head[N], sz[N], S[N * 2];
int f[N], g[N], F[N * 2], ans;
void add(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
}
void dfs(int x) {
  dep[x] = dep[fa[x]] + 1;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa[x])
      if (!dep[e[i].to]) {
        fa[e[i].to] = x;
        dfs(e[i].to);
      } else if (dep[e[i].to] < dep[x]) {
        q[++*q] = x;
        for (int y = x; y != e[i].to; y = fa[y]) q[++*q] = fa[y];
      }
}
void dfs2(int x, int fa) {
  sz[x] = 1;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa && !vis[e[i].to]) {
      dfs2(e[i].to, x);
      sz[x] += sz[e[i].to];
      f[x] += f[e[i].to];
    }
  g[x] = n + f[x];
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa && !vis[e[i].to])
      g[x] = max(g[x], f[x] + (n - sz[e[i].to]) - f[e[i].to] + g[e[i].to]);
  f[x] += sz[x];
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(++x, ++y);
    add(y, x);
  }
  dfs(1);
  m = *q;
  for (int i = (int)(1); i <= (int)(m); i++) vis[q[i]] = 1;
  for (int i = (int)(1); i <= (int)(m); i++) dfs2(q[i], 0);
  for (int i = (int)(1); i <= (int)(m); i++) q[i + m] = q[i];
  for (int i = (int)(1); i <= (int)(2 * m); i++) S[i] = S[i - 1] + sz[q[i]];
  for (int i = (int)(1); i <= (int)(2 * m); i++) F[i] = f[q[i]];
  for (int l = (int)(1); l <= (int)(m - 2); l++) {
    for (int i = (int)(1); i <= (int)(2 * m - l + 1); i++)
      F[i] += S[i + l - 1] - S[i - 1];
    for (int i = (int)(1); i <= (int)(2 * m - l); i++)
      F[i] = max(F[i] + f[q[i + l]], F[i + 1] + f[q[i]]);
  }
  for (int i = (int)(1); i <= (int)(m); i++) ans = max(ans, F[i + 1] + g[q[i]]);
  printf("%d\n", ans);
}
