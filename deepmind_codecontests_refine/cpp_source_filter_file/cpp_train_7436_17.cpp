#include <bits/stdc++.h>
char po[105];
int main() {
  int len, i, loc, n;
  while (scanf("%d%d%s", &n, &loc, po) != EOF) {
    len = strlen(po);
    if (len % 2 == 0) {
      if (loc > len / 2 + 0.5) {
        for (i = loc; i < len; i++) printf("RIHGT\n");
        for (i = len - 1; i > 0; i--) {
          printf("PRINT %c\nLEFT\n", po[i]);
        }
        printf("PRINT %c\n", po[i]);
      } else {
        for (i = loc - 1; i > 0; i--) printf("LEFT\n");
        for (i = 0; i < len - 2; i++) {
          printf("PRINT %c\nRIGHT\n", po[i]);
        }
        printf("PRINT %c\n", po[i]);
      }
    } else {
      if (loc >= len / 2 + 1) {
        for (i = loc; i < len; i++) printf("RIHGT\n");
        for (i = len - 1; i > 0; i--) {
          printf("PRINT %c\nLEFT\n", po[i]);
        }
        printf("PRINT %c\n", po[i]);
      } else {
        for (i = loc - 1; i > 0; i--) printf("LEFT\n");
        for (i = 0; i < len - 2; i++) {
          printf("PRINT %c\nRIGHT\n", po[i]);
        }
        printf("PRINT %c\n", po[i]);
      }
    }
  }
  return 0;
}
