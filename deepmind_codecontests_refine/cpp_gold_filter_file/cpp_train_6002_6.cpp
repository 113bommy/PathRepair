#include <bits/stdc++.h>
int main() {
  int n, m, i = 1;
  scanf("%d%d", &n, &m);
  for (m %= (1 + n) * n / 2; m - i >= 0; ++i) m -= i;
  printf("%d", m);
}
