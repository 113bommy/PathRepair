#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (t.size()); ++(i)) s << t[i] << " ";
  return s;
}
double px[105], py[105], pz[105], dx, dy, dz;
const double eps = 1e-8;
int n;
inline double sqr(double x) { return x * x; }
double dist() {
  double ans = 0;
  for (int(i) = 0; (i) < (n); ++(i))
    (ans) = max((ans), (sqr(px[i] - dx) + sqr(py[i] - dy) + sqr(pz[i] - dz)));
  return -ans;
}
void tz(double from, double to) {
  if (abs(from - to) < eps) {
    dz = from;
    return;
  }
  double mid1 = (2 * from + to) / 3, mid2 = (from + 2 * to) / 3;
  dz = mid1;
  double wyn1 = dist();
  dz = mid2;
  double wyn2 = dist();
  if (wyn1 < wyn2)
    tz(mid1, to);
  else
    tz(from, mid2);
}
void ty(double from, double to) {
  if (abs(from - to) < eps) {
    dy = from;
    return;
  }
  double mid1 = (2 * from + to) / 3, mid2 = (from + 2 * to) / 3;
  dy = mid1;
  tz(-10000, 10000);
  double wyn1 = dist();
  dy = mid2;
  tz(-10000, 10000);
  double wyn2 = dist();
  if (wyn1 < wyn2)
    ty(mid1, to);
  else
    ty(from, mid2);
}
void tx(double from, double to) {
  if (abs(from - to) < eps) {
    dx = from;
    return;
  }
  double mid1 = (2 * from + to) / 3, mid2 = (from + 2 * to) / 3;
  dx = mid1;
  ty(-10000, 10000);
  double wyn1 = dist();
  dx = mid2;
  ty(-10000, 10000);
  double wyn2 = dist();
  if (wyn1 < wyn2)
    tx(mid1, to);
  else
    tx(from, mid2);
}
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n); ++(i)) {
    int(a), (b), (c);
    scanf("%d %d %d", &(a), &(b), &(c));
    px[i] = a;
    py[i] = b;
    pz[i] = c;
  }
  tx(-10000, 10000);
  printf("%.9lf %.9lf %.9lf\n", dx, dy, dz);
}
