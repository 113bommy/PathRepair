#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a > b) {
    printf("%d ", b);
    a = a - b;
    printf("%d", a / 2);
  } else {
    printf("%d", a);
    b = b - a;
    printf("%d", b / 2);
  }
  return 0;
}
