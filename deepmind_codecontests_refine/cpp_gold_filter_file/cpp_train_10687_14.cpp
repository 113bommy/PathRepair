#include <bits/stdc++.h>
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    if (n % 10 == 0)
      n /= 10;
    else
      n--;
  }
  printf("%d\n", n);
  return 0;
}
