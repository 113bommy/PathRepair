#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[MAXN][MAXN];
int visit[MAXN][MAXN];
int dsu[MAXN][MAXN];
long long n, m, qq;
pair<int, int> q[MAXN * MAXN];
inline bool check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + pos[i][0], ny = y + pos[i][1];
    if (a[nx][ny] == a[x][y]) return true;
  }
  return false;
}
void bfs() {
  long long front = 0;
  long long end = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (check(i, j)) {
        dsu[i][j] = 0;
        visit[i][j] = 1;
        q[end++] = make_pair(i, j);
      }
  while (front < end) {
    pair<long long, long long> now = q[front++];
    for (int i = 0; i < 4; i++) {
      int nx = now.first + pos[i][0], ny = now.second + pos[i][1];
      if (nx < 1 || nx > n || ny < 1 || ny > m || visit[nx][ny]) continue;
      dsu[nx][ny] = dsu[now.first][now.second] + 1;
      visit[nx][ny] = true;
      q[end++] = make_pair(nx, ny);
    }
  }
}
int main() {
  memset(a, -1, sizeof(a));
  memset(dsu, -1, sizeof(dsu));
  memset(visit, 0, sizeof(visit));
  cin >> n >> m >> qq;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) a[i][j + 1] = s[j] - '0';
  }
  bfs();
  int x, y;
  long long t;
  while (qq--) {
    cin >> x >> y >> t;
    if (visit[x][y]) {
      printf("%d\n", a[x][y] ^ (max(0ll, t - dsu[x][y]) & 1));
    } else
      printf("%d\n", dsu[x][y]);
  }
}
