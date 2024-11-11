#include <bits/stdc++.h>
int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  n /= 2;
  if ((x == n || x == n + 1) && (y == n || y == n + 1))
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
