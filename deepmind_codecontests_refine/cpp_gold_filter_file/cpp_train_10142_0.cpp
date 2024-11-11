#include <bits/stdc++.h>
int main() {
  int a, b, x = 0, y = 0, z = 0, i;
  scanf("%d%d", &a, &b);
  for (i = 1; i < 7; i++) {
    if (fabs(a - i) > fabs(b - i)) x++;
    if (fabs(a - i) < fabs(b - i)) y++;
    if (fabs(a - i) == fabs(b - i)) z++;
  }
  printf("%d %d %d\n", y, z, x);
  return 0;
}
