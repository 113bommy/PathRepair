#include <bits/stdc++.h>
using namespace std;
long n, m, px[200000], py[200000], gx[200000], gy[200000];
double sy, minx, maxx, miny, maxy, mid1, mid2;
double eval(double x, double y) {
  double s = 0;
  for (int i = 0; i < n; i++)
    s += (x - gx[i]) * (x - gx[i]) + (y - gy[i]) * (y - gy[i]);
  return s;
}
double get(double x) {
  miny = 1e9;
  maxy = -1e9;
  for (int i = 0; i < m; i++) {
    if (px[i] != px[i + 1] && min(px[i], px[i + 1]) <= x &&
        max(px[i], px[i + 1]) >= x) {
      double y =
          py[i] + (py[i + 1] - py[i]) * (x - px[i]) / (px[i + 1] - px[i]);
      miny = min(miny, y);
      maxy = max(maxy, y);
    }
  }
  if (sy > maxy) return eval(x, maxy);
  if (sy < miny) return eval(x, miny);
  return eval(x, sy);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> gx[i] >> gy[i];
    sy += gy[i];
  }
  sy /= n;
  cin >> m;
  minx = 1e9;
  maxx = 1e9;
  for (int i = 0; i < m; i++) {
    cin >> px[i] >> py[i];
    minx = min(minx, px[i] + .0);
    maxx = max(maxx, px[i] + .0);
  }
  px[n] = px[0];
  py[n] = py[0];
  double l, r;
  l = minx;
  r = maxx;
  while (l < r - 1e-13) {
    mid1 = 2 * l + r;
    mid2 = l + 2 * r;
    mid1 /= 3, mid2 /= 3;
    if (get(mid1) > get(mid2))
      l = mid1;
    else
      r = mid2;
  }
  cout.precision(12);
  cout << fixed << get(l) << endl;
  cin.get();
  cin.get();
  return 0;
}
