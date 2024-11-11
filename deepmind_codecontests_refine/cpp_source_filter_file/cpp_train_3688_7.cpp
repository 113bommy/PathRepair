#include <bits/stdc++.h>
int main() {
  int n, i, d, e, f, years = 0;
  scanf("%d", &n);
  int y[n - 1];
  for (i = 0; i < n - 1; i++) scanf("%d", &y[i]);
  {
    scanf("%d%d", &e, &f);
    d = f - e;
  }
  for (i = 0; i < d; i++) {
    years = years + y[i];
  }
  printf("%d\n", years);
  return 0;
}
