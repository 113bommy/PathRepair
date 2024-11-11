#include <bits/stdc++.h>
int n, a[200010], x = 2e9, nn, tot, cnt, b[200010], c[200010];
bool fl, f[200010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), fl ^= (a[i] < 0);
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) c[++tot] = i, f[i] = 1;
  if (fl) {
    for (int i = 1; i <= n; i++)
      if (a[i] < 0 && -a[i] < x) x = -a[i], nn = i;
    if (tot) {
      if (tot > 1) {
        for (int i = 1; i < tot; i++) printf("1 %d %d\n", c[i], c[i + 1]);
        printf("1 %d %d\n", c[tot], nn);
      } else
        printf("1 %d %d\n", c[tot], nn);
    }
    if (tot < n - 1) {
      printf("%d %d\n", 2, nn);
      tot = 0;
      for (int i = 1; i <= n; i++)
        if (nn != i && a[i]) b[++tot] = i;
      for (int i = 1; i < tot; i++) printf("1 %d %d\n", b[i], b[i + 1]);
    }
  } else {
    if (tot) {
      if (tot > 1)
        for (int i = 1; i < tot; i++) printf("1 %d %d\n", c[i], c[i + 1]);
      if (tot < n - 1) {
        printf("2 %d\n", c[tot]);
        for (int i = 1; i <= n; i++)
          if (!f[i]) b[++cnt] = i;
        for (int i = 1; i < cnt; i++) printf("1 %d %d\n", b[i], b[i + 1]);
      }
    } else
      for (int i = 1; i < n; i++) printf("1 %d %d\n", i, i + 1);
  }
  return 0;
}
