#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
struct gg {
  double x, y;
} pt[10];
double ang[10], r;
double fgcd(double a, double b) {
  return fabs(b - 0) <= eps ? a : fgcd(b, fmod(a, b));
}
double dis(gg a, gg b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void get(double a, double b, double c) {
  double S, p, h[4], s[4];
  if (a > b) swap(a, b);
  if (a > c) swap(a, c);
  if (b > c) swap(b, c);
  p = (a + b + c) / 2;
  S = sqrt(p * (p - a) * (p - b) * (p - c));
  h[1] = S * 2 / c;
  s[1] = h[1] / b;
  s[2] = h[1] / a;
  r = a / s[1];
  h[2] = S * 2 / b;
  ang[1] = asin(s[1]);
  ang[2] = asin(s[2]);
  ang[3] = acos(-1) - ang[1] - ang[2];
  return;
}
int main() {
  double edge, dis1, dis2, dis3, ta, S, angg;
  for (int i = 1; i <= 3; i++) scanf("%lf%lf", &pt[i].x, &pt[i].y);
  dis1 = dis(pt[1], pt[2]), dis2 = dis(pt[1], pt[3]), dis3 = dis(pt[2], pt[3]);
  get(dis1, dis2, dis3);
  angg = fgcd(ang[1], fgcd(ang[2], ang[3]));
  ta = tan(angg);
  edge = r * sin(angg);
  S = edge * edge / ta / 4;
  S *= acos(-1) / angg;
  printf("%.6lf", S);
}
