#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  long long f = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
long long fa[200005][21], lg[200005], deep[200005], dis[200005], w[200005],
    t[200005], h[200005], head, n, ans[200005];
struct yyy {
  long long to, z, w;
  inline void add(long long x, long long y, long long W) {
    to = y;
    z = h[x];
    h[x] = head;
    w = W;
  }
} a[200005 * 2];
inline void dfs2(long long x, long long pre) {
  register long long i;
  deep[x] = deep[pre] + 1;
  fa[x][0] = pre;
  for (i = 1; i <= lg[deep[x]]; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (i = h[x]; i; i = a[i].z)
    if (a[i].to != pre) dis[a[i].to] = dis[x] + a[i].w, dfs2(a[i].to, x);
}
inline void dfs(long long x, long long pre) {
  register long long i;
  for (i = h[x]; i; i = a[i].z)
    if (a[i].to ^ pre) {
      dfs(a[i].to, x);
      t[x] += t[a[i].to];
    }
}
inline void init() {
  register long long i, j, k;
  for (j = 1, k = 1; j <= n; j <<= 1, k++)
    for (i = j; i < j * 2; i++) lg[i] = k;
  dfs2(1, 0);
}
signed main() {
  register long long i, j, x, y;
  read(n);
  for (i = 1; i <= n; i++) read(w[i]);
  for (i = 2; i <= n; i++) {
    read(x);
    read(y);
    a[++head].add(i, x, y);
    a[++head].add(x, i, y);
  }
  init();
  for (i = 2; i <= n; i++) {
    x = i;
    for (j = lg[deep[i]]; j >= 0; j--)
      if (fa[x][j] && dis[i] - dis[fa[x][j]] <= w[i]) x = fa[x][j];
    t[fa[x][0]]--;
    t[fa[i][0]]++;
  }
  dfs(1, 0);
  for (i = 1; i <= n; i++) printf("%lld ", t[i]);
  return 0;
}
