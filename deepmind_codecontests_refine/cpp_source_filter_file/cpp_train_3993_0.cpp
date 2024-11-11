#include <bits/stdc++.h>
int main() {
  int n, m, a;
  long long int x, y;
  scanf("%d %d %d", &n, &m, &a);
  x = n / a;
  y = m / a;
  if (x * a != n) x++;
  if (y * a != m) y++;
  printf("%d", x * y);
  return 0;
}
