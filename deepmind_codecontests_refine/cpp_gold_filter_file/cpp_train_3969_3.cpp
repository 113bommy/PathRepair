#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, h, id;
  node(int a, int b, int c) { x = a, h = b, id = c; }
};
int a[105], b[105], x[105], h[105], ans[105], vis[105][105];
queue<node> q;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> x[i] >> h[i];
  for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
  for (int pos = 1; pos <= n; pos++) {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      q.push(node(x[i], h[i], i));
      memset(vis[i], 0, sizeof(vis[i]));
    }
    for (int i = 1; i <= n; i++) a[i] = b[i];
    while (!q.empty()) {
      node e = q.front();
      q.pop();
      if (vis[e.id][e.x] == n) continue;
      vis[e.id][e.x]++;
      if (e.x == pos) {
        ans[++cnt] = e.id;
        continue;
      }
      int xx = e.x, hh = e.h;
      while (pos > e.x && e.h + a[e.x + 1] >= 0) ++e.x, e.h += a[e.x];
      while (pos < e.x && e.h + a[e.x - 1] >= 0) --e.x, e.h += a[e.x];
      int t1 = min(xx, pos), t2 = max(xx, pos);
      if (e.x == pos)
        for (int k = t1; k <= t2; k++) a[k] = 0;
      else
        e.x = xx, e.h = hh;
      q.push(e);
    }
    if (cnt == m) {
      printf("%d\n", pos);
      for (int i = 1; i <= cnt; i++) cout << ans[i] << " ";
      return 0;
    }
  }
  puts("-1");
}
