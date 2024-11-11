#include <bits/stdc++.h>
int a, b, n, t1, t2;
char r[200005] = {0};
long long i, j, re, te;
int main() {
  scanf("%d %d", &a, &b);
  if (b == 0) {
    printf("%I64d\n", (long long)(a + b) * (a + b));
    for (i = 0; i < a; i++) printf("o");
    printf("\n");
  } else if (a == 0) {
    printf("%I64d\n", -(long long)(a + b) * (a + b));
    for (i = 0; i < b; i++) printf("x");
    printf("\n");
  } else {
    re = 100000;
    re = -re * re - 1;
    for (n = 1; n <= b; n++) {
      for (j = (n - 1 > 0 ? n - 1 : 1); j <= n + 1 && j <= a; j++) {
        te = (long long)(a - j + 1) * (a - j + 1) + j - 1 -
             (long long)(b / n) * (b / n) * (n - b % n) -
             (long long)(b / n + 1) * (b / n + 1) * (b % n);
        if (re < te) {
          re = te;
          t1 = j;
          t2 = n;
        }
      }
    }
    printf("%I64d\n", re);
    if (t1 < t2) {
      for (i = 0; i < t1 + t2; i++) {
        if (i % 2 == 0)
          for (j = 0; j < (i / 2 < b % t2 ? (b / t2 + 1) : (b / t2)); j++)
            printf("x");
        else
          for (j = 0; j < (i / 2 < t1 - 1 ? 1 : (a - t1 + 1)); j++) printf("o");
      }
    } else {
      for (i = 0; i < t1 + t2; i++) {
        if (i % 2 == 1)
          for (j = 0; j < (i / 2 < b % t2 ? (b / t2 + 1) : (b / t2)); j++)
            printf("x");
        else
          for (j = 0; j < (i / 2 < t1 - 1 ? 1 : (a - t1 + 1)); j++) printf("o");
      }
    }
    printf("\n");
    scanf("%I64d", &i);
  }
  return 0;
}
