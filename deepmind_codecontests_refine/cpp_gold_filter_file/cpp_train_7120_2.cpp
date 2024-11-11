#include <bits/stdc++.h>
char s[1000];
int a[200], b[200], c[200][200], n, m, p, q;
int main() {
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 1; j <= n; j++)
      if (s[j - 1] == '.') {
        c[i][j] = 1;
        a[i]++;
        b[j]++;
      }
  }
  p = 1;
  q = 0;
  for (int i = 1; i <= n; i++)
    if (!a[i]) p = 0;
  if (p) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (c[i][j]) {
          printf("%d %d\n", i, j);
          break;
        }
    }
    return 0;
  }
  p = 1;
  for (int i = 1; i <= n; i++)
    if (!b[i]) p = 0;
  if (p) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (c[j][i]) {
          printf("%d %d\n", j, i);
          break;
        }
    }
    return 0;
  }
  printf("-1\n");
  return 0;
}
