#include <bits/stdc++.h>
int main() {
  long n, i, d, a, m;
  scanf("%ld", &n);
  for (i = 0; i < 1000; i++) {
    d = n - i * i;
    if (d <= 0) {
      a = i;
      break;
    }
  }
  if (a * (a - 1) - n >= 0) {
    m = 2 * (2 * a - 1);
    printf("%ld", m);
  } else {
    m = 4 * a;
    printf("%ld", m);
  }
  return 0;
}
