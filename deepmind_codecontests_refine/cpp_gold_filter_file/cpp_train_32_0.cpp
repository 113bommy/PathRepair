#include <bits/stdc++.h>
int main() {
  int n, x, y;
  scanf("%d", &n);
  scanf("%d", &x);
  scanf("%d", &y);
  int dy = 0;
  if ((y * n) % 100 == 0)
    dy = ((y * n) / 100);
  else
    dy = ((y * n) / 100) + 1;
  int ans = 0;
  if (dy - x <= 0)
    ans = 0;
  else
    ans = dy - x;
  printf("%d", ans);
  return 0;
}
