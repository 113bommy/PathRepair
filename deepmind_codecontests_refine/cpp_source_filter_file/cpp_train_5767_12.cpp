#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int sx, sy, ex, ey;
  scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
  int x = ex - sx;
  char charX;
  if (x >= 0)
    charX = 'E';
  else {
    x = (-1) * x;
    charX = 'W';
  }
  int y = ey - sy;
  char charY;
  if (x >= 0)
    charY = 'N';
  else {
    y = (-1) * y;
    charY = 'S';
  }
  char c[n + 5];
  scanf("%s", c);
  int i;
  ;
  for (i = 0; i < n; i++) {
    if (c[i] == charX && x > 0)
      x--;
    else if (c[i] == charY && y > 0)
      y--;
    if (x == 0 && y == 0) break;
  }
  if (i == n)
    printf("-1");
  else
    printf("%d", i + 1);
  return 0;
}
