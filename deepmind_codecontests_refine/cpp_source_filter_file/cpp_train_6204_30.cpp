#include <bits/stdc++.h>
using namespace std;
int inside(double x, double y, double x1, double y1, double x2, double y2) {
  double maxx, maxy, minx, miny;
  maxx = max(x1, x2);
  maxy = max(y1, y2);
  minx = min(x1, x2);
  miny = min(y1, y2);
  if (minx < x and maxx > x and miny < y and maxy > y)
    return 1;
  else
    return 0;
}
int check(int n, int *rx, int *ry, int *vx, int *vy, double mid, double x1,
          double y1, double x2, double y2) {
  int i;
  for (i = 0; i < n; i++) {
    double tempx = (double)rx[i] + (double)vx[i] * mid;
    double tempy = (double)ry[i] + (double)vy[i] * mid;
    if (!inside(tempx, tempy, x1, y1, x2, y2)) return 0;
  }
  return 1;
}
int main() {
  cout.precision(7);
  double temp;
  int flag = 0;
  int n, x1, y1, x2, y2;
  int maxx, maxy, minx, miny;
  int i;
  cin >> n;
  cin >> x1 >> y1 >> x2 >> y2;
  maxx = max(x1, x2);
  maxy = max(y1, y2);
  minx = min(x1, x2);
  miny = min(y1, y2);
  double high = (double)200000, low = 0, mid;
  int rx[n], ry[n], vx[n], vy[n];
  for (i = 0; i < n; i++) {
    cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
    if (rx[i] <= minx or rx[i] >= maxx) {
      if (rx[i] <= minx) {
        if (vx[i] <= 0) {
          flag = 1;
          break;
        }
        temp = (double)(minx - rx[i]) / (double)vx[i];
        low = max(temp, low);
        temp = (double)(maxx - rx[i]) / (double)vx[i];
        high = min(temp, high);
      } else {
        if (vx[i] >= 0) {
          flag = 1;
          break;
        }
        temp = (double)abs(maxx - rx[i]) / (double)abs(vx[i]);
        low = max(temp, low);
        temp = (double)abs(minx - rx[i]) / (double)abs(vx[i]);
        high = min(temp, high);
      }
    } else {
      if (vx[i] > 0) {
        temp = (double)(maxx - rx[i]) / (double)vx[i];
        high = min(temp, high);
      } else if (vx[i] < 0) {
        double temp = (double)abs(minx - rx[i]) / (double)abs(vx[i]);
        high = min(temp, high);
      }
    }
    if (ry[i] <= miny or ry[i] >= maxy) {
      if (ry[i] <= miny) {
        if (vy[i] <= 0) {
          flag = 1;
          break;
        }
        temp = (double)(miny - ry[i]) / vy[i];
        low = max(temp, low);
        temp = (double)(maxy - ry[i]) / (double)vy[i];
        high = min(temp, high);
      } else {
        if (vy[i] >= 0) {
          flag = 1;
          break;
        }
        temp = (double)abs(maxy - ry[i]) / (double)abs(vy[i]);
        low = max(temp, low);
        temp = (double)abs(miny - ry[i]) / (double)abs(vy[i]);
        high = min(temp, high);
      }
    } else {
      if (vy[i] > 0) {
        temp = (double)(maxy - ry[i]) / (double)vy[i];
        high = min(temp, high);
      } else if (vy[i] < 0) {
        double temp = (double)abs(miny - ry[i]) / (double)abs(vy[i]);
        high = min(temp, high);
      }
    }
  }
  if (low > high or flag == 1)
    cout << -1;
  else
    cout << low;
}
