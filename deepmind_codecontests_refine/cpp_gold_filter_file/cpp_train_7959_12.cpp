#include <bits/stdc++.h>
using namespace std;
int n, m, c, h, x, y, xx[4], yy[4], bst = 2e9, bsti;
int main() {
  scanf("%d %d %d %d %d", &n, &m, &c, &x, &y);
  for (int i = (0); i < (4); i++) xx[i] = x, yy[i] = y;
  for (int i = (0); i < (c - 1); i++) {
    scanf("%d %d", &x, &y);
    if (x + y > xx[0] + yy[0]) xx[0] = x, yy[0] = y;
    if (x - y > xx[1] - yy[1]) xx[1] = x, yy[1] = y;
    if (y - x > yy[2] - xx[2]) xx[2] = x, yy[2] = y;
    if (-x - y > -xx[3] - yy[3]) xx[3] = x, yy[3] = y;
  }
  scanf("%d", &h);
  for (int i = (0); i < (h); i++) {
    scanf("%d %d", &x, &y);
    int a = 0;
    for (int j = (0); j < (4); j++) a = max(a, abs(x - xx[j]) + abs(y - yy[j]));
    if (a < bst) bst = a, bsti = i + 1;
  }
  printf("%d\n%d\n", bst, bsti);
  return 0;
}
