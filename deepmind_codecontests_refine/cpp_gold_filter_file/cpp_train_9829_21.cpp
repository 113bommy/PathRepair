#include <bits/stdc++.h>
int main() {
  int i, j, a, b, n, m;
  int s[100][100];
  while (scanf("%d%d", &n, &m) != EOF) {
    a = 0;
    b = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &s[i][j]);
        if (s[i][j] == 1 && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
          a++;
        else if (s[i][j] == 1)
          b++;
      }
    }
    if (a > 0)
      printf("2\n");
    else
      printf("4\n");
  }
  return 0;
}
