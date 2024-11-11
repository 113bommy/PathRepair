#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a < b && abs(a - b) == 1) {
    printf("%d9 %d0\n", a, b);
  } else if (a == b) {
    printf("%d1 %d2\n", a, b);
  } else if (a == 9 && b == 1) {
    printf("%d %d0", a, b);
  } else if (abs(a - b) >= 2 || a > b) {
    printf("-1\n");
  }
  return 0;
}
