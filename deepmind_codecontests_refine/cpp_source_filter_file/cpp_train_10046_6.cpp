#include <bits/stdc++.h>
int mini(int x, int y) { return (x > y) ? y : x; }
int main() {
  int n, x1, y1, x2, y2, sum = 0;
  scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
  if ((x1 == 0 && x2 == n || x1 == 0 && x2 == n) && (y1 != 0 || y1 != n)) {
    sum = (x1 + x2 + n);
  } else if ((y1 == 0 && y2 == n || y1 == n && y2 == 0) &&
             (x1 != 0 || x1 != n)) {
    sum = y1 + y2 + n;
  } else {
    sum = abs(x1 - x2) + abs(y1 - y2);
  }
  printf("%d", mini(sum, (4 * n - sum)));
}
