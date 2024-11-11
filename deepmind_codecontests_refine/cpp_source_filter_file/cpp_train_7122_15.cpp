#include <bits/stdc++.h>
int a[100010], b[100010], c[100010];
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (0); i < m; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  int sum = 0;
  for (int i = (0); i < m; i++) {
    if (a[i] == b[i]) continue;
    for (int j = (0); j < m; j++) {
      if (a[j] == b[j]) continue;
      if (b[i] == a[j])
        if (c[i] >= c[j]) {
          c[i] -= c[j];
          a[j] = a[i];
          if (a[j] == b[j]) c[j] = 0;
        } else {
          c[j] -= c[i];
          a[i] = a[j];
          if (a[i] == b[j]) c[i] = 0;
        }
      else if (a[i] == b[j]) {
        if (c[i] >= c[j]) {
          c[i] -= c[j];
          b[j] = b[i];
          if (a[j] == b[j]) c[j] = 0;
        } else {
          c[j] -= c[i];
          a[i] = a[j];
          if (a[i] == b[i]) c[i] = 0;
        }
      }
    }
  }
  for (int i = (0); i < m; i++) sum += c[i];
  printf("%d\n", sum);
  return 0;
}
