#include <bits/stdc++.h>
int main() {
  char s[15];
  int m, i, j, x, a[6], b[15], y;
  scanf("%d ", &m);
  for (j = 0; j < m; j++) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    x = 0;
    y = 0;
    gets(s);
    for (i = 0; i <= 11; i++) {
      if (s[i] == 'X') {
        b[i] = 1;
        a[0] = 1;
      } else {
        y = 1;
      }
    }
    if (y == 0)
      memset(a, 1, sizeof(a));
    else {
      if (b[0] * b[6] || b[1] * b[7] || b[2] * b[8] || b[3] * b[9] ||
          b[4] * b[10] || b[5] * b[11])
        a[1] = 1;
      if (b[0] * b[4] * b[8] || b[1] * b[5] * b[9] || b[2] * b[6] * b[10] ||
          b[3] * b[7] * b[11])
        a[2] = 1;
      if (b[0] * b[3] * b[6] * b[9] || b[1] * b[4] * b[7] * b[10] ||
          b[2] * b[5] * b[8] * b[11])
        a[3] = 1;
      if (b[0] * b[2] * b[4] * b[6] * b[8] * b[10] ||
          b[1] * b[3] * b[5] * b[7] * b[9] * b[11])
        a[4] = 1;
    }
    for (i = 0; i < 6; i++)
      if (a[i]) x++;
    printf("%d ", x);
    if (a[0]) printf("1*12 ");
    if (a[1]) printf("2*6 ");
    if (a[2]) printf("3*4 ");
    if (a[3]) printf("4*3 ");
    if (a[4]) printf("6*2 ");
    if (a[5]) printf("12*1 ");
    printf("\n");
  }
  return 0;
}
