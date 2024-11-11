#include <bits/stdc++.h>
using namespace std;
bool T[2005][2005], a[2005][2005];
int x[2005 * 2005], y[2005 * 2005], dx[8], dy[8];
char ch;
int n, i, j, cnt, h, t, circle, square;
void add(int X, int Y) {
  if (a[X][Y]) x[++t] = X, y[t] = Y, a[X][Y] = 0;
}
void calc(int x, int y) {
  if (x < dx[0] || x == dx[0] && y < dy[0]) dx[0] = x, dy[0] = y;
  if (x < dx[1] || x == dx[1] && y > dy[1]) dx[1] = x, dy[1] = y;
  if (x > dx[2] || x == dx[2] && y > dy[2]) dx[2] = x, dy[2] = y;
  if (x > dx[3] || x == dx[3] && y < dy[3]) dx[3] = x, dy[3] = y;
  if (y < dy[4] || y == dy[4] && x > dx[4]) dx[4] = x, dy[4] = y;
  if (y < dy[5] || y == dy[5] && x < dx[5]) dx[5] = x, dy[5] = y;
  if (y > dy[6] || y == dy[6] && x > dx[6]) dx[6] = x, dy[6] = y;
  if (y > dy[7] || y == dy[7] && x < dx[7]) dx[7] = x, dy[7] = y;
}
int sqr(int x) { return x * x; }
void work() {
  a[i][j] = 0;
  h = 0, t = 1;
  int r = 0;
  while (h < t) {
    int X = x[++h], Y = y[h];
    add(X - 1, Y);
    add(X, Y - 1);
    add(X, Y + 1);
    add(X + 1, Y);
  }
  if (t <= 80) return;
  dx[0] = dy[0] = n + 1;
  dx[1] = n + 1;
  dy[1] = 0;
  dx[2] = dy[3] = 0;
  dx[3] = 0;
  dy[4] = n + 1;
  dy[4] = n + 1;
  dx[4] = 0;
  dy[5] = dx[5] = n + 1;
  dy[6] = dx[6] = 0;
  dy[7] = 0;
  dx[7] = n + 1;
  for (int i = 1; i <= t; i++) calc(x[i], y[i]);
  for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++)
      r = max((int)sqrt(sqr(dx[i] - dx[j]) + sqr(dy[i] - dy[j])), r);
  if (t * 1. / r / r >= 0.6225)
    circle++;
  else
    square++;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      ch = ' ';
      while (ch != '0' && ch != '1') ch = getchar();
      T[i][j] = ch - '0';
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      a[i][j] = T[i][j] |
                (T[i - 1][j] + T[i][j - 1] + T[i][j + 1] + T[i + 1][j] >= 3);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (a[i][j]) x[1] = i, y[1] = j, work();
  printf("%d %d\n", circle, square);
}
