#include <bits/stdc++.h>
int main() {
  int i, t;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if ((a + b) > (c + d))
      printf("%d\n", a + b);
    else
      printf("%d\n", c + d);
  }
  return 0;
}
