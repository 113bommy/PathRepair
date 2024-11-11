#include <bits/stdc++.h>
const int MAXN = 200000 * 3;
int n, m;
char ma[10][10];
bool ok = false;
void dfs(int a, int b, int step) {
  if (step > 8) {
    ok = true;
    return;
  }
  for (int i = 1; i <= 7; ++i) {
    for (int j = 1; j <= 8; ++j) {
      if (ma[i][j] == 'S') {
        if (i + step == a && j == b) {
          return;
        }
      }
    }
  }
  for (int dir_x = -1; dir_x <= 1; ++dir_x) {
    for (int dir_y = -1; dir_y <= 1; ++dir_y) {
      int x = a + dir_x, y = b + dir_y;
      if (ma[x - step][y] != 'S' && x >= 1 && y >= 1 && x <= 8 && y <= 8) {
        dfs(x, y, step + 1);
        if (ok == true) {
          return;
        }
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      std::cin >> ma[i][j];
    }
  }
  dfs(8, 1, 0);
  puts(ok ? "WIN" : "LOSE");
}
