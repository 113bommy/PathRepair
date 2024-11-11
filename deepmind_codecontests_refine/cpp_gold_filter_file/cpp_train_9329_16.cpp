#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int inf = 1e9;
int h[N], q[N], dis[N], v[N], pre[N];
int n, m, tot = 1, vs, vt, ans;
int op, l, r, x, mn[N], mx[N];
struct edge {
  int x, y, z, c, next;
} g[N * 4];
void adp(int x, int y, int z, int c) {
  g[++tot].y = y;
  g[tot].x = x;
  g[tot].c = c;
  g[tot].z = z;
  g[tot].next = h[x];
  h[x] = tot;
  g[++tot].y = x;
  g[tot].x = y;
  g[tot].c = -c;
  g[tot].z = 0;
  g[tot].next = h[y];
  h[y] = tot;
}
int spfa() {
  memset(dis, 0x16, sizeof(dis));
  memset(v, 0, sizeof(v));
  v[vs] = 1;
  int l = 0, r = 1;
  q[1] = vs;
  dis[vs] = 0;
  while (l < r) {
    int x = q[++l];
    v[x] = 0;
    for (int i = h[x]; i; i = g[i].next)
      if (g[i].z && dis[g[i].y] > dis[x] + g[i].c) {
        dis[g[i].y] = dis[x] + g[i].c;
        pre[g[i].y] = i;
        if (!v[g[i].y]) {
          v[g[i].y] = 1;
          q[++r] = g[i].y;
        }
      }
  }
  if (dis[vt] == 370546198) return 0;
  int res = inf;
  for (int i = pre[vt]; i; i = pre[g[i].x]) res = min(res, g[i].z);
  ans += res * dis[vt];
  for (int i = pre[vt]; i; i = pre[g[i].x]) g[i].z -= res, g[i ^ 1].z += res;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) mn[i] = 1, mx[i] = n;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &op, &l, &r, &x);
    if (op == 1) {
      for (int j = l; j <= r; j++) mn[j] = max(mn[j], x);
    } else {
      for (int j = l; j <= r; j++) mx[j] = min(mx[j], x);
    }
  }
  for (int i = 1; i <= n; i++)
    if (mn[i] > mx[i]) {
      printf("-1\n");
      return 0;
    }
  vs = 0;
  vt = 2 * n + 1;
  for (int i = 1; i <= n; i++) adp(vs, i, 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = mn[i]; j <= mx[i]; j++) adp(i, j + n, 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) adp(n + i, vt, 1, 2 * j - 1);
  while (spfa())
    ;
  printf("%d\n", ans);
}
