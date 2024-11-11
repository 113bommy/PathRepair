#include <bits/stdc++.h>
int main() {
  int v[10], x, y, z, x1, y1, z1;
  scanf("%d%d%d", &x1, &y1, &z1);
  scanf("%d%d%d", &x, &y, &z);
  for (int i = 1; i <= 6; i++) scanf("%d", &v[i]);
  int ans = 0;
  if (x1 > x) ans += v[6];
  if (x1 < x) ans += v[5];
  if (y1 > y) ans += v[2];
  if (y1 < y) ans += v[1];
  if (z1 > z) ans += v[4];
  if (z1 < z) ans += v[3];
  printf("%d\n", ans);
  return 0;
}
