#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:836777216")
using namespace std;
int n;
int x[11111];
int y[11111];
int xa, ya, xv, yv, zv, f, xu, yu, zu;
const double eps = 1e-7;
double t1 = -1, t2 = -1;
const double SM_INF = 1e10;
struct SimplexM {
  int startN, N;
  vector<long double> old_c, c, b, res;
  vector<vector<long double> > system;
  double value;
  SimplexM(vector<long double> c) : N(c.size()), c(c) {}
  void add(vector<long double> r, double v, int sgn = 0) {
    for (; c.size() < r.size(); c.push_back(0))
      ;
    for (; r.size() < c.size(); r.push_back(0))
      ;
    if (sgn) r.push_back(-sgn), c.push_back(0);
    system.push_back(r), b.push_back(v);
  }
  void refresh_c_func(int pos, int row) {
    double begin = c[pos];
    for (int i(0); i < (N); i++) c[i] -= begin * system[row][i];
  }
  void gauss(int row, int col) {
    double v = system[row][col];
    for (int i(0); i < (N); i++) system[row][i] /= v;
    b[row] /= v;
    for (int i(0); i < (system.size()); i++)
      if (i != row) {
        v = system[i][col];
        for (int j(0); j < (N); j++) system[i][j] -= v * system[row][j];
        b[i] -= v * b[row];
      }
  }
  int solve() {
    N = c.size(), old_c = c;
    int m = system.size();
    for (int i(0); i < (m); i++) system[i].resize(N);
    startN = N;
    vector<int> base(m, -1);
    for (int i(0); i < (N); i++) {
      int nm = 0, pos = -1;
      for (int j(0); j < (m); j++)
        if (fabs(system[j][i]) > eps) nm++, pos = j;
      if (nm == 1 && fabs(system[pos][i] - 1) < eps && base[pos] == -1)
        base[pos] = i;
    }
    for (int i(0); i < (m); i++)
      if (base[i] == -1) {
        N++;
        c.push_back(SM_INF);
        for (int j(0); j < (m); j++) system[j].push_back(j == i ? 1 : 0);
        base[i] = N - 1;
      }
    for (int i(0); i < (m); i++) refresh_c_func(base[i], i);
    while (1) {
      int pos = -1, row = -1;
      for (int i(0); i < (N); i++)
        if (c[i] < -eps && (pos == -1 || c[i] < c[pos])) pos = i;
      if (pos == -1) break;
      double min_teta = 0;
      for (int i(0); i < (m); i++)
        if (system[i][pos] > eps &&
            (row == -1 || min_teta > b[i] / system[i][pos]))
          row = i, min_teta = b[i] / system[i][pos];
      if (row == -1) return -1;
      base[row] = pos;
      gauss(row, pos);
      refresh_c_func(pos, row);
    }
    for (int i(0); i < (m); i++)
      if (base[i] >= startN && fabs(b[i]) > eps) return -2;
    res.resize(startN, 0);
    for (int i(0); i < (m); i++)
      if (base[i] < startN) res[base[i]] = b[i];
    value = 0;
    for (int i(0); i < (startN); i++) value += res[i] * old_c[i];
    return 1;
  }
};
void go(double X, double Y) {
  vector<long double> c;
  c.push_back(1e5);
  c.push_back(1);
  c.push_back(0);
  SimplexM m(c);
  vector<long double> r1;
  r1.push_back(xv);
  r1.push_back(0);
  r1.push_back(xu);
  if (X < 0) {
    X = -X;
    for (int i(0); i < (r1.size()); i++) r1[i] = -r1[i];
  }
  m.add(r1, X, 0);
  vector<long double> r2;
  r2.push_back(yv);
  r2.push_back(0);
  r2.push_back(yu);
  if (Y < 0) {
    Y = -Y;
    for (int i(0); i < (r2.size()); i++) r2[i] = -r2[i];
  }
  m.add(r2, Y, 0);
  vector<long double> r3;
  r3.push_back(zv);
  r3.push_back(f);
  r3.push_back(zu);
  m.add(r3, 0, 0);
  if (m.solve() == 1) {
    double T1 = m.res[0];
    double T2 = m.res[1];
    if (t1 < -0.5 || t1 > T1 + eps || t1 > T1 - eps && t2 > T2 + eps)
      t1 = T1, t2 = T2;
  }
}
double det(double a, double b, double c, double d) { return a * d - b * c; }
int main() {
  cin >> n;
  for (int i(0); i < (n); i++) scanf("%d %d", x + i, y + i);
  x[n] = x[0], y[n] = y[0];
  cin >> xa >> ya;
  for (int i(0); i < (n + 1); i++) x[i] -= xa, y[i] -= ya;
  cin >> xv >> yv >> zv;
  cin >> f;
  cin >> xu >> yu >> zu;
  for (int i(0); i < (n); i++) go(x[i], y[i]);
  double dx = xv;
  double dy = yv;
  for (int q(0); q < (2); q++) {
    for (int i(0); i < (n); i++) {
      double d = det(x[i + 1] - x[i], -dx, y[i + 1] - y[i], -dy);
      if (fabs(d) > eps) {
        double t1 = det(-x[i], -dx, -y[i], -dy) / d;
        double t2 = det(x[i + 1] - x[i], -x[i], y[i + 1] - y[i], -y[i]) / d;
        if (t1 > 0 && t1 < 1 && t2 > 0) {
          go(dx * t2, dy * t2);
        }
      }
    }
    dx += zv / double(-zu) * xu;
    dy += zv / double(-zu) * yu;
  }
  printf("%.6lf %.6lf\n", t1, t2);
  return 0;
}
