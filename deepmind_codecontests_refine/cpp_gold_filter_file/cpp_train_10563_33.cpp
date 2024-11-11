#include <bits/stdc++.h>
int main() {
  int i, j, n, m, l1, l2;
  scanf("%d%d", &n, &m);
  char a[3001][11], b[3001][11], ss[11];
  for (i = 0; i < m; i++) scanf("%s%s", a[i], b[i]);
  for (j = 0; j < n; j++) {
    scanf("%s", ss);
    for (i = 0; i < m; i++)
      if (strcmp(ss, a[i]) == 0) {
        l1 = strlen(a[i]);
        l2 = strlen(b[i]);
        if (l1 <= l2)
          printf("%s ", a[i]);
        else
          printf("%s ", b[i]);
      }
  }
}
