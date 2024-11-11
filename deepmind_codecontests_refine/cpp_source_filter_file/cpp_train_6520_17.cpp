#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
struct Point {
  double x, y, z;
} o, a[MAXN], b[MAXN * 10];
struct Vector {
  double x, y, z;
} v;
int n, m = 0;
double ro, r[MAXN];
double ans = 1000000.0;
inline double dis(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
inline Point trs(Point a, Vector v, double t) {
  a.x += v.x * t;
  a.y += v.y * t;
  a.z += v.z * t;
  return a;
}
void chk(Point o, Point a, double d) {
  double l = 0, r = 1000000.0;
  while (r - l > 1e-9) {
    double dt = (r - l) / 3.0;
    double ll = l + dt, rr = r - dt;
    double dl = dis(trs(o, v, ll), a);
    double dr = dis(trs(o, v, rr), a);
    if (dl < dr)
      r = rr;
    else
      l = ll;
  }
  double ll = 0, rr = l;
  while (rr - ll > 1e-9) {
    double mid = (ll + rr) / 2;
    double d_tmp = dis(trs(o, v, mid), a);
    if (d_tmp <= d)
      rr = mid;
    else
      ll = mid;
  }
  if (dis(trs(o, v, ll), a) <= d + 1e-10) {
    if (ll < ans) ans = ll;
  }
}
void work() {
  for (int i = 1; i <= n; i++) chk(o, a[i], ro + r[i]);
  for (int i = 1; i <= m; i++) chk(o, b[i], ro);
}
int main() {
  cin >> o.x >> o.y >> o.z >> v.x >> v.y >> v.z >> ro;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> a[i].x >> a[i].y >> a[i].z >> r[i] >> t;
    while (t--) {
      m++;
      cin >> b[m].x >> b[m].y >> b[m].z;
      b[m].x += a[i].x;
      b[m].y += a[i].y;
      b[m].z += a[i].z;
    }
  }
  work();
  if (ans > 500000.0)
    cout << -1 << endl;
  else
    cout << setiosflags(ios::fixed) << setprecision(10) << ans << endl;
  return 0;
}
