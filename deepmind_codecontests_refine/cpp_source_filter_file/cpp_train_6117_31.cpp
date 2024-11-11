#include <bits/stdc++.h>
int main() {
  int n, m, x[10], y[100], i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &x[i]);
  for (i = 0; i < m; i++) scanf("%d", &y[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (x[i] == y[j]) printf("%d", x[i]);
  return 0;
}
