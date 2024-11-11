#include <bits/stdc++.h>
using namespace std;
struct P {
  double x, y, z;
};
int n, i, j, k, l;
P p[100005];
double vp, vs, bx, by, bz, t, q, u, x, y, z;
double eps = 1e-12;
double time(int i, int j) {
  double di, dj, dc, t1, t2, x, y, z;
  di = 0;
  dj = 1;
  x = p[j].x;
  y = p[j].y;
  z = p[j].z;
  t1 = t + sqrt(((x - p[i].x) * (x - p[i].x)) + ((y - p[i].y) * (y - p[i].y)) +
                ((z - p[i].z) * (z - p[i].z))) /
               vs;
  t2 = sqrt(((x - bx) * (x - bx)) + ((y - by) * (y - by)) +
            ((z - bz) * (z - bz))) /
       vp;
  if (t1 < t2 && fabs(t1 - t2) > 1e-9) return -1;
  while (dj - di > eps) {
    dc = (di + dj) / 2.;
    x = p[i].x + (p[j].x - p[i].x) * dc;
    y = p[i].y + (p[j].y - p[i].y) * dc;
    z = p[i].z + (p[j].z - p[i].z) * dc;
    t1 =
        t + sqrt(((x - p[i].x) * (x - p[i].x)) + ((y - p[i].y) * (y - p[i].y)) +
                 ((z - p[i].z) * (z - p[i].z))) /
                vs;
    t2 = sqrt(((x - bx) * (x - bx)) + ((y - by) * (y - by)) +
              ((z - bz) * (z - bz))) /
         vp;
    if (t1 < t2)
      di = dc;
    else
      dj = dc;
  }
  return dc;
}
int main() {
  cin >> n;
  ++n;
  for (i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y >> p[i].z;
  }
  cin >> vp >> vs >> bx >> by >> bz;
  p[n] = p[0];
  t = 0;
  for (i = 0; i < n - 1; ++i) {
    q = time(i, i + 1);
    if (q < 0)
      t += sqrt(((p[i + 1].x - p[i].x) * (p[i + 1].x - p[i].x)) +
                ((p[i + 1].y - p[i].y) * (p[i + 1].y - p[i].y)) +
                ((p[i + 1].z - p[i].z) * (p[i + 1].z - p[i].z))) /
           vs;
    else {
      x = p[i].x + (p[i + 1].x - p[i].x) * q;
      y = p[i].y + (p[i + 1].y - p[i].y) * q;
      z = p[i].z + (p[i + 1].z - p[i].z) * q;
      u = sqrt(((x - p[i].x) * (x - p[i].x)) + ((y - p[i].y) * (y - p[i].y)) +
               ((z - p[i].z) * (z - p[i].z))) /
          vs;
      t += u;
      printf("YES\n%.7lf\n%.7lf %.7lf %.7lf\n", t, x, y, z);
      return 0;
    }
  }
  printf("NO");
  return 0;
}
