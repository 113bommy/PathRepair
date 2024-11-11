#include <bits/stdc++.h>
int main() {
  int a, d;
  scanf("%d", &a);
  if (a < 5) {
    d = 1;
    printf("%d\n", d);
  } else {
    if (a % 5 != 0) {
      d = a / 5 + 1;
      printf("%d\n", d);
    } else if (a % 5 == 0) {
      d = a / 5;
      printf("%d\n", d);
    }
  }
  return 0;
}
