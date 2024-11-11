#include <bits/stdc++.h>
const int mod = (int)1e9 + 7;
int n, x = 0, y = 0;
char m[4][10010 + 1];
int f[2][64];
inline int get(int x, int p) { return (x >> (p - 1) * 2) & 3; }
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int solve() {
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    memset(f[i & 1], 0, sizeof f[i & 1]);
    for (int j = 0; j < 64; ++j) {
      if (!f[i & 1 ^ 1][j]) continue;
      for (int k = 0; k < 64; ++k) {
        bool ok = true;
        for (int x = 1; ok && x <= 3; ++x) {
          if (get(j, x) == 1 && get(k, x) != 2) ok = false;
          if (get(k, x) == 2 && get(j, x) != 1) ok = false;
          if (m[x][i] != 'X' && get(k, x) == 0) ok = false;
          if (m[x][i] == 'X' && get(k, x) != 0) ok = false;
        }
        if (get(k, 1) == 3 && get(k, 2) != 3) ok = false;
        if (get(k, 2) != 3 && get(k, 3) == 3) ok = false;
        if (get(k, 2) == 3 && get(k, 1) != 3 && get(k, 3) != 3) ok = false;
        if (get(k, 1) == 3 && get(k, 2) == 3 && get(k, 3) == 3) ok = false;
        if (!ok) continue;
        add(f[i & 1][k], f[i & 1 ^ 1][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 64; ++i) {
    bool ok = true;
    for (int x = 1; ok && x <= 3; ++x) {
      if (get(i, x) == 1) ok = false;
    }
    if (!ok) continue;
    add(ans, f[n & 1][i]);
  }
  return ans;
}
const int dir[8][2] = {{0, 1},   {1, 0},  {-1, 0}, {0, -1},
                       {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int main() {
  scanf("%d", &n);
  scanf("%s%s%s", m[1] + 1, m[2] + 1, m[3] + 1);
  for (int i = 1; !x && i <= n; ++i)
    for (int j = 1; j <= 3; ++j)
      if (m[j][i] == 'O') x = j, y = i;
  m[x][y] = 'X';
  int ans = solve();
  if (x == 2 && y > 1 && y < n) {
    bool need = true;
    for (int i = 0; i < 8; ++i) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if (m[nx][ny] == 'X') need = false;
    }
    if (need) {
      for (int i = 0; i < 8; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        m[nx][ny] = 'X';
      }
      ans -= 2 * solve();
      while (ans < 0) ans += mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}
