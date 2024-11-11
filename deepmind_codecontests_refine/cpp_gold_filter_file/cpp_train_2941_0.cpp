#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
inline long long readint() {
  long long res = 0, f = 1;
  char c = 0;
  while (!isdigit(c)) {
    c = getchar();
    if (c == '-') f = -1;
  }
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res * f;
}
int n, m, T, a[MAXN][MAXN];
char str[MAXN];
int f[MAXN][MAXN], pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[MAXN][MAXN];
inline bool check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + pos[i][0], ny = y + pos[i][1];
    if (a[nx][ny] == a[x][y]) return true;
  }
  return false;
}
pair<int, int> q[MAXN * MAXN];
inline void bfs() {
  int front = 0, rear = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (check(i, j))
        f[i][j] = 0, vis[i][j] = true, q[rear++] = make_pair(i, j);
  while (front < rear) {
    pair<int, int> now = q[front++];
    for (int i = 0; i < 4; i++) {
      int nx = now.first + pos[i][0], ny = now.second + pos[i][1];
      if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
      f[nx][ny] = f[now.first][now.second] + 1;
      vis[nx][ny] = true;
      q[rear++] = make_pair(nx, ny);
    }
  }
}
int main() {
  n = readint(), m = readint(), T = readint();
  memset(a, -1, sizeof(a));
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; j++) a[i][j] = str[j] - '0';
  }
  bfs();
  int x, y;
  long long t;
  while (T--) {
    x = readint(), y = readint(), t = readint();
    if (vis[x][y])
      printf("%d\n", a[x][y] ^ (max(0ll, t - f[x][y]) & 1));
    else
      printf("%d\n", a[x][y]);
  }
  return 0;
}
