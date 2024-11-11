#include <bits/stdc++.h>
using namespace std;
int T, n, m, cnt, ans, tot, head[205], deg[205], vis[205 * 205 * 2], tag[205];
struct Edge {
  int next, to;
} edge[205 * 2];
pair<int, int> pii[205 * 205];
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
    pii[++tot] = make_pair(x, to);
    deg[x]--;
    deg[to]--;
    if (!deg[x]) tag[x] = 1;
    dfs(to);
    break;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    ans = tot = 0;
    cnt = 1;
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));
    memset(head, 0, sizeof(head));
    memset(tag, 0, sizeof(tag));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      addedge(x, y);
      addedge(y, x);
    }
    for (int i = 1; i <= n; i++) {
      if (deg[i] & 1)
        q.push(i);
      else
        ans++;
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      dfs(x);
    }
    for (int i = 1; i <= n; i++)
      if (!tag[i]) dfs(i);
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) printf("%d %d\n", pii[i].first, pii[i].second);
  }
  return 0;
}
