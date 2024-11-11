#include <bits/stdc++.h>
int main() {
  int n, m, count, i, j, p;
  count = 0;
  scanf("%d %d", &n, &m);
  if (n > m)
    p = n;
  else
    p = m;
  for (i = 0; i <= p; i++) {
    for (j = 0; j <= p; j++) {
      if ((i * i + j) == n && (j * j + i) == m) {
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
