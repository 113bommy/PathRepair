#include <bits/stdc++.h>
using namespace std;
int T, n, m, cnt = 1, sum, head[205], deg[205], vis[205 * 205 * 2], tag[205],
             ans[205 * 205];
int x[205 * 205], y[205 * 205];
struct Edge {
  int next, to;
} edge[205 * 205 * 2];
queue<int> q;
void addedge(int from, int to) {
  edge[++cnt].next = head[from];
  edge[cnt].to = to;
  deg[to]++;
  head[from] = cnt;
}
void dfs(int x) {
  if (!deg[x]) tag[x] = 1;
  for (int i = head[x]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (vis[i]) continue;
    vis[i] = vis[i ^ 1] = 1;
    ans[i / 2] = i % 2;
    deg[x]--;
    deg[to]--;
    if (!deg[x]) tag[x] = 1;
    dfs(to);
    break;
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    addedge(x[i], y[i]);
    addedge(y[i], x[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] & 1)
      q.push(i);
    else
      sum++;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    dfs(x);
  }
  for (int i = 1; i <= n; i++)
    if (!tag[i]) dfs(i);
  printf("%d\n", sum);
  for (int i = 1; i <= m; i++) {
    if (ans[i])
      printf("%d %d\n", y[i], x[i]);
    else
      printf("%d %d\n", x[i], y[i]);
  }
}
void init() {
  sum = 0;
  cnt = 1;
  memset(head, 0, sizeof(head));
  memset(deg, 0, sizeof(deg));
  memset(tag, 0, sizeof(tag));
  memset(vis, 0, sizeof(vis));
  memset(ans, 0, sizeof(ans));
}
int main() {
  scanf("%d", &T);
  while (T--) {
    init();
    solve();
  }
  return 0;
}
