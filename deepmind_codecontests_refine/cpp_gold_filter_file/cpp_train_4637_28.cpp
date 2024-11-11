#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int M = 15;
const double eps = 1e-7;
const int INF = 1 << 30;
int n;
struct node {
  double x, y, z;
  node() { x = y = z = 0; }
  node(double xx, double yy, double zz) {
    x = xx;
    y = yy;
    z = zz;
  }
} poy[N], ori;
double vp, vs, prelen;
int ln;
double ABS(double x) {
  while (x < 0) x = -x;
  return x;
}
double dist(node a, node b) {
  double tmp = 0;
  tmp += (a.x - b.x) * (a.x - b.x);
  tmp += (a.y - b.y) * (a.y - b.y);
  tmp += (a.z - b.z) * (a.z - b.z);
  return sqrt(tmp);
}
void init() {
  double x, y, z;
  for (int i = 1; i <= n + 1; i++) {
    cin >> x >> y >> z;
    poy[i] = node(x, y, z);
  }
  cin >> vp >> vs;
  cin >> x >> y >> z;
  ori = node(x, y, z);
}
bool solve() {
  double t = 0;
  for (int i = 2; i <= n + 1; i++) {
    double len = dist(ori, poy[i]) / vp;
    double edge = dist(poy[i - 1], poy[i]) / vs;
    t += edge;
    if ((t - len) >= -eps) {
      ln = i;
      prelen = t - edge;
      return 1;
    }
  }
  return 0;
}
node getmid(node a, node b) {
  double xx, yy, zz;
  xx = (a.x + b.x) * 0.5;
  yy = (a.y + b.y) * 0.5;
  zz = (a.z + b.z) * 0.5;
  return node(xx, yy, zz);
}
void cal() {
  node pre = poy[ln - 1];
  node l = poy[ln - 1], r = poy[ln];
  double t;
  while (ABS(dist(l, r)) > eps) {
    node mid = getmid(l, r);
    double len1 = dist(ori, mid);
    double len2 = dist(mid, pre);
    double t1 = len1 / vp;
    double t2 = len2 / vs + prelen;
    t = t1;
    if ((t1 - t2) < 1e-12)
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n%.10lf %.10lf %.10lf\n", t, l.x, l.y, l.z);
}
int main() {
  while (cin >> n) {
    init();
    if (solve())
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
      continue;
    }
    cal();
  }
}
