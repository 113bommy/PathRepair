#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
const int inf = 0x7ffffff;
struct node {
  int x, y;
  node() {}
  node(int _x, int _y) {
    x = _x;
    y = _y;
  }
} ans[maxn];
vector<int> G[maxn];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int vis[maxn];
void dfs(int u, int x, int y, int dir, int num) {
  if (vis[u]) return;
  vis[u] = 1;
  int tmp = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v]) continue;
    if (tmp == dir) tmp = (tmp + 1) % 4;
    int tx = x + dx[tmp] * (1 << num);
    int ty = y + dy[tmp] * (1 << num);
    ans[v] = node(tx, ty);
    dfs(v, tx, ty, (tmp + 2) % 4, num - 1);
    tmp = (tmp + 1) % 4;
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    if (G[i].size() > 4) {
      flag = 0;
      puts("NO");
      break;
    }
  }
  if (flag) {
    puts("YES");
    memset(vis, 0, sizeof(vis));
    ans[1] = node(0, 0);
    dfs(1, 0, 0, 0, 30);
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].x, ans[i].y);
  }
  return 0;
}
