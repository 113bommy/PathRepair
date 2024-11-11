#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct pt {
  double x, y, z;
};
pt operator+(const pt& a, const pt& b) {
  pt p = {a.x + b.x, a.y + b.y, a.z + b.z};
  return p;
}
pt operator-(const pt& a, const pt& b) {
  pt p = {a.x - b.x, a.y - b.y, a.z - b.z};
  return p;
}
pt operator*(const pt& a, double m) {
  pt p = {a.x * m, a.y * m, a.z * m};
  return p;
}
pt readPoint() {
  pt ret;
  scanf("%lf %lf %lf", &ret.x, &ret.y, &ret.z);
  return ret;
}
int n, m1, m2;
pt Z, V;
double R;
pt mine[1000][2];
pt sphere[100];
double r[100];
double distPointToPoint(pt a, pt b) {
  return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)) +
              ((a.z - b.z) * (a.z - b.z)));
}
double distPointToSegment(pt p, pt a, pt b) {
  double l = 0, r = 1;
  while (r - l > 1e-9) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = distPointToPoint(a + (b - a) * m1, p);
    double f2 = distPointToPoint(a + (b - a) * m2, p);
    if (f1 < f2)
      r = m2;
    else
      l = m1;
  }
  double f = distPointToPoint(a + (b - a) * l, p);
  return f;
}
double intersectMine(pt a, pt b) {
  double l = 0, r = 1e10;
  while (r - l > 1e-9) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = distPointToSegment(Z + V * m1, a, b);
    double f2 = distPointToSegment(Z + V * m2, a, b);
    if (f1 < f2)
      r = m2;
    else
      l = m1;
  }
  double md = distPointToSegment(Z + V * l, a, b);
  if (md > R + 1e-7) return 1e100;
  l = 0;
  while (r - l > 1e-9) {
    double m = (l + r) / 2;
    double f = distPointToSegment(Z + V * m, a, b);
    if (f <= R)
      r = m;
    else
      l = m;
  }
  return r;
}
double intersectSphere(pt cc, double rr) {
  double l = 0, r = 1e10;
  while (r - l > 1e-9) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = distPointToPoint(Z + V * m1, cc);
    double f2 = distPointToPoint(Z + V * m2, cc);
    if (f1 < f2)
      r = m2;
    else
      l = m1;
  }
  double md = distPointToPoint(Z + V * l, cc);
  if (md > R + rr + 1e-7) return 1e100;
  l = 0;
  while (r - l > 1e-9) {
    double m = (l + r) / 2;
    double f = distPointToPoint(Z + V * m, cc);
    if (f <= R + rr)
      r = m;
    else
      l = m;
  }
  return r;
}
void solution() {
  Z = readPoint();
  V = readPoint();
  scanf("%lf", &R);
  scanf("%d", &n);
  for (int i = 0, _n = (n); i < _n; ++i) {
    int k;
    pt O = readPoint();
    scanf("%lf", r + m2);
    sphere[m2++] = O;
    scanf("%d", &k);
    for (int j = 0, _n = (k); j < _n; ++j) {
      pt P = readPoint();
      P = P + O;
      mine[m1][0] = O;
      mine[m1++][1] = P;
    }
  }
  double mini = 1e100;
  for (int i = 0, _n = (m1); i < _n; ++i)
    mini = min(mini, intersectMine(mine[i][0], mine[i][1]));
  for (int i = 0, _n = (m2); i < _n; ++i)
    mini = min(mini, intersectSphere(sphere[i], r[i]));
  if (mini > 1e99)
    puts("-1");
  else
    printf("%.6lf\n", mini);
}
int main() {
  solution();
  return 0;
}
