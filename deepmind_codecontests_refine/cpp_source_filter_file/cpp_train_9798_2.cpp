#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
struct pos {
  int x, y;
  int xx, yy;
};
int n, m, r, c, xx, yy;
bool vis[MAXN][MAXN];
char str[MAXN];
pos move(pos x, int k) {
  if (k == 0) return (pos){x.x - 1, x.y, x.xx, x.yy};
  if (k == 1) return (pos){x.x + 1, x.y, x.xx, x.yy};
  if (k == 2) return (pos){x.x, x.y - 1, x.xx - 1, x.yy};
  if (k == 3) return (pos){x.x, x.y + 1, x.xx, x.yy - 1};
}
void bfs(pos st) {
  deque<pos> que;
  que.push_back(st);
  int ans = 0;
  for (; !que.empty();) {
    pos now = que.front();
    que.pop_front();
    if (vis[now.x][now.y]) continue;
    vis[now.x][now.y] = true;
    ans++;
    if (now.x > 1 && !vis[now.x - 1][now.y]) que.push_front(move(now, 0));
    if (now.x < n && !vis[now.x + 1][now.y]) que.push_front(move(now, 1));
    if (now.xx > 0 && now.y > 1 && !vis[now.x][now.y - 1])
      que.push_back(move(now, 2));
    if (now.yy > 0 && now.y < m && !vis[now.x][now.y + 1])
      que.push_back(move(now, 3));
  }
  printf("%d\n", ans);
}
int main() {
  cin >> n >> m >> r >> c >> xx >> yy;
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; j++) vis[i][j] = str[j] == '*';
  }
  bfs((pos){r, c, xx, yy});
  return 0;
}
