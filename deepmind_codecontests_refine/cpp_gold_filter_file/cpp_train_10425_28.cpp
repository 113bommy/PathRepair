#include <bits/stdc++.h>
int main(void) {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  n /= 2;
  if ((x == n || x == n + 1) && (y == n || y == n + 1))
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
