#include <bits/stdc++.h>
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) > 0) {
    char a[100][100], r = '0';
    int i, j, color[100] = {0}, s = 0;
    for (i = 0; i < n; i++) scanf("%s", a[i]);
    for (i = 0; i < m; i++) {
      r = '0';
      for (j = 0; j < n; j++)
        if (r < a[j][i]) {
          r = a[j][i];
        }
      for (j = 0; j < n; j++)
        if (a[j][i] == r && color[j] == 0) {
          color[j] = 1;
          s++;
        }
    }
    printf("%d\n", s);
  }
  return 0;
}
