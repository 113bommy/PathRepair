#include <bits/stdc++.h>
int main() {
  int n, i, u = 0, v = 0, w = 0;
  scanf("%d", &n);
  int a, x[n], y[n], z[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a < 0) {
      x[u] = a;
      u++;
    } else if (a > 0) {
      y[v] = a;
      v++;
    } else {
      z[w] = a;
      w++;
    }
  }
  if (v == 0) {
    y[v] = x[u - 1];
    y[v + 1] = x[u - 2];
    v += 2;
    u -= 2;
  }
  if (u % 2 == 0) {
    z[w] = x[u - 1];
    w++;
    u--;
  }
  printf("%d ", u);
  for (i = 0; i < u; i++) printf("%d ", x[i]);
  printf("\n%d ", v);
  for (i = 0; i < v; i++) printf("%d ", y[i]);
  printf("\n%d ", w);
  for (i = 0; i < w; i++) printf("%d ", z[i]);
  return 0;
}
