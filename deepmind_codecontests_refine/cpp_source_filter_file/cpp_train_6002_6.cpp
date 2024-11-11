#include <bits/stdc++.h>
int main() {
  int i = 1, n, m;
  scanf("%d%d", &n, &m);
  while (1) {
    if (m < i) break;
    m -= i++;
    i = i % n + 1;
  }
  printf("%d\n", m);
  return 0;
}
