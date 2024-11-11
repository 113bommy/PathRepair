#include <bits/stdc++.h>
int main() {
  char a[1001];
  int n, m, c = 0, i, j = 0, k = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%s", &a);
    if (i == n) {
      for (j = 0; j < m - 1; j++) {
        if (a[j] == 'B')
          c++;
        else {
          if (c > 0) {
            c = 0;
            k++;
          }
        }
      }
      if (a[m - 2] == 'B') k++;
    }
  }
  printf("%d", k);
  return 0;
}
