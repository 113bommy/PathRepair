#include <bits/stdc++.h>
double l;
double dist(int x, int y, int x1, int y1) {
  return sqrt((double)((x - x1) * (x - x1) + (y - y1) * (y - y1)));
}
bool f(int r, int r1, int r2) {
  if (l >= r + r2) return true;
  if (l + r2 <= r) return true;
  if (l + r <= r1) return true;
  return false;
}
int main() {
  int x1, x2, y1, y2, r1, R1, r2, R2, ans = 0;
  scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &r1, &R1, &x2, &y2, &r2, &R2);
  l = dist(x1, y1, x2, y2);
  if (f(r1, r2, R2)) ans++;
  if (f(R1, r2, R2)) ans++;
  if (f(r2, r1, R1)) ans++;
  if (f(R2, r1, R1)) ans++;
  printf("%d\n", ans);
  return 0;
}
