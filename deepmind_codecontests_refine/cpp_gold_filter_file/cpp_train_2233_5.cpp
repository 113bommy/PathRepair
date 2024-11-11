#include <bits/stdc++.h>
using namespace std;
struct name {
  int to, next;
} bl[400001];
int n, m, a[400001], f[400001], h[400001], cnt, ans, sum;
bool vis[400001];
void add(int u, int v) {
  bl[++cnt].to = v;
  bl[cnt].next = h[u];
  h[u] = cnt;
}
void dfs(int u, int fa) {
  vis[u] = 1;
  f[++ans] = u;
  a[u] ^= 1;
  for (int i = h[u]; i; i = bl[i].next)
    if (!vis[bl[i].to]) {
      dfs(bl[i].to, u);
      f[++ans] = u;
      a[u] ^= 1;
    }
  if (a[u]) {
    f[++ans] = fa;
    a[fa] ^= 1;
    f[++ans] = u;
    a[u] ^= 1;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) sum = i;
  }
  if (sum) {
    dfs(sum, -1);
    for (int i = 1; i <= n; i++)
      if (!vis[i] && a[i]) return printf("-1\n"), 0;
  }
  if (ans > 1 && f[ans - 1] == -1) ans -= 3;
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d ", f[i]);
}
