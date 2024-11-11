#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;
const int Mod = (int)1e9 + 7;
int n;
char g[3][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int could[4];
int is(int a, int b) {
  return a >= 0 && a < 3 && b >= 0 && b < n && g[a][b] == '.';
}
int f[MAX][8];
void add(int& a, int b) {
  a += b;
  if (a >= Mod) a -= Mod;
}
int get() {
  int i, cc = 0;
  int last = 0;
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  for ((i) = (0); (i) <= (n); ++(i)) {
    cc = (is(0, i) << 0) | (is(1, i) << 1) | (is(2, i) << 2);
    int g[8];
    memset(g, 0, sizeof g);
    for ((last) = (0); (last) != (8); ++(last)) {
      int np = f[i][last];
      if (last == 7) {
        add(g[0], np);
        add(g[2 + 4], np);
        add(g[1 + 2], np);
      } else if (last == 6) {
        add(g[1], np);
        add(g[1 + 2 + 4], np);
      } else if (last == 3) {
        add(g[4], np);
        add(g[1 + 2 + 4], np);
      } else if (last == 0)
        add(g[1 + 2 + 4], np);
      else if (last == 1 + 4)
        add(g[2], np);
      else
        add(g[(1 != last) + (2 != last) * 2 + (4 != last) * 4], np);
    }
    for ((last) = (0); (last) != (8); ++(last))
      if (((~last) & (~cc)) & ((1 << 3) - 1))
        ;
      else
        add(f[i + 1][last & cc], g[last]);
  }
  return f[n + 1][0];
}
int main() {
  int i, j;
  scanf("%d", &n);
  int sx = 0, sy = 0;
  for ((i) = (0); (i) != (3); ++(i)) {
    cin >> g[i];
    for ((j) = (0); (j) != (n); ++(j))
      if (g[i][j] == 'O') {
        sx = i;
        sy = j;
      }
  }
  int pp = 0, dir;
  for ((dir) = (0); (dir) != (4); ++(dir)) {
    int& flag = could[dir];
    flag = 1;
    for ((j) = (1); (j) <= (2); ++(j))
      if (!is(sx + dx[dir] * j, sy + dy[dir] * j)) {
        flag = 0;
        break;
      }
    if (!flag) continue;
    pp |= (1 << dir);
  }
  int ans = 0;
  for (i = pp; i; i = (i - 1) & pp) {
    for ((dir) = (0); (dir) != (4); ++(dir))
      if (i & (1 << dir))
        for ((j) = (1); (j) <= (2); ++(j))
          g[sx + dx[dir] * j][sy + dy[dir] * j] = '#';
    int cc = 0;
    for ((dir) = (0); (dir) != (4); ++(dir))
      if (i & (1 << dir)) cc++;
    if (cc % 2 == 1)
      ans = (ans + get()) % Mod;
    else
      ans = (ans - get()) % Mod;
    for ((dir) = (0); (dir) != (4); ++(dir))
      if (i & (1 << dir))
        for ((j) = (1); (j) <= (2); ++(j))
          g[sx + dx[dir] * j][sy + dy[dir] * j] = '.';
  }
  cout << ans << endl;
  return 0;
}
