#include <bits/stdc++.h>
int main() {
  int a, i, x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 0;
  for (i = 1; i <= 25; ++i) {
    scanf("%d", &a);
    if (a == 1) {
      break;
    }
  }
  if (i == 1 || i == 5 || i == 21 || i == 25) {
    printf("%d", x4);
  }
  if (i == 3 || i == 7 || i == 9 || i == 11 || i == 15 || i == 17 || i == 19 ||
      i == 23) {
    printf("%d", x2);
  }
  if (i == 2 || i == 4 || i == 6 || i == 10 || i == 16 || i == 20 || i == 22 ||
      i == 24) {
    printf("%d", x3);
  }
  if (i == 8 || i == 12 || i == 14 || i == 18) {
    printf("%d", x1);
  }
  if (i == 13) {
    printf("%d", x5);
  }
  return 0;
}
