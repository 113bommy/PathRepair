#include <bits/stdc++.h>
int main() {
  int s = 0, n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  if (a * m > b) {
    s = (n / m) * b + (n % m) * a;
    if (a > b) {
      if (n % m != 0) s = ((n / m) + 1) * b;
    }
  } else {
    s += a * n;
  }
  if (s > b) s = b;
  printf("%d\n", s);
  return 0;
}
