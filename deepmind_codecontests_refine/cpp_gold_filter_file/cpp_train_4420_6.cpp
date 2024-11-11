#include <bits/stdc++.h>
int main() {
  char a[1000], b[50];
  gets(a);
  int c = 1, x, d = 1, e, i, j;
  x = strlen(a);
  b[0] = a[1];
  for (i = 4; i < x; i = i + 3) {
    for (j = 0; j < d; j++) {
      e = 1;
      if (a[i] == b[j]) {
        e = 0;
        break;
      }
    }
    if (e == 1) {
      b[c] = a[i];
      c++;
    }
    d++;
  }
  if (a[1] > 96 && a[1] < 123)
    printf("%d", c);
  else
    printf("0");
}
