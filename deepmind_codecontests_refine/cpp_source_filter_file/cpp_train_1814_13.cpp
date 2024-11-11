#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 1e3 + 5;
const int mod = 1e9 + 7;
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 0x3f3f3f3f;
int n, m, sx, sy, cnt, ans;
int tx[9], ty[9], v[9], w[1 << 8], f[22][22][1 << 8];
char g[22][22];
struct node {
  int x, y, s;
};
inline bool judge(int px, int py, int x, int y, int id) {
  if (x == tx[id] && y < ty[id])
    return px < tx[id];
  else if (px == tx[id] && py < ty[id])
    return x < tx[id];
  return 0;
}
inline void bfs() {
  queue<node> q;
  memset(f, -1, sizeof f);
  q.push({sx, sy, 0});
  f[sx][sy][0] = 0;
  bool first = 1;
  while (!q.empty()) {
    node cur = q.front();
    q.pop();
    if (cur.x == sx && cur.y == sy) {
      ans = max(ans, w[cur.s] - f[cur.x][cur.y][cur.s]);
      if (first)
        first = 0;
      else
        continue;
    }
    for (int i = 0; i < 4; i++) {
      int dx = cur.x + dir[i][0];
      int dy = cur.y + dir[i][1];
      int s = cur.s;
      if (dx < 1 || dx > n || dy < 1 || dy > m ||
          (g[dx][dy] != 'S' && g[dx][dy] != '.'))
        continue;
      for (int j = 0; j < cnt + 1; j++) {
        if (judge(cur.x, cur.y, dx, dy, j)) s ^= (1 << j);
      }
      if (f[dx][dy][s] != -1 && f[dx][dy][s] <= f[cur.x][cur.y][cur.s] + 1)
        continue;
      f[dx][dy][s] = f[cur.x][cur.y][cur.s] + 1;
      q.push({dx, dy, s});
    }
  }
}
inline void solve() {
  scanf("%d%d", &n, &m);
  cnt = -1;
  for (int i = 1; i < n + 1; i++) {
    scanf("%s", g[i] + 1);
    for (int j = 1; j < m + 1; j++) {
      if (g[i][j] == 'S')
        sx = i, sy = j;
      else if ('1' <= g[i][j] && g[i][j] <= '8') {
        cnt++;
        int id = g[i][j] - '1';
        tx[id] = i;
        ty[id] = j;
      }
    }
  }
  for (int i = 0; i < cnt + 1; i++) scanf("%d", &v[i]);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (g[i][j] == 'B') {
        tx[++cnt] = i;
        ty[cnt] = j;
        v[cnt] = -inf;
      }
    }
  }
  memset(w, 0, sizeof w);
  int tot = 1 << (cnt + 1);
  for (int i = 0; i < tot; i++) {
    for (int j = 0; j < cnt + 1; j++)
      if (i & (1 << j)) {
        w[i] += v[j];
      }
  }
  ans = -inf;
  bfs();
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
