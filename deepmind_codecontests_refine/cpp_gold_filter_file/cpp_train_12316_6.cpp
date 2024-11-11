#include <bits/stdc++.h>
int main() {
  int i = 1, k, l, m, p = 0, n, d, count = 0;
  scanf("%d\n%d\n%d\n%d\n%d", &k, &l, &m, &n, &d);
  while (i <= d) {
    if (i % k == 0) {
      count++;
    } else if (i % l == 0) {
      count++;
    } else if (i % m == 0) {
      count++;
    } else if (i % n == 0) {
      count++;
    }
    i++;
  }
  printf("%d", count);
}
