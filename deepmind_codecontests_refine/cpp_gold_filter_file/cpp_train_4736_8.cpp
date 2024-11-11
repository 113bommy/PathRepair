#include <bits/stdc++.h>
int main() {
  int n, c, k, a = 0, b, sum = 0, i;
  scanf("%d%d", &n, &k);
  scanf("%d", &c);
  for (i = 0; i < c; i++) {
    scanf("%d", &b);
    sum += (b - a - 1) / k;
    a = b;
  }
  sum += (n - a) / k;
  printf("%d\n", sum + c);
  return 0;
}
