#include <bits/stdc++.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  b = b / 2;
  c = c / 4;
  if (a < b && a < c)
    printf("%d\n", 7 * a);
  else if (b < c && b < a)
    printf("%d\n", 7 * b);
  else
    printf("%d\n", 7 * c);
  return 0;
}
