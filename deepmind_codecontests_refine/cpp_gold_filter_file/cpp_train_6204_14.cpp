#include <bits/stdc++.h>
using namespace std;
const long long moda = 134232354111111;
int n;
int minx, maxx, miny, maxy;
int tx, ty, vx, vy;
int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &minx, &miny, &maxx, &maxy);
  if (minx > maxx) {
    swap(minx, maxx);
  }
  if (miny > maxy) {
    swap(miny, maxy);
  }
  double mint = 0;
  double maxt = 1e100;
  double tmin, tmax;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &tx, &ty, &vx, &vy);
    if (vx == 0) {
      if (!(tx > minx && tx < maxx)) {
        puts("-1");
        exit(0);
      }
    } else {
      tmin = (minx - tx) * 1.0 / (vx);
      tmax = (maxx - tx) * 1.0 / (vx);
      if (tmin > tmax) {
        swap(tmin, tmax);
      }
      mint = max(mint, tmin);
      maxt = min(maxt, tmax);
    }
    if (vy == 0) {
      if (!(ty > miny && ty < maxy)) {
        puts("-1");
        exit(0);
      }
    } else {
      tmin = (miny - ty) * 1.0 / (vy);
      tmax = (maxy - ty) * 1.0 / (vy);
      if (tmin > tmax) {
        swap(tmin, tmax);
      }
      mint = max(mint, tmin);
      maxt = min(maxt, tmax);
    }
  }
  if (maxt <= mint || maxt < 0) {
    puts("-1");
  } else {
    printf("%.20f\n", mint);
  }
  return 0;
}
