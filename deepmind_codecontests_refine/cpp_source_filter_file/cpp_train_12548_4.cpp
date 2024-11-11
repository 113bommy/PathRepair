#include <bits/stdc++.h>
int main() {
  int i, j, k, n;
  long long a, b, c;
  scanf("%d", &n);
  if (n == 2)
    printf("-1\n");
  else {
    printf("6\n");
    a = 3;
    for (i = 2; i <= n - 1; i++) {
      printf("%I64d\n", a * 7);
      a = 3 * a;
    }
    printf("56\n");
  }
  return 0;
}
