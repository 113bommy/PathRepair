#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct pt {
  double x, y;
} a, b, c;
int T;
bool zero(double a) { return fabs(a) < eps; }
double sqr(double a) { return a * a; }
pt operator+(pt a, pt b) { return (pt){a.x + b.x, a.y + b.y}; }
pt operator-(pt a, pt b) { return (pt){a.x - b.x, a.y - b.y}; }
pt operator*(pt a, double k) { return (pt){a.x * k, a.y * k}; }
double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
double sqr(pt a) { return sqr(a.x) + sqr(b.x); }
double dis(pt a) { return sqrt(sqr(a)); }
void print(pt a) { printf("%.9lf %.9lf ", a.x, a.y); }
bool check(pt *p) {
  if (cross(p[1] - p[0], p[2] - p[1]) * cross(p[3] - p[0], p[2] - p[3]) > -eps)
    return 0;
  if (cross(p[0] - p[1], p[3] - p[0]) * cross(p[2] - p[1], p[3] - p[2]) > -eps)
    return 0;
  return 1;
}
void gauss(double mat[5][6], double *X) {
  int Ct = 4;
  for (int i = 1; i < Ct; i++) {
    if (zero(mat[i][i])) {
      int k;
      for (int j = i + 1; j <= Ct; j++)
        if (!zero(mat[j][i])) k = j;
      for (int j = 1; j <= Ct + 1; j++) swap(mat[k][j], mat[i][j]);
    }
    if (!zero(mat[i][i]))
      for (int j = i + 1; j <= Ct; j++) {
        double mul = mat[j][i] / mat[i][i];
        for (int k = 1; k <= Ct + 1; k++) mat[j][k] -= mul * mat[i][k];
      }
  }
  X[Ct] = mat[Ct][Ct + 1] / mat[Ct][Ct];
  for (int i = Ct - 1; i >= 1; i--) {
    X[i] = mat[i][Ct + 1];
    for (int j = i + 1; j <= Ct; j++) X[i] -= mat[i][j] * X[j];
    if (!zero(mat[i][i])) X[i] /= mat[i][i];
  }
}
bool solve(pt a, pt b, pt c) {
  pt p[4];
  double t0 = sqr(a) - sqr(b), t1 = sqr(a) - sqr(c);
  double t2 = (a.x - b.x) * 2.0, t3 = (a.y - b.y) * 2.0;
  double t4 = (a.x - c.x) * 2.0, t5 = (a.y - c.y) * 2.0;
  double X[5], mat[5][6] = {{0, 0, 0, 0, 0, 0},
                            {0, t2, t3, 0, 0, t0},
                            {0, 0, 0, t4, t5, t1},
                            {0, 1, 0, 1, 0, 2 * a.x},
                            {0, 0, 1, 0, 1, 2 * a.y}};
  gauss(mat, X);
  p[0].x = X[1], p[0].y = X[2];
  p[1].x = X[3], p[1].y = X[4];
  p[3] = b * 2 - p[0];
  p[2] = c * 2 - p[1];
  if (check(p)) {
    printf("YES\n");
    for (int i = 0; i < 4; i++) print(p[i]);
    puts("");
    return 0;
  }
  return 1;
}
void error() { printf("NO\n\n"); }
int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (zero(cross(a - b, a - c)))
      error();
    else if (solve(a, b, c) && solve(b, a, c) && solve(c, a, b))
      error();
  }
  return 0;
}
