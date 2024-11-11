#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 1000010, INF = 0x3f3f3f3f;
int n, m, k;
int g[N][N], dist[N][N];
pair<int, int> q[M];
char s[N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
    if (g[tx][ty] == g[x][y]) return true;
  }
  return false;
}
void bfs() {
  int hh = 0, tt = -1;
  memset(dist, 0x3f, sizeof dist);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (check(i, j)) {
        q[++tt] = {i, j};
        dist[i][j] = 0;
      }
  while (hh <= tt) {
    auto t = q[hh++];
    for (int i = 0; i < 4; i++) {
      int tx = t.first + dx[i];
      int ty = t.second + dy[i];
      if (tx < 1 || ty < 1 || tx > n || ty > m || dist[tx][ty] != INF) continue;
      dist[tx][ty] = dist[t.first][t.second] + 1;
      q[++tt] = {tx, ty};
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) g[i][j] = s[j] - '0';
  }
  bfs();
  while (k--) {
    int x, y;
    long long p;
    scanf("%d%d%lld", &x, &y, &p);
    if (dist[x][y] == INF)
      printf("%d\n", g[x][y]);
    else
      printf("%d\n", g[x][y] ^ (max(0LL, p - dist[x][y]) & 1LL));
  }
  return 0;
}
