#include <bits/stdc++.h>
typedef struct {
  int dollar;
  int cent;
} money;
money q[110];
int w[110];
int main() {
  int i, j, n, m, k = 0, l = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d%d", &q[i].dollar, &q[i].cent);
  for (i = 1; i <= n; i++) {
    if (q[i].dollar < m || (q[i].dollar == m && q[i].cent == 0)) {
      if (!k) k = 1;
      if (q[i].cent == 0)
        continue;
      else
        l = (l > 100 - q[i].cent) ? l : 100 - q[i].cent;
    }
  }
  if (!k)
    printf("-1\n");
  else
    printf("%d\n", l);
  return 0;
}
