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
const int N = 1e5 + 1, L = 26;
char c[N];
bool del[L];
pair<int, int> x[L];
int main() {
  for (__typeof(int(L)) i = 0; i < int(L); ++i) x[i].first = 'a' + i;
  int n, k;
  scanf("%s %d", c, &k);
  n = strlen(c);
  for (__typeof(n) i = 0; i < n; ++i) x[c[i] - 'a'].second++;
  int ans = 0;
  for (__typeof(int(L)) i = 0; i < int(L); ++i)
    if (x[i].second) ans++;
  sort(x, x + n, [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
    return a.second < b.second;
  });
  for (__typeof((int)L) i = 0; i < (int)L; ++i)
    if (x[i].second && k >= x[i].second) {
      del[x[i].first - 'a'] = 1;
      k -= x[i].second;
      ans--;
    }
  printf("%d\n", ans);
  for (__typeof(n) i = 0; i < n; ++i)
    if (!del[c[i] - 'a']) printf("%c", c[i]);
  return 0;
}
