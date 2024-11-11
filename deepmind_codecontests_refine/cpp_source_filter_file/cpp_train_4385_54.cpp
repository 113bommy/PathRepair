#include <bits/stdc++.h>
int main() {
  int x, y, z, t1, t2, t3, s, e, dif1, dif2;
  scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);
  if (y > x)
    dif1 = y - x;
  else
    dif1 = x - y;
  if (x > z)
    dif2 = x - z;
  else
    dif2 = z - x;
  if ((2 * t3 + t2 * dif1 + t2 * dif2) > dif1 * t1)
    printf("NO");
  else
    printf("YES");
}
