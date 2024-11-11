#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
struct point {
  double x, y;
  point() {}
  point(double in_x, double in_y) { x = in_x, y = in_y; }
  double module() { return sqrt(x * x + y * y); }
  double operator*(point &B) { return x * B.x + y * B.y; }
  point operator-(point &B) { return point(x - B.x, y - B.y); }
  point rotate(double alp) {
    return point(x * cos(alp) - y * sin(alp), x * sin(alp) + y * cos(alp));
  }
};
point P, Q, S;
double Vp, Vs, r, R;
bool solve(double T) {
  Q = P.rotate(T * Vp / R);
  double S_len = S.module(), Q_len = R, len = 0;
  double alp = acos(S * Q / (S_len * Q_len));
  double bel = acos(r / S_len) + acos(r / Q_len);
  if (alp < bel)
    len = (S - Q).module();
  else
    len = sqrt(S * S - r * r) + sqrt(Q * Q - r * r) + (alp - bel) * r;
  return len / Vs < T + Eps;
}
int main() {
  scanf("%lf%lf%lf", &P.x, &P.y, &Vp);
  scanf("%lf%lf%lf%lf", &S.x, &S.y, &Vs, &r);
  R = P.module();
  double l = 0, r = 100000;
  while (r - l > Eps) {
    double m = (l + r) / 2;
    if (solve(m))
      r = m;
    else
      l = m;
  }
  printf("%.8lf\n", l);
  return 0;
}
