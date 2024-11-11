#include <bits/stdc++.h>
using namespace std;
const int N = 400 + 5, M = 0, Z = 1e9 + 7, ms63 = 1061109567;
int n, m, x, y;
bool a[N][N];
bool vis[N];
int BFS(bool w) {
  memset(vis, 0, sizeof(vis));
  queue<pair<int, int> > q;
  q.push(make_pair(1, 0));
  while (!q.empty()) {
    int x = q.front().first, step = q.front().second + 1;
    q.pop();
    for (int i = 1; i <= n; i++)
      if (!vis[i] && a[x][i] == w) {
        if (i == n) return step;
        q.push(make_pair(i, step));
        vis[i] = 1;
      }
  }
  return -1;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &x, &y);
      a[x][y] = a[y][x] = 1;
    }
    int ans;
    if (a[1][n])
      ans = BFS(0);
    else
      ans = BFS(1);
    printf("%d\n", ans - 1);
  }
  return 0;
}
