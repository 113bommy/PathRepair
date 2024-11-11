#include <bits/stdc++.h>
int main() {
  int i, n, x, y, z, a = 0, b = 0, c = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    a += x;
    b += y;
    c += z;
  }
  if (a == b && b == c && a == c)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
