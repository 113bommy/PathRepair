#include <bits/stdc++.h>
int main() {
  int y, i, j, k, l, c, a[1005], t = 0, s, p;
  scanf("%d", &y);
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      for (k = 0; k < 9; k++) {
        for (l = 0; l < 9; l++) {
          c = i * 1000 + j * 100 + k * 10 + l;
          if (c > y && i != j && i != k && i != l && j != k && j != l &&
              k != l) {
            a[t] = c;
            t++;
            break;
          }
        }
      }
    }
  }
  s = a[0];
  for (p = 0; p < t; p++) {
    if (a[p] < s) {
      s = a[p];
    }
  }
  printf("%d", s);
}
