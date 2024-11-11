#include <bits/stdc++.h>
int main() {
  int i, n, t, a, d = 86400, l, c = 0;
  scanf("%d%d", &n, &t);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    l = d - a;
    c++;
    if (l >= t) break;
  }
  printf("%d\n", c);
  return 0;
}
