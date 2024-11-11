#include <bits/stdc++.h>
int main() {
  char a[105][105], x;
  int i, j, n, c;
  scanf("%d", &n);
  scanf("%c", &x);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%c", &a[i][j]);
    }
    scanf("%c", &x);
  }
  for (i = 1; i < n - 1; i++) {
    for (j = 1; j < n - 1; j++) {
      if (a[i][j] == '#' && a[i - 1][j] == '#' && a[i + 1][j] == '#' &&
          a[i][j - 1] == '#' && a[i][j + 1] == '#') {
        a[i][j] = a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = '.';
      }
    }
  }
  c = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '#') c = 0;
    }
  }
  if (c == 0)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
