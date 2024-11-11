#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1)
    printf("-1\n");
  else
    printf("%d %d %d\n", n, n + 1, 2 * (n + 1));
  return 0;
}
