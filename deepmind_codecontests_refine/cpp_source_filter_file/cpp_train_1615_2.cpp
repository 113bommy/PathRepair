#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, next;
} e[200010 << 2];
int head[200010];
int cnt;
int n, m;
int ans1, ans2;
int mark[200010], vis[200010], dep[200010];
void link(int x, int y) {
  e[++cnt] = (edge){y, head[x]};
  head[x] = cnt;
}
void dfs(int x, int fa) {
  if (fa != -1) dep[x] = dep[fa] + 1;
  if (mark[x]) vis[x] = 1;
  for (int i = head[x], y; i, y = e[i].to; i = e[i].next)
    if (y != fa) {
      dfs(y, x);
      vis[x] |= vis[y];
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    link(x, y);
    link(y, x);
  }
  for (int i = 1, x; i <= m; i++) {
    scanf("%d", &x);
    mark[x] = 1;
  }
  int maxn, t1, t2;
  for (int i = 1; i <= n; i++)
    if (mark[i]) {
      maxn = 0;
      t1 = i;
      dfs(i, -1);
      break;
    }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) ans1++;
    if (mark[i] && dep[i] > maxn) maxn = dep[i], t1 = i;
  }
  ans1 = (ans1 - 1) * 2;
  memset(dep, 0, sizeof(dep));
  dfs(t1, -1);
  maxn = 0;
  t2 = t1;
  for (int i = 1; i <= n; i++)
    if (mark[i] && dep[i] > maxn) maxn = dep[i], t2 = i;
  printf("%d\n%d\n", t2, ans1 - maxn);
  return 0;
}
