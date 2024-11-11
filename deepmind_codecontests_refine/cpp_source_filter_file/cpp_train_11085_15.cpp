#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n], i, x = 0, y = 0, z = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) x++;
    if (a[i] == 2) y++;
    if (a[i] == 3) z++;
  }
  if (x > y && x > z)
    printf("%d", n - x);
  else if (y > z && y > x)
    printf("%d", n - y);
  else if (z > x && z > y)
    printf("%d", n - z);
  return 0;
}
