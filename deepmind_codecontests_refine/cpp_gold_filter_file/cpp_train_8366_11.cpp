#include <bits/stdc++.h>
using namespace std;
int n;
int x[200], y[200];
double last = 0;
bool check(pair<double, double> pt, double r) {
  double xx = pt.first, yy = pt.second;
  for (int i = 0; i < n; i++) {
    double d = (x[i] - xx) * (x[i] - xx) + (y[i] - yy) * (y[i] - yy);
    if (d + 1e-6 < r * r) return false;
  }
  return true;
}
int turn(int i, int j, int k) {
  return (x[i] - x[j]) * (y[k] - y[j]) - (x[k] - x[j]) * (y[i] - y[j]);
}
pair<double, double> circumcenter(int i, int j, int k, double r) {
  double dx = x[j] - x[i], dy = y[j] - y[i];
  double md = sqrt(max((4 * r * r - dx * dx - dy * dy) / (dx * dx + dy * dy),
                       (double)0.0)) /
              2;
  int t = 2 * (turn(i, k, j) > 0) - 1;
  pair<double, double> p =
      make_pair(x[i] + dx / 2 - (md)*dy * t, y[i] + dy / 2 + (md)*dx * t);
  return p;
}
double side(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
bool acute(double a, double b, double c) {
  return a + b > c + 1 && c + a > b + 1 && b + c > a + 1;
}
double rad(double s1, double s2, double s3, int a, int b, int c) {
  return sqrt(s1 * s2 * s3) / (2 * abs(turn(a, b, c)));
}
double square(int i, int j, int k, int l) {
  int x1 = x[j] - x[i], y1 = y[j] - y[i];
  int x2 = x[k] - x[i], y2 = y[k] - y[i];
  int x3 = x[l] - x[i], y3 = y[l] - y[i];
  if (x1 * x2 + y1 * y2 == 0 && x1 + x2 == x3 && y1 + y2 == y3)
    return sqrt(x3 * x3 + y3 * y3) / 2;
  if (x1 * x3 + y1 * y3 == 0 && x1 + x3 == x2 && y1 + y3 == y2)
    return sqrt(x2 * x2 + y2 * y2) / 2;
  if (x3 * x2 + y3 * y2 == 0 && x3 + x2 == x1 && y3 + y2 == y1)
    return sqrt(x1 * x1 + y1 * y1) / 2;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        double a = side(i, j);
        double b = side(i, k);
        double c = side(j, k);
        if (acute(a, b, c)) {
          double r = rad(a, b, c, i, j, k);
          if (check(circumcenter(i, j, k, r), r)) {
            last = max(last, r);
          }
        }
        for (int l = k + 1; l < n; l++) {
          double r = square(i, j, k, l);
          if (check(make_pair((x[i] + x[j] + x[k] + x[l]) / 4.0,
                              (y[i] + y[j] + y[k] + y[l]) / 4.0),
                    r)) {
            last = max(last, r);
          }
        }
      }
    }
  }
  if (last == 0) {
    printf("-1\n");
  } else {
    printf("%.10f\n", last);
  }
}
