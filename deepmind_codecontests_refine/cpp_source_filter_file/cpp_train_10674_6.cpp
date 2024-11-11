#include <bits/stdc++.h>
int main() {
  int n, a, b, c;
  scanf("%d", &n);
  if ((n > 0) && (n < 1000000)) {
    a = (n / 7) * 2;
    b = n % 7;
    switch (b) {
      case 0:
        printf("%d %d", a, a);
        break;
      case 1:
        printf("%d %d", a, a + 1);
        break;
      case 6:
        printf("%d %d", a + 1, a + 2);
        break;
      default:
        printf("%d %d", a, a + 2);
    }
  }
  return 0;
}
