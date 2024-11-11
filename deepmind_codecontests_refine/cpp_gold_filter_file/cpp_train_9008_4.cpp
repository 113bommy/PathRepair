#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, x, sz[N];
int Edgecnt, head[N], nxt[2 * N], to[2 * N];
double f[N];
void add(int u, int v) {
  to[++Edgecnt] = v;
  nxt[Edgecnt] = head[u];
  head[u] = Edgecnt;
}
void dfs1(int x, int fa) {
  sz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs1(y, x);
    sz[x] += sz[y];
  }
}
void dfs2(int x, int fa) {
  if (fa != 0) f[x] = f[fa] + 1 + (sz[fa] - sz[x] - 1) * 0.5;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs2(y, x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &x);
    add(i, x);
    add(x, i);
  }
  f[1] = 1;
  dfs1(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) printf("%.1lf ", f[i]);
  return 0;
}
