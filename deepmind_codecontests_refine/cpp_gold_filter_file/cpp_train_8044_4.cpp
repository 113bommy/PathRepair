#include <bits/stdc++.h>
using namespace std;
int n, m;
char block[][3][4] = {{"..#", "###", "..#"},
                      {".#.", ".#.", "###"},
                      {"#..", "###", "#.."},
                      {"###", ".#.", ".#."}};
int cell[10][10], anscell[10][10];
int bcnt, ans;
bool isPlacable(int i, int j, int k) {
  for (int p = 0; p < 3; ++p)
    for (int q = 0; q < 3; ++q) {
      if (cell[i + p][j + q] != -1 && block[k][p][q] == '#') return false;
    }
  return true;
}
void setBlock(int i, int j, int k) {
  for (int p = 0; p < 3; ++p)
    for (int q = 0; q < 3; ++q) {
      if (block[k][p][q] == '#') cell[i + p][j + q] = bcnt;
    }
  ++bcnt;
}
void removeBlock(int i, int j, int k) {
  for (int p = 0; p < 3; ++p)
    for (int q = 0; q < 3; ++q) {
      if (block[k][p][q] == '#') cell[i + p][j + q] = -1;
    }
  --bcnt;
}
void go(int i, int j) {
  if (j >= m - 2) {
    go(i + 1, 0);
    return;
  }
  if (i == n - 2) {
    if (ans < bcnt) {
      ans = bcnt;
      memcpy(anscell, cell, sizeof(cell));
    }
    return;
  }
  if (bcnt + (n * m - (i * m + j)) / 6 <= ans) {
    return;
  }
  for (int k = 0; k < 4; ++k) {
    if (isPlacable(i, j, k)) {
      setBlock(i, j, k);
      go(i, j + 1);
      removeBlock(i, j, k);
    }
  }
  go(i, j + 1);
}
int main() {
  memset(cell, -1, sizeof(cell));
  memset(anscell, -1, sizeof(anscell));
  scanf("%d %d", &n, &m);
  if (n >= 3 && m >= 3) go(0, 0);
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      putchar(anscell[i][j] == -1 ? '.' : ('A' + anscell[i][j]));
    }
    putchar('\n');
  }
  return 0;
}
