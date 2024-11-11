#include <bits/stdc++.h>
using namespace std;
void printMas(double *p, int n) {
  for (int i = 0; i < n; ++i) cout << p[i] << " ";
  cout << endl;
}
double getP(double *r, int k, double d, int n) {
  double *pp = new double[n + 1];
  memset(pp, 0, sizeof(double) * (n + 1));
  pp[0] = 1;
  for (int i = 0; i < n; ++i) {
    double *buf = new double[n + 1];
    memset(buf, 0, sizeof(double) * (n + 1));
    double ver = (r[i] < d) ? 1 : exp(1 - (r[i] * r[i]) / (d * d));
    buf[0] = pp[0] * (1 - ver);
    for (int j = 0; j <= i; ++j) {
      buf[j + 1] = pp[j] * ver + pp[j + 1] * (1 - ver);
    }
    pp = buf;
  }
  double res = 0;
  for (int i = k; i <= n; ++i) res += pp[i];
  return res;
}
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  double x0, y0;
  cin >> x0 >> y0;
  double *r = new double[n];
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    r[i] = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
  }
  double left = 0, right = 100000;
  while (abs(left - right) > 1e-9) {
    double d = (left + right) / 2;
    double pp = getP(r, k, d, n);
    if ((1 - pp) * 1000 < p) {
      right = d;
    } else
      left = d;
  }
  printf("%.8lf", left);
  return 0;
};
