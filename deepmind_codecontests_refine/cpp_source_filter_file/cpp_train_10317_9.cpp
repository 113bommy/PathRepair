#include <bits/stdc++.h>
using namespace std;
int dcmp(double a, double b) {
  return ((fabs(a - b) < (1e-9)) ? 0 : (a < b) ? -1 : +1);
}
double crossP(const complex<double> &v1, const complex<double> &v2) {
  return (conj(v1) * v2).imag();
}
double dotP(const complex<double> &v1, const complex<double> &v2) {
  return (conj(v1) * v2).real();
}
double lengthSqr(const complex<double> &p) { return dotP(p, p); }
double length(const complex<double> &p) { return hypot(p.real(), p.imag()); }
double fixAngle(double a) { return ((a > 1) ? 1 : (a < -1) ? -1 : a); }
bool same(const complex<double> &p1, const complex<double> &p2) {
  return ((dcmp(p1.real(), p2.real()) == 0 && dcmp(p1.imag(), p2.imag()) == 0)
              ? 1
              : 0);
}
double getAngle_A_abc(double a, double b, double c) {
  return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}
const int N = 1e5 + 1, M = 26;
char c[N];
int x[M];
int memo[N][M];
bool y[M];
int n;
int f(int i, int k) {
  if (i == M) return 0;
  int &ret = memo[i][k];
  if (ret != -1) return ret;
  if (x[i] == 0)
    ret = f(i + 1, k);
  else {
    int c1 = f(i + 1, k) + 1;
    int c2 = (~(1 << 31));
    if (k >= x[i]) c2 = f(i + 1, k - x[i]);
    if (c1 < c2)
      ret = c1;
    else
      ret = c2;
  }
  return ret;
}
void b(int i, int k) {
  if (i == M) return;
  int &ret = memo[i][k];
  if (x[i] == 0) {
    y[i] = 0;
    b(i + 1, k);
  } else {
    int c1 = f(i + 1, k) + 1;
    if (ret == c1)
      y[i] = 1, b(i + 1, k);
    else
      y[i] = 0, b(i + 1, k - x[i]);
  }
}
int main() {
  memset(memo, -1, sizeof(memo));
  memset(y, 1, sizeof(y));
  int k;
  scanf("%s %d", c, &k);
  n = strlen(c);
  for (__typeof(n) i = 0; i < n; ++i) x[c[i] - 'a']++;
  int ans = f(0, k);
  b(0, k);
  printf("%d\n", ans);
  for (__typeof(n) i = 0; i < n; ++i)
    if (y[c[i] - 'a']) printf("%c", c[i]);
  return 0;
}
