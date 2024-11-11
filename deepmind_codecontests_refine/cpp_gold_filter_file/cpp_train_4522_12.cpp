#include <bits/stdc++.h>
char a, c;
int b, d, i;
int main() {
  scanf("%c%d %c%d", &a, &b, &c, &d);
  if (a < c) {
    if (b < d) {
      if (c - a < d - b) {
        printf("%d\n", d - b);
        for (i = 1; i < c - a; i++) printf("RU\n");
        for (i = 1; i <= (d - b) - (c - a); i++) printf("U\n");
      } else {
        printf("%d\n", c - a);
        for (i = 1; i <= d - b; i++) printf("RU\n");
        for (i = 1; i <= (c - a) - (d - b); i++) printf("R\n");
      }
    } else {
      if ((c - a) < (b - d)) {
        printf("%d\n", b - d);
        for (i = 1; i <= c - a; i++) printf("RD\n");
        for (i = 1; i <= (b - d) - (c - a); i++) printf("D\n");
      } else {
        printf("%d\n", c - a);
        for (i = 1; i <= b - d; i++) printf("RD\n");
        for (i = 1; i <= (c - a) - (b - d); i++) printf("R\n");
      }
    }
  } else {
    if (b < d) {
      if (d - b < a - c) {
        printf("%d\n", a - c);
        for (i = 1; i <= (a - c) - (d - b); i++) printf("L\n");
        for (i = 1; i <= d - b; i++) printf("LU\n");
      } else {
        printf("%d\n", d - b);
        for (i = 1; i <= a - c; i++) printf("LU\n");
        for (i = 1; i <= (d - b) - (a - c); i++) printf("U\n");
      }
    } else {
      if (a - c < b - d) {
        printf("%d\n", b - d);
        for (i = 1; i <= a - c; i++) printf("LD\n");
        for (i = 1; i <= (b - d) - (a - c); i++) printf("D\n");
      } else {
        printf("%d\n", a - c);
        for (i = 1; i <= (a - c) - (b - d); i++) printf("L\n");
        for (i = 1; i <= b - d; i++) printf("LD\n");
      }
    }
  }
  return 0;
}
