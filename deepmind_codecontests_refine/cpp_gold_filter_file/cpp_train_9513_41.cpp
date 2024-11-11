#include <bits/stdc++.h>
int main() {
  int i, j, n, m, k, sum;
  scanf("%d%d", &n, &m);
  if (m == 3 && (n == 5 || n == 6)) {
    puts("-1");
    return 0;
  }
  sum = 0;
  for (i = 1; i <= m; i++) {
    sum += 128 - i;
    printf("%d %d\n", i + 10000, sum);
  }
  n -= m;
  sum = 0;
  for (i = 1; i <= n; i++) {
    sum += 128 - i;
    printf("%d %d\n", -i, sum);
  }
  return 0;
}
