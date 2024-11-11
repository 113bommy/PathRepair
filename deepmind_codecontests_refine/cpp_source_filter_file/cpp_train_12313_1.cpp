#include <bits/stdc++.h>
int main() {
  int a, x, y;
  double i;
  scanf("%d %d %d", &a, &x, &y);
  i = a / 2;
  if ((0 < y) && (y < a) && (-i < x) && (x < i))
    printf("1");
  else if ((abs(x) >= a) || (y % a == 0) || ((x == 0) && (y / a % 2 == 0)) ||
           ((abs(x) >= i) && (y < a)))
    printf("-1");
  else if ((y / a % 2 == 1) &&
           (((-a <= x) && (x <= -i)) || ((i <= x) && (x <= a))))
    printf("-1");
  else if (y / a % 2 == 1)
    printf("%d", ((y / a) / 2) * 3 + 2);
  else if (x < 0)
    printf("%d", ((y / a) / 2) * 3);
  else
    printf("%d", ((y / a) / 2) * 3 + 1);
  return 0;
}
