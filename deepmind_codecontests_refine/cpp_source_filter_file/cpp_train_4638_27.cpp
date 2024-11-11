#include <bits/stdc++.h>
using namespace std;
struct point {
  long double x, y, z;
  point(long double a = 0, long double b = 0, long double c = 0) {
    x = a, y = b, z = c;
  }
};
vector<point> v;
int n;
int vp, vs;
int xx, yy, zz;
long double ans;
point fans;
long double dis(long double x1, long double y1, long double z1, long double x2,
                long double y2, long double z2) {
  long double temp = (x1 - x2) * double(x1 - x2);
  temp += (y1 - y2) * double(y1 - y2);
  temp += (z1 - z2) * double(z1 - z2);
  return sqrt(temp);
}
bool check(long double const& tt) {
  long double tl = tt;
  for (int i = 1; i < n; i++) {
    long double d1 =
        dis(v[i].x, v[i].y, v[i].z, v[i - 1].x, v[i - 1].y, v[i - 1].z);
    long double dc = vs * tl;
    if (dc < d1 + 1e-9 || (fabs(dc - d1)) <= 1e-9) {
      int x = v[i - 1].x;
      int y = v[i - 1].y;
      int z = v[i - 1].z;
      long double ratio = dc / d1;
      point res;
      res.x = x + (v[i].x - x) * ratio;
      res.y = y + (v[i].y - y) * ratio;
      res.z = z + (v[i].z - z) * ratio;
      long double dis2 = dis(res.x, res.y, res.z, xx, yy, zz);
      long double tk = dis2 / vp;
      if (tk < tt + 1e-9 || (fabs(tk - tt)) <= 1e-9) {
        if (tt < ans) {
          ans = tt;
          fans = res;
        }
        return true;
      } else
        return false;
      break;
    } else {
      long double cross = d1 / vs;
      tl -= cross;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  n++;
  for (int i = 0, x, y, z; i < n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    v.push_back(point(x, y, z));
  }
  scanf("%d%d", &vp, &vs);
  scanf("%d%d%d", &xx, &yy, &zz);
  long double l = 0, r = 1e9;
  ans = 1e9;
  for (int it = 0; it < 100; it++) {
    long double mid = (l + r) / 2.0;
    if (check(mid)) {
      r = mid;
    } else
      l = mid;
  }
  if (ans < 1e9) {
    cout << "YES" << endl;
    cout << setprecision(8) << fixed << ans << endl;
    cout << setprecision(8) << fixed << fans.x << " " << fans.y << " " << fans.z
         << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
