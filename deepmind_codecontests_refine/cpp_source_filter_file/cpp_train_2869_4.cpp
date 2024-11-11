#include <bits/stdc++.h>
int main(void) {
  int n, i;
  scanf("%d", &n);
  char a[n][100], b[n];
  int c[n];
  for (i = 0; i < n; i++) {
    scanf("%s", &a[i][0]);
    b[i] = a[i][0];
    c[i] = (int)strlen(&a[i][0]);
  }
  for (i = 0; i < n; i++) {
    if (c[i] > 10)
      printf("%c%d%c\n", a[i][0], c[i] - 2, a[i][c[i] - 1]);
    else
      printf("%s\n", &a[i][0]);
  }
  return 0;
}
