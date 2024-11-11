#include <bits/stdc++.h>
using namespace std;
int a[1010][1010], up[1101010], down[1101010], left1[1101010], right1[1101010],
    b[1010][1010];
void input(int &x) {
  char ch;
  while (ch = getchar(), ch == ' ' || ch == '\n')
    ;
  x = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
int getid(int x, int y) { return x * 1000 + y; }
int getx(int id) { return id / 1000; }
int gety(int id) { return id % 1000; }
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int id = getid(i, j);
      up[id] = getid(i - 1, j);
      down[id] = getid(i + 1, j);
      left1[id] = getid(i, j - 1);
      right1[id] = getid(i, j + 1);
    }
  for (int i = 1; i <= m; i++)
    down[getid(0, i)] = getid(1, i), up[getid(n + 1, i)] = getid(n, i);
  for (int i = 1; i <= n; i++)
    right1[getid(i, 0)] = getid(i, 1), left1[getid(i, m + 1)] = getid(i, m);
  while (q-- > 0) {
    int x, y, x1, y1, x2, y2, w, h, nx, ny;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
    int id1, id2;
    id1 = getid(0, y1);
    for (int i = 1; i <= x1; i++) id1 = down[id1];
    id2 = getid(0, y2);
    for (int i = 1; i <= x2; i++) id2 = down[id2];
    for (int i = 1; i <= w; i++) {
      swap(down[up[id1]], down[up[id2]]);
      swap(up[id1], up[id2]);
      if (i != w) id1 = right1[id1], id2 = right1[id2];
    }
    for (int i = 1; i <= h; i++) {
      swap(left1[right1[id1]], left1[right1[id2]]);
      swap(right1[id1], right1[id2]);
      if (i != h) id1 = down[id1], id2 = down[id2];
    }
    for (int i = 1; i <= w; i++) {
      swap(up[down[id1]], up[down[id2]]);
      swap(down[id1], down[id2]);
      if (i != w) id1 = left1[id1], id2 = left1[id2];
    }
    for (int i = 1; i <= h; i++) {
      swap(right1[left1[id1]], right1[left1[id2]]);
      swap(left1[id1], left1[id2]);
      if (i != h) id1 = up[id1], id2 = up[id2];
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = i, y = 0, id = getid(i, 0);
    for (int j = 1; j <= m; j++) {
      id = right1[id];
      x = getx(id);
      y = gety(id);
      b[i][j] = a[x][y];
    }
  }
  for (int i = 1; i <= n; i++, printf("\n"))
    for (int j = 1; j <= m; j++) printf("%d ", b[i][j]);
  return 0;
}
