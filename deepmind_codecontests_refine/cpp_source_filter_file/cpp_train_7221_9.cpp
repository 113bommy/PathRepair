#include <bits/stdc++.h>
int main() {
  int a[6][6], c, w, i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1) {
        c = j;
        w = i;
      }
    }
  }
  if (c > 3)
    c = c - 3;
  else
    c = 3 - c;
  if (w > 3)
    w = w - 3;
  else
    w = 3 - w;
  printf("%d", w + c);
}
