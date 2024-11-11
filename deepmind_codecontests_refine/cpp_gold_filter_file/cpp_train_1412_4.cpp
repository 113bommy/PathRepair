#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct edge {
  int x, y;
} e[N];
int v[N], w[N], nxt[N], point[N], bs = 0, bs0 = 0, tot = 0;
int vis[N], inq[N], vip[N], last[N], fa[N], num[N], bj[N], sta[N], top = 0;
void addedge(int x, int y, int z) {
  bs++;
  v[bs] = y;
  w[bs] = z;
  nxt[bs] = point[x];
  point[x] = bs;
  bs++;
  v[bs] = x;
  w[bs] = z;
  nxt[bs] = point[y];
  point[y] = bs;
}
void add(int x, int y) { bs0++, e[bs0].x = x, e[bs0].y = y; }
void dfs(int x) {
  int i, p;
  vis[x] = 1;
  inq[x] = 1;
  sta[++top] = x;
  for (p = point[x]; p; p = nxt[p])
    if (!vis[v[p]]) {
      last[x] = p;
      dfs(v[p]);
    } else if (inq[v[p]] && v[p] != sta[top - 1]) {
      last[x] = p;
      tot++;
      for (i = top; sta[i] != v[p]; i--)
        ;
      for (; i <= top; i++) {
        int x = sta[i], p = last[x];
        vip[(p + 1) / 2] = 1;
        add(tot, w[p]);
      }
    }
  last[x] = 0;
  inq[x] = 0;
  top--;
}
int findfa(int x) {
  if (fa[x] != x) fa[x] = findfa(fa[x]);
  return fa[x];
}
int main() {
  int i, j, n, m;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    addedge(x, y, z + n);
  }
  dfs(1);
  for (i = 1; i <= m; i++)
    if (!vip[i]) add(0, w[2 * i]), add(0, w[2 * i]);
  for (i = 0; i <= n + m; i++) fa[i] = i;
  for (i = n + 1; i <= n + m; i++) fa[i] = i, num[i] = 1;
  for (i = 1; i <= bs0; i++) {
    int f1 = findfa(e[i].x), f2 = findfa(e[i].y);
    if (f1 != f2) {
      fa[f1] = f2;
      bj[f2] |= bj[f1];
      num[f2] += num[f1];
    } else
      bj[f1] = 1;
  }
  int ans = 0;
  for (i = 0; i <= n + m; i++)
    if (num[i] > 0 && findfa(i) == i) ans += num[i] - 1 + bj[i];
  printf("%d\n", ans);
  return 0;
}
