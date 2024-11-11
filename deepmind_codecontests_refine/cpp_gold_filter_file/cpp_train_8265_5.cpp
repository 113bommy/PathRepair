#include <bits/stdc++.h>
long w[4];
int main() {
  long i, j, k, k1, k2, t, an, x, y;
  char c;
  scanf("%ld", &t);
  for (; t; t--) {
    for (i = 0; i < 4; i++) {
      w[i] = 0;
    }
    k = 5;
    an = 1;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        scanf("%c", &c);
        while (c != 'K' && c != '.' && c != '#') {
          scanf("%c", &c);
        }
        if (c != '#') {
          w[(i + j) % 4] = 1;
        }
        if (c == 'K') {
          if (k > 4) {
            k = (i + j) % 4;
            x = i;
            y = j;
          } else {
            if (k != ((i + j) % 4)) {
              an = 0;
            }
            if (!((((i - x + 64) / 2) % 2 == 0) &&
                  (((j - y + 64) / 2) % 2 == 0))) {
              an = 0;
            }
          }
        }
      }
    }
    if (an && w[k]) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
