#include <bits/stdc++.h>
double w[2][3];
const double EPS = 1e-7;
const double PHI = 1.6180339887;
int n;
const double INF = 1e50;
inline double max(double a, double b) { return a > b ? a : b; }
double S;
double C[3];
inline double f() {
  double result = .0, current = .0;
  for (int i = 0; i < 3; ++i) {
    if (fabs(w[0][i]) < EPS) {
      result -= C[i] * INF;
    } else {
      result += C[i] * log(w[0][i]);
    }
  }
  return result;
}
inline double g() {
  double result = .0, current = .0;
  for (int i = 0; i < 3; ++i) {
    if (fabs(w[1][i]) < EPS) {
      result -= C[i] * INF;
    } else {
      result += C[i] * log(w[1][i]);
    }
  }
  return result;
}
inline double go(int coordinate, double l, double r, double accum) {
  if (coordinate == 3) {
    double fR = f(), gR = g();
    if (gR > fR) {
      memcpy(w[0], w[1], 24);
    }
    return gR;
  } else {
    double a, b, fA, fB, step;
    while (l + EPS < r) {
      step = (r - l) / 3;
      a = l + step;
      b = r - step;
      w[1][coordinate] = a;
      fA = go(1 + coordinate, 0, S - accum - a, accum + a);
      w[1][coordinate] = b;
      fB = go(1 + coordinate, 0, S - accum - b, accum + b);
      if (fA < fB) {
        l = a;
      } else {
        r = b;
      }
    }
    w[1][coordinate] = (l + r) / 2;
    double can = S;
    for (int i = 0; i <= coordinate; ++i) can -= w[1][i];
    return go(1 + coordinate, 0, can, -can + S);
  }
}
int main() {
  int i, j;
  scanf("%lf%lf%lf%lf", &S, C + 0, C + 1, C + 2);
  go(0, 0, S, 0);
  for (i = 0; i < 3; ++i) {
    printf("%.9lf ", w[0][i]);
  }
  return 0;
}
