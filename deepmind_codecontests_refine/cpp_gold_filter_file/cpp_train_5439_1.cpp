#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, c, d, k, count = 0;
    scanf("%d", &n);
    if (n == 10 || n == 100 || n == 1000 || n == 10000) {
      printf("1\n");
      printf("%d\n", n);
    } else {
      if (n > 0) {
        a = n % 10;
        n = n - a;
        if (a > 0) count++;
        k = 1;
      }
      if (n >= 10) {
        b = n % 100;
        n = n - b;
        if (b > 0) count++;
        k = 2;
      }
      if (n >= 100) {
        c = n % 1000;
        n = n - c;
        if (c > 0) count++;
        k = 3;
      }
      if (n >= 1000) {
        d = n % 10000;
        n = n - d;
        if (d > 0) count++;
        k = 4;
      }
      if (k == 1 && a > 0) {
        printf("%d\n", k);
        printf("%d\n", a);
      } else if (k == 2) {
        printf("%d\n", count);
        if (a > 0) printf("%d ", a);
        if (b > 0) printf("%d \n", b);
      } else if (k == 3) {
        printf("%d\n", count);
        if (a > 0) printf("%d ", a);
        if (b > 0) printf("%d ", b);
        if (c > 0) printf("%d\n", c);
      } else if (k == 4) {
        printf("%d\n", count);
        if (a > 0) printf("%d ", a);
        if (b > 0) printf("%d ", b);
        if (c > 0) printf("%d ", c);
        if (d > 0) printf("%d\n", d);
      }
    }
  }
  return 0;
}
