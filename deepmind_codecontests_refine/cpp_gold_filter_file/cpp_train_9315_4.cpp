#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
char cm[600][600];
int cn[600][600], n, m;
bool vis[600][600];
int next_x[] = {0, 1, 0, -1};
int next_y[] = {1, 0, -1, 0};
int sx, sy, ex, ey;
void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = true;
  if (x < 1 || x > n) return;
  if (y < 1 || y > m) return;
  if (cm[x][y] == 'X') return;
  for (int i = 0; i < 4; i++) dfs(x + next_x[i], y + next_y[i]);
}
int main() {
  n = readInt<int>(), m = readInt<int>();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> cm[i][j];
  memset(vis, false, sizeof(vis));
  sx = readInt<int>(), sy = readInt<int>(), ex = readInt<int>(),
  ey = readInt<int>();
  cm[sx][sy] = '.';
  dfs(sx, sy);
  cm[sx][sy] = 'X';
  if (ex == sx && ey == sy) {
    for (int i = 0; i < 4; i++)
      if (cm[sx + next_x[i]][sy + next_y[i]] == '.') return cout << "YES", 0;
    return cout << "NO", 0;
  }
  if (vis[ex][ey]) {
    if (cm[ex][ey] == 'X')
      cout << "YES";
    else {
      int cc = 0;
      for (int i = 0; i < 4; i++)
        if (cm[ex + next_x[i]][ey + next_y[i]] == '.') cc++;
      if (abs(sx - ex) == 1 && sy - ey == 0 && cc >= 1)
        cout << "YES";
      else if (abs(sy - ey) == 1 && sx - ex == 0 && cc >= 1)
        cout << "YES";
      else if (cc > 1)
        cout << "YES";
      else
        return cout << "NO", 0;
    }
  } else
    cout << "NO";
  return 0;
}
