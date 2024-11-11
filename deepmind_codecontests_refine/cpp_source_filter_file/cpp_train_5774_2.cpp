#include <bits/stdc++.h>
int main() {
  int i, j, n, cnt, yes;
  static char a[100][101];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%s", a[i]);
  yes = 1;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      cnt = 0;
      if (i > 0 && a[i - 1][j] == 'o') cnt++;
      if (i + 1 < n && a[i + 1][j] == 'o') cnt++;
      if (i > 0 && a[i][j - 1] == 'o') cnt++;
      if (j + 1 < n && a[i][j + 1] == 'o') cnt++;
      if (cnt % 2 != 0) {
        yes = 0;
        break;
      }
    }
  printf("%s\n", yes ? "YES" : "NO");
  return 0;
}
