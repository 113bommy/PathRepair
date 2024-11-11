#include <bits/stdc++.h>
int main() {
  int n, a, g = 0, s = 0, f[10], e = 0, q = 0, p, c[110];
  scanf("%d", &n);
  memset(c, 0, sizeof(c));
  while (n--) {
    scanf("%d", &a);
    if (c[a])
      continue;
    else
      c[a] = 1;
    int x = a % 10, y = a / 10 % 10, ans = 1;
    if (x && y) {
      q = 1;
      p = a;
      continue;
    }
    if (x && g) ans = 0;
    if (y && s) ans = 0;
    if (ans) {
      f[++e] = a;
      if (x) g = 1;
      if (y) s = 1;
    }
  }
  if (g == 0 && s == 0 && q)
    printf("%d\n%d ", e + 1, p);
  else
    printf("%d\n", e);
  for (int i = 1; i <= e; i++) printf("%d ", f[i]);
  printf("\n");
}
