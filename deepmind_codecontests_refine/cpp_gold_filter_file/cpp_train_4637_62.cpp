#include <bits/stdc++.h>
using namespace std;
struct dot {
  double x;
  double y;
  double z;
} arr[10005];
double vs, vp;
double sqr(double a) { return a * a; }
double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}
void distance(double x, double y, double z, int id, double t) {
  double lx = arr[id].x;
  double rx = arr[id + 1].x;
  double ly = arr[id].y;
  double ry = arr[id + 1].y;
  double lz = arr[id].z;
  double rz = arr[id + 1].z;
  for (int i = 0; i < 80; i++) {
    double mx = (lx + rx) / 2;
    double my = (ly + ry) / 2;
    double mz = (lz + rz) / 2;
    if (dist(mx, my, mz, x, y, z) / vp <
        t + dist(mx, my, mz, arr[id].x, arr[id].y, arr[id].z) / vs) {
      rx = mx;
      ry = my;
      rz = mz;
    } else {
      lx = mx;
      ly = my;
      lz = mz;
    }
  }
  cout << fixed << setprecision(10)
       << t + dist(lx, ly, lz, arr[id].x, arr[id].y, arr[id].z) / vs << endl;
  cout << fixed << setprecision(10) << lx << " " << fixed << setprecision(10)
       << ly << " " << fixed << setprecision(10) << lz << endl;
}
double px, py, pz;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> arr[i].x >> arr[i].y >> arr[i].z;
  }
  cin >> vp >> vs;
  cin >> px >> py >> pz;
  double t = 0;
  for (int i = 0; i < n; i++) {
    if ((dist(arr[i + 1].x, arr[i + 1].y, arr[i + 1].z, px, py, pz)) / vp -
            1e-6 <=
        t + (dist(arr[i + 1].x, arr[i + 1].y, arr[i + 1].z, arr[i].x, arr[i].y,
                  arr[i].z)) /
                vs) {
      cout << "YES\n";
      distance(px, py, pz, i, t);
      return 0;
    } else {
      t += (dist(arr[i + 1].x, arr[i + 1].y, arr[i + 1].z, arr[i].x, arr[i].y,
                 arr[i].z)) /
           vs;
    }
  }
  cout << "NO\n";
  return 0;
}
