#include <bits/stdc++.h>
int main() {
  int x, y, z, a, b, c;
  scanf("%d %d %d", &x, &y, &z);
  scanf("%d %d %d", &a, &b, &c);
  if (a < x) {
    printf("NO");
  } else if ((a + b + c) < (x + y + z)) {
    printf("NO");
  } else {
    a = a - x;
    if (((y + z) <= a + b + c) && y < (a + b))
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}
