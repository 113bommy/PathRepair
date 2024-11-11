#include <bits/stdc++.h>
int main() {
  int t, i, n, m, a, b;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  if (a * m <= b) {
    printf("%d\n", n * a);
  } else if ((b * (n / m) + a * (n % m)) > (b * ((n / m) + 1))) {
    printf("%d\n", b * (n / m) + b);
  } else
    printf("%d\n", b * (n / m) + a * (n % m) + 1);
  return 0;
}
