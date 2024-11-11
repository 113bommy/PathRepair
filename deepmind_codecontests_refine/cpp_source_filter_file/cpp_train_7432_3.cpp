#include <bits/stdc++.h>
using namespace std;
const int S = 233, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, w, h, st[S], su;
bool a[S][S];
void fill(int x, int y) {
  a[x][y] = true;
  if (!(x & 1) && !(y & 1)) ++su;
  int xx, yy;
  for (int i = 0; i < 4; i++) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (xx >= 1 && xx <= (w << 1 | 1) && yy >= 1 && yy <= (h << 1 | 1) &&
        !a[xx][yy])
      fill(xx, yy);
  }
}
int main() {
  scanf("%d%d%d", &w, &h, &n);
  for (int i = 1; i <= w + 1; ++i)
    for (int j = 1; j <= h + 1; ++j) a[2 * i - 1][2 * j - 1] = true;
  int x1, x2, y1, y2;
  while (n--) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2)
      for (int i = y1; i <= y2; i++) a[2 * x1 + 1][i * 2] = true;
    else
      for (int i = x1; i <= x2; i++) a[i * 2][2 * y1 + 1] = true;
  }
  for (int i = 1; i <= 2 * w + 1; i++)
    for (int j = 1; j <= 2 * h + 1; j++)
      if (!a[i][j]) {
        su = 0;
        fill(i, j);
        st[++st[0]] = su;
      }
  sort(st + 1, st + 1 + st[0]);
  for (int i = 1; i <= st[0]; i++) printf("%d ", st[i]);
  return 0;
}
