#include <bits/stdc++.h>
using namespace std;
int R, C, N, x, y, Ans;
int Parent[3333 * 6666];
bool Land[3333][6666];
int Dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Find(int x) { return Parent[x] < 0 ? x : Parent[x] = Find(Parent[x]); }
void Union(int n1, int n2) {
  int r1 = Find(n1), r2 = Find(n2);
  if (r1 == r2) return;
  if (Parent[r1] < Parent[r2]) {
    Parent[r1] += Parent[r2];
    Parent[r2] = r1;
  } else {
    Parent[r2] += Parent[r1];
    Parent[r1] = r2;
  }
}
bool check(int x, int y) {
  for (int d1 = 0; d1 < 8; ++d1) {
    int newx1 = x + Dx[d1], newy1 = y + Dy[d1];
    if (newx1 < 1 || newx1 > R) continue;
    if (newy1 == 0) newy1 = 2 * C;
    if (newy1 > 2 * C) newy1 = 1;
    for (int d2 = 0; d2 < 8; ++d2) {
      int newx2 = x + Dx[d2], newy2 = y + C + Dy[d2];
      if (newx2 < 1 || newx2 > R) continue;
      if (newy2 == 0) newy2 = 2 * C;
      if (newy2 > 2 * C) newy2 = 1;
      if (Land[newx1][newy1] && Land[newx2][newy2] &&
          Find(newx1 * 6666 + newy1) == Find(newx2 * 6666 + newy2))
        return false;
    }
  }
  return true;
}
void add(int x, int y) {
  for (int d = 0; d < 8; ++d) {
    int newx = x + Dx[d], newy = y + Dy[d];
    if (newx < 1 || newx > R) continue;
    if (newy <= 0) newy += 2 * C;
    if (newy > 2 * C) newy -= 2 * C;
    if (Land[newx][newy]) Union(x * 6666 + y, newx * 6666 + newy);
  }
  Land[x][y] = true;
}
int main() {
  scanf("%d%d%d", &R, &C, &N);
  memset(Parent, -1, sizeof(Parent));
  while (N--) {
    scanf("%d%d", &x, &y);
    if (check(x, y)) {
      ++Ans;
      add(x, y);
      add(x, y + C);
    }
  }
  if (y == 1)
    puts("0");
  else
    printf("%d\n", Ans);
  return 0;
}
