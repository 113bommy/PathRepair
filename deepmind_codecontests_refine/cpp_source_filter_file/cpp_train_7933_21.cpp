#include <bits/stdc++.h>
using namespace std;
int read() {
  int xx = 0, ww = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ww = -ww;
    ch = getchar();
  }
  while (isdigit(ch)) {
    xx = 10 * xx + ch - 48;
    ch = getchar();
  }
  return xx * ww;
}
char s[10][10];
bool has_statue[10][10][10];
int sx, sy, ex, ey;
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1},
    dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
bool dfs(int x, int y, int t) {
  if (t >= 8) return true;
  if (x == ex && y == ey) return true;
  bool ans = false;
  for (int i = 0; i <= 8; i++) {
    int xx = dx[i] + x, yy = dy[i] + y;
    if (xx >= 0 && yy >= 0 && xx < 8 && yy < 8 && !has_statue[xx][yy][t] &&
        !has_statue[xx][yy][t + 1])
      ans |= dfs(xx, yy, t + 1);
  }
  return ans;
}
void print() {
  for (int k = 0; k <= 8; k++) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (has_statue[i][j][k] == true)
          printf("S");
        else
          printf(".");
      }
      puts("");
    }
    puts("");
  }
  return;
}
int main() {
  memset(has_statue, false, sizeof(has_statue));
  for (int i = 0; i < 8; i++) scanf("%s", s[i]);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == 'S') {
        has_statue[i][j][0] = true;
      } else if (s[i][j] == 'M') {
        sx = i;
        sy = j;
      } else if (s[i][j] == 'A') {
        ex = i;
        ey = j;
      }
    }
  }
  for (int k = 0; k < 8; k++)
    for (int i = 1; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (has_statue[i][j][k]) has_statue[i + 1][j][k + 1] = true;
  if (dfs(sx, sy, 0))
    puts("WIN");
  else
    puts("LOSE");
  return 0;
}
