#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, M = 5e5 + 5;
bool vis[N];
int q[N], tot, fa[N];
int n, m, k, head[N], ne[M << 1], to[M << 1], cnt, d[N];
inline int read() {
  int x, f = 1;
  char ch;
  while (!(isdigit(ch = getchar()))) ch == '-' ? f = -1 : f;
  x = ch ^ 48;
  while ((isdigit(ch = getchar()))) x = (x << 1) + (x << 3) + (ch ^ 48);
  return f * x;
}
inline void ins(int x, int y) {
  ne[++cnt] = head[x];
  head[x] = cnt;
  to[cnt] = y;
}
inline void dfs(int x) {
  vis[x] = 1;
  if (d[x] >= (n + k - 1) / k) {
    puts("PATH");
    printf("%d\n", d[x]);
    while (x) printf("%d ", x), x = fa[x];
    exit(0);
  }
  bool pd = 0;
  for (int i = head[x]; i; i = ne[i]) {
    if (fa[x] == to[i] || vis[to[i]]) continue;
    fa[to[i]] = x;
    d[to[i]] = d[x] + 1;
    pd = 1;
    dfs(to[i]);
  }
  if (!pd) q[++tot] = x;
}
int main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    ins(x, y);
    ins(y, x);
  }
  d[1] = 1;
  dfs(1);
  puts("CYCLES");
  for (int j = 1; j <= k; j++) {
    int x = q[j], y = 0, z = 0;
    for (int i = head[x]; i; i = ne[i]) {
      if (fa[x] == to[i]) continue;
      if (!y)
        y = to[i];
      else
        z = to[i];
    }
    int res = d[x] - d[y] + 1;
    if (res % 3) {
      printf("%d\n", res);
      while (x != y) {
        printf("%d ", x);
        x = fa[x];
      }
      printf("%d\n", y);
      continue;
    }
    res = d[x] - d[z] + 1;
    if (res % 3) {
      printf("%d\n", res);
      while (x != z) {
        printf("%d ", x);
        x = fa[x];
      }
      printf("%d\n", z);
      continue;
    }
    if (d[y] < d[z]) swap(y, z);
    res = d[y] - d[z] + 2;
    printf("%d\n", res);
    while (y != z) {
      printf("%d ", y);
      y = fa[y];
    }
    printf("%d %d\n", z, x);
  }
  return 0;
}
