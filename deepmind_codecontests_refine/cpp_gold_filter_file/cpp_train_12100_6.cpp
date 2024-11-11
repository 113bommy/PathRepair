#include <bits/stdc++.h>
int main() {
  int x, y, a, b, t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    if ((y - x) % (a + b) == 0)
      printf("%d\n", (y - x) / (a + b));
    else
      printf("-1\n");
  }
  return 0;
}
