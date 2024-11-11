#include <bits/stdc++.h>
int main() {
  int b, a;
  scanf("%d%d", &a, &b);
  if ((a == 9) && (b == 1)) {
    printf("99 100");
  } else if (a == b) {
    a = a * 100 + 12;
    b = b * 100 + 13;
    printf("%d %d\n", a, b);
  } else if ((b - a) == 1) {
    a = a * 100 + 99;
    b = b * 100;
    printf("%d %d\n", a, b);
  } else
    printf("-1");
}
