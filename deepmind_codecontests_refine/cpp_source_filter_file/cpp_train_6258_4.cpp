#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const double eps = 1e-9;
inline int sgn(const double x) { return fabs(x) <= eps ? 0 : x > 0 ? 1 : -1; }
int n;
long long t;
int a[maxn], b[maxn];
double p[maxn];
struct matrix {
  static const int n = 3;
  double a[n][n];
  matrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
  }
  void mul(double v[n], double res[n]) {
    for (int i = 0; i < n; i++) {
      res[i] = 0;
      for (int j = 0; j < n; j++) {
        res[i] += a[i][j] * v[j];
      }
    }
  }
  matrix operator*(const matrix& b) const {
    matrix ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans.a[i][j] = 0;
        for (int k = 0; k < n; k++) {
          ans.a[i][j] += a[i][k] * b.a[k][j];
        }
      }
    }
    return ans;
  }
};
struct Line {
  double a, b;
  Line() {}
  Line(double _a, double _b) : a(_a), b(_b) {}
  bool operator<(const Line& l) const {
    return sgn(a - l.a) < 0 || (sgn(a - l.a) == 0 && sgn(b - l.b) < 0);
  }
  double eval(double x) { return a * x + b; }
};
bool bad(const Line& A, const Line& B, const Line& C) {
  return (A.b - B.b) / (B.a - A.a) > (B.b - C.b) / (C.a - B.a) - eps;
}
double M = 0;
void procFirst(matrix& x, const Line& l) {
  x.a[0][0] = 1 - l.a;
  x.a[0][1] = l.a * M;
  x.a[0][2] = l.b;
  x.a[1][1] = 1;
  x.a[1][2] = 1;
  x.a[2][2] = 1;
}
Line lx[maxn];
int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%lf", a + i, b + i, p + i);
    M = max(M, b[i] * p[i]);
  }
  for (int i = 0; i < n; i++) {
    lx[i] = Line(p[i], p[i] * a[i]);
  }
  sort(lx, lx + n);
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k >= 1 && sgn(lx[k - 1].a - lx[i].a) == 0) k--;
    while (k >= 2 && bad(lx[k - 2], lx[k - 1], lx[i])) k--;
    lx[k++] = lx[i];
  }
  n = k;
  long long curt = 0;
  double dp = 0;
  for (int i = 0; i < n && curt < t; i++) {
    double x = M * curt - dp;
    if (i + 1 < n && sgn(lx[i + 1].eval(x) - lx[i].eval(x)) > 0) continue;
    vector<matrix> as;
    as.push_back(matrix());
    procFirst(as[0], lx[i]);
    double v0[3] = {dp, (double)curt, 1.0}, v[3];
    for (;;) {
      if (curt + (1ll << (as.size() - 1)) > t) {
        as.pop_back();
        break;
      }
      as.back().mul(v0, v);
      double nx = M * v[1] - v[0];
      if (i + 1 < n && sgn(lx[i + 1].eval(nx) - lx[i].eval(nx)) > 0) {
        as.pop_back();
        break;
      }
      matrix nxt = as.back() * as.back();
      as.push_back(nxt);
    }
    for (; !as.empty();) {
      if (curt + (1ll << (as.size() - 1)) > t) {
        as.pop_back();
        continue;
      }
      as.back().mul(v0, v);
      double nx = M * v[1] - v[0];
      if (i + 1 < n && sgn(lx[i + 1].eval(nx) - lx[i].eval(nx)) > 0) {
        as.pop_back();
        continue;
      }
      curt += (1ll << (as.size() - 1));
      for (int j = 0; j < 3; j++) {
        v0[j] = v[j];
      }
      dp = v0[0];
      as.pop_back();
    }
    if (curt >= t) break;
    as.push_back(matrix());
    procFirst(as[0], lx[i]);
    as[0].mul(v0, v);
    curt++;
    dp = v[0];
  }
  printf("%.12f\n", dp);
}
