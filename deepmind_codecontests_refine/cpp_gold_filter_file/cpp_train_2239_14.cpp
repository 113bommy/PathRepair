#include <bits/stdc++.h>
int main() {
  int x, y, z, t1, t2, t3, t4;
  scanf("%d%d%d", &x, &y, &z);
  t1 = x + y + z;
  t2 = 2 * (x + y);
  t3 = x + z + z + x;
  t4 = y + z + z + y;
  int min = 900000000;
  if (t1 < min) min = t1;
  if (t2 < min) min = t2;
  if (t3 < min) min = t3;
  if (t4 < min) min = t4;
  printf("%d", min);
  return 0;
}
