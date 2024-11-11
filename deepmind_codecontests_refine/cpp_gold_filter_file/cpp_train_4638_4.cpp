#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
double dis(double x, double y, double z, double x2, double y2, double z2) {
  double dx = (x - x2);
  double dy = (y - y2);
  double dz = (z - z2);
  return sqrt(dx * dx + dy * dy + dz * dz);
}
void writeanswer(double x, double y, double z, double x2, double y2, double z2,
                 int vs, int vp, int xp, int yp, int zp, double now,
                 double time) {
  if (dis(x, y, z, x2, y2, z2) < 0.0000001 && time < 0.0000001) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cout << now << endl;
    cout << x << " " << y << " " << z << endl;
    return;
  } else {
    double xm = (x + x2) / 2;
    double ym = (y + y2) / 2;
    double zm = (z + z2) / 2;
    double t2 = (time) / 2;
    if (dis(xm, ym, zm, xp, yp, zp) <= (now + t2) * vp) {
      return writeanswer(x, y, z, xm, ym, zm, vs, vp, xp, yp, zp, now, t2);
    } else {
      return writeanswer(xm, ym, zm, x2, y2, z2, vs, vp, xp, yp, zp, now + t2,
                         t2);
    }
  }
}
int main() {
  int a;
  cin >> a;
  vector<int> xs;
  vector<int> ys;
  vector<int> zs;
  for (int i = 0; i <= a; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    xs.push_back(x);
    ys.push_back(y);
    zs.push_back(z);
  }
  int vs, vp;
  cin >> vp >> vs;
  int xp, yp, zp;
  cin >> xp >> yp >> zp;
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(10);
  double now = 0.0;
  if (xp == xs[0] && yp == ys[0] && zp == zs[0]) {
    cout << "YES" << endl;
    cout << 0.0 << endl;
    cout << (double)xp << " " << (double)yp << " " << (double)zp << endl;
    return 0;
  }
  for (int i = 0; i < a; i++) {
    int x = xs[i];
    int y = ys[i];
    int z = zs[i];
    int x2 = xs[i + 1];
    int y2 = ys[i + 1];
    int z2 = zs[i + 1];
    int dx = x2 - x;
    int dy = y2 - y;
    int dz = z2 - z;
    int dx2 = x2 - xp;
    int dy2 = y2 - yp;
    int dz2 = z2 - zp;
    double distance = sqrt((double)dx * dx + dy * dy + dz * dz);
    double time = distance / vs;
    if ((now + time) * vp >= sqrt((double)dx2 * dx2 + dy2 * dy2 + dz2 * dz2)) {
      cout << "YES" << endl;
      writeanswer(x, y, z, x2, y2, z2, vs, vp, xp, yp, zp, now, time);
      return 0;
    }
    now += time;
  }
  cout << "NO";
  return 0;
}
