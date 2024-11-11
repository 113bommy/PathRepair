#include <bits/stdc++.h>
int main() {
  int n, a, b, m;
  scanf("%d%d%d", &n, &a, &b);
  m = a + 1;
  while (m + b < n) {
    m++;
  }
  printf("%d", m);
  return 0;
}
