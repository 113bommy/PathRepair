#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, x1, y1, z1;
  scanf("%d %d %d %d %d %d", &x, &y, &z, &x1, &y1, &z1);
  int a1, a2, a3, a4, a5, a6;
  scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
  int ans = 0;
  if (y > y1) ans += a2;
  if (z > z1) ans += a4;
  if (x > x1) ans += a6;
  if (y < 0) ans += a1;
  if (z < 0) ans += a3;
  if (x < 0) ans += a5;
  printf("%d\n", ans);
  return 0;
}
