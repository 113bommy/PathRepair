#include <bits/stdc++.h>
using namespace std;
int main() {
  int r1, c1, r2, c2;
  scanf("%d %d", &r1, &c1);
  scanf("%d %d", &r2, &c2);
  int dx = max(c1 - c2, c2 - c1);
  int dy = max(r1 - r2, r2 - r1);
  int ra;
  if (c1 == c2 && r1 == r2) {
    printf("0 0 0\n");
    return 0;
  }
  if (dx == 0 || dy == 0)
    ra = 1;
  else
    ra = 2;
  int rb;
  if (dx == dy)
    rb = 1;
  else if ((r1 + c1) % 2 == (r2 + c2) % 2)
    rb = 2;
  else
    rb = 0;
  printf("%d %d %d\n", ra, rb, max(dx, dy));
  return 0;
}
