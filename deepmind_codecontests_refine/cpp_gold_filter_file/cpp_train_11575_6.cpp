#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, cou;
char board[300][300];
void search(int i, int j) {
  for (int p = -1; p < 2; p++)
    for (int q = -1; q < 2; q++) {
      if (p == 0 && q == 0) continue;
      int y = i + p, x = j + q;
      if (y < 0 || y >= n || x < 0 || x >= m) continue;
      if (board[y][x] != 1) continue;
      board[y][x] = 2;
      cou++;
      search(y, x);
    }
}
void fill(int i, int j) {
  board[i][j] = 0;
  for (int p = -1; p < 2; p++)
    for (int q = -1; q < 2; q++) {
      if (p == 0 && q == 0) continue;
      int y = i + p, x = j + q;
      if (y < 0 || y >= n || x < 0 || x >= m) continue;
      if (board[y][x] != 2) continue;
      fill(y, x);
    }
}
bool check1(int y, int x, int t) {
  if (y + t - 1 >= n || x + t - 1 >= m) return false;
  for (int i = y; i < y + t; i++) {
    if (board[i][x] != 2 || board[i][x + t - 1] != 2) return false;
  }
  for (int i = x; i < x + t; i++)
    if (board[y][i] != 2 || board[y + t - 1][i] != 2) return false;
  return true;
}
bool check2(int y, int x, int t) {
  if (x - t + 1 < 0 || x + t - 1 >= m || y + 2 * t - 2 >= n) return false;
  for (int i = 0; i > -t; i--) {
    if (board[y - i][x + i] != 2 || board[y + t - 1 - i][x + t - 1 + i] != 2)
      return false;
  }
  for (int i = 0; i > -t; i--)
    if (board[y + t - 1 - i][x - t + 1 - i] != 2 || board[y - i][x - i] != 2)
      return false;
  return true;
}
bool check(int i, int j) {
  if (cou % 4 != 0) return false;
  int t = cou / 4 + 1;
  return check1(i, j, t) || check2(i, j, t);
}
void show() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d", board[i][j]);
    printf("\n");
  }
  printf("\n");
}
int main() {
  int runs;
  for (scanf("%d", &runs); runs > 0; runs--) {
    scanf("%d %d", &n, &m);
    cnt = 0;
    for (int i = 0; i < n; i++) scanf("%s", board[i]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) board[i][j] -= '0';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 0) continue;
        cou = 0;
        search(i, j);
        if (check(i, j)) {
          cnt++;
        }
        fill(i, j);
      }
    printf("%d\n", cnt);
  }
}
