#include <bits/stdc++.h>
using namespace std;
int n, x, y, xx, yy, rx, ry, vx, vy;
double mn, mx;
void Sol(int rx, int ry, int vx, int vy) {
  double mnx, mny, mxx, mxy;
  if ((rx >= xx && vx >= 0) || (rx <= x && vx <= 0))
    mnx = 1e10;
  else if (rx > x && rx < xx)
    mnx = 0;
  else
    mnx = min(1.0 * (x - rx) / vx, 1.0 * (xx - rx) / vx);
  if ((rx >= xx && vx >= 0) || (rx <= x && vx <= 0))
    mxx = -1e10;
  else if (vx == 0)
    mxx = 1e10;
  else
    mxx = max(1.0 * (x - rx) / vx, 1.0 * (xx - rx) / vx);
  if ((ry >= yy && vy >= 0) || (ry <= y && vy <= 0))
    mny = 1e10;
  else if (ry > y && ry < yy)
    mny = 0;
  else
    mny = min(1.0 * (y - ry) / vy, 1.0 * (yy - ry) / vy);
  if ((ry >= yy && vy >= 0) || (ry <= y && vy <= 0))
    mxy = -1e10;
  else if (vy == 0)
    mxy = 1e10;
  else
    mxy = max(1.0 * (y - ry) / vy, 1.0 * (yy - ry) / vy);
  mn = max(mn, mnx);
  mn = max(mn, mny);
  mx = min(mx, mxx);
  mx = min(mx, mxy);
}
int main() {
  mn = -1e9;
  mx = 1e9;
  scanf("%d%d%d%d%d", &n, &x, &y, &xx, &yy);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
    Sol(rx, ry, vx, vy);
  }
  if (mn < mx + 1e-8)
    printf("%.16f\n", mn);
  else
    printf("-1\n");
  return 0;
}
