#include <bits/stdc++.h>
int a, b;
int main() {
  scanf("%d%d", &a, &b);
  if ((a == 0) && (b != 0))
    printf("Impossible");
  else if ((a == 0) && (b == 0))
    printf("0");
  else if ((b < a) && (b > 0))
    printf("%d %d", a, a + b - 1);
  else if (b < a)
    printf("%d %d", a, a);
  else
    printf("%d %d", b, a + b - 1);
}
