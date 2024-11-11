#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct data {
  int nt, to, w;
} a[N << 1];
int head[N], pre[N], c[N], vis[N], d[N], dis[N], q[N];
int mx = 0, cnt = 0;
void add(int x, int y, int w) {
  a[++cnt].to = y, a[cnt].w = w, a[cnt].nt = head[x], head[x] = cnt;
  a[++cnt].to = x, a[cnt].w = w, a[cnt].nt = head[y], head[y] = cnt;
}
void dfs(int u, int fa) {
  pre[u] = fa;
  for (int i = head[u]; i; i = a[i].nt) {
    int to = a[i].to;
    if (to == fa) continue;
    dis[to] = dis[u] + a[i].w;
    dfs(to, u);
  }
}
void go(int u, int now) {
  vis[u] = 1, mx = max(mx, now);
  for (int i = head[u]; i; i = a[i].nt) {
    int to = a[i].to;
    if (vis[to]) continue;
    go(to, now + a[i].w);
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 2; i <= n; ++i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    add(x, y, w);
  }
  dfs(1, 0);
  int be = -1, maxn = 0;
  for (int i = 1; i <= n; ++i) {
    if (maxn < dis[i]) {
      be = i, maxn = dis[i];
    }
  }
  memset(dis, 0, sizeof dis);
  memset(pre, 0, sizeof pre);
  dfs(be, 0);
  int st = -1;
  maxn = 0;
  for (int i = 1; i <= n; ++i) {
    if (maxn < dis[i]) {
      st = i, maxn = dis[i];
    }
  }
  for (; st; st = pre[st]) {
    c[++c[0]] = st, vis[st] = 1;
  }
  reverse(c + 1, c + 1 + c[0]);
  for (int i = 1; i <= c[0]; ++i) {
    mx = 0;
    go(c[i], 0);
    d[i] = mx;
  }
  k = min(k, c[0]);
  int ans = 1e9;
  int head = 1, tail = 0;
  for (int i = 1; i <= c[0]; ++i) {
    while (head <= tail && d[q[tail]] <= d[i]) tail--;
    q[++tail] = i;
    while (head <= tail && q[head] <= i - k) head++;
    if (i >= k) {
      int pos = max(dis[c[i - k + 1]], dis[c[c[0]]] - dis[c[i]]);
      ans = min(ans, max(pos, d[q[head]]));
    }
  }
  printf("%d\n", ans);
  return 0;
}
