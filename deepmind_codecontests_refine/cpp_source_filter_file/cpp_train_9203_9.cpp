#include <bits/stdc++.h>
int main() {
  int n, a, b, c, d, i;
  bool flat = false;
  scanf("%d", &n);
  for (i = 0; i < 4; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a > b) {
      a = b;
    }
    if (c > d) {
      c = d;
    }
    if (a + c <= n) {
      printf("%d %d %d\n", i + 1, a, n - a);
      flat = true;
    }
  }
  if (!flat) puts("-1");
  return 0;
}
