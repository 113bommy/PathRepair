#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long ans[maxn], cnt[maxn], now, maxi;
int n, son[maxn], col[maxn], size[maxn];
int ver[maxn << 1], head[maxn], nxt[maxn << 1], tot;
void add(int u, int v) {
  ver[++tot] = v;
  nxt[tot] = head[u];
  head[u] = tot;
}
void dfs1(int x, int fa) {
  size[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y != fa) {
      dfs1(y, x);
      size[x] += size[y];
      if (size[y] > size[son[x]]) son[x] = y;
    }
  }
}
void dfs2(int x, int fa, int large) {
  cnt[col[x]]++;
  if (cnt[col[x]] == maxi) now += col[x];
  if (cnt[col[x]] > maxi) maxi = cnt[col[x]], now = col[x];
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y != fa && y != large) dfs2(y, x, large);
  }
}
void cls(int x, int fa) {
  cnt[col[x]]--;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y != fa) cls(y, x);
  }
}
void dsu(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y != fa && y != son[x]) {
      dsu(y, x);
      cls(y, x);
      now = 0, maxi = 0;
    }
  }
  if (son[x]) dsu(son[x], x);
  dfs2(x, fa, son[x]);
  ans[x] = now;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    add(x, y), add(y, x);
  }
  dfs1(1, 0);
  dsu(1, 0);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
