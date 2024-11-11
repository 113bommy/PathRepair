#include <bits/stdc++.h>
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  printf("%d", (100 * n - 1800 * m) * (1 << m));
  return 0;
}
