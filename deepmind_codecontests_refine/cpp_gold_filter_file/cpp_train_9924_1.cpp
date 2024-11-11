#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const double eps = 1e-8;
int sgn(double x) { return (x > eps) - (x < -eps); }
bool Cmp(const complex<double>& a, const complex<double>& b) {
  if (sgn(a.real() - b.real()) != 0) return a.real() < b.real();
  return a.imag() < b.imag();
}
double cross(const complex<double>& a, const complex<double>& b) {
  return (conj(a) * b).imag();
}
double dot(const complex<double>& a, const complex<double>& b) {
  return (conj(a) * b).real();
}
int n;
double R;
complex<double> p[N], q[N];
int l[N], r[N], del[N], _, version[N];
priority_queue<pair<double, pair<int, int> > > Q;
void Del(int x) {
  del[x] = true;
  r[l[x]] = r[x], l[r[x]] = l[x];
}
void Update(int x) {
  if (dot(q[l[x]] - q[x], q[r[x]] - q[x]) > 0) {
    version[x] = -1;
    return;
  }
  complex<double>&a = q[x], &b = q[l[x]], &c = q[r[x]];
  double r =
      abs(a - b) * abs(a - c) * abs(b - c) / (2 * fabs(cross(a - b, c - b)));
  Q.push(make_pair(r, make_pair(x, version[x] = ++_)));
}
int main() {
  scanf("%d%lf", &n, &R);
  double x, y;
  for (int i = 0; i < (n); ++i)
    scanf("%lf%lf", &x, &y), p[i] = complex<double>(x, y);
  if (n == 1) return puts("0.000000"), 0;
  sort(p, p + n, Cmp);
  q[0] = p[0];
  int tp = 1;
  for (int i = 1; i < (n); ++i) {
    while (tp >= 2 && cross(q[tp - 1] - q[tp - 2], p[i] - q[tp - 2]) <= 0) --tp;
    q[tp++] = p[i];
  }
  int tt = tp;
  for (int i = n - 1; i >= 0; --i) {
    while (tp > tt && cross(q[tp - 1] - q[tp - 2], p[i] - q[tp - 2]) <= 0) --tp;
    q[tp++] = p[i];
  }
  n = tp - 1;
  for (int i = 0; i < (n); ++i) l[i] = (i - 1 + n) % n, r[i] = (i + 1) % n;
  for (int i = 0; i < (n); ++i)
    if (dot(q[l[i]] - q[i], q[r[i]] - q[i]) < 0) Update(i);
  while ((int)(Q).size() && Q.top().first > R) {
    pair<int, int> tp = Q.top().second;
    Q.pop();
    int c = tp.first, ver = tp.second;
    if (ver != version[c]) continue;
    Del(c);
    Update(l[c]);
    Update(r[c]);
  }
  int s = 0;
  while (del[s]) ++s;
  double ans = 0.;
  int i = s;
  do {
    ans += cross(q[i], q[r[i]]) / 2;
    double angle = 2 * asin(abs(q[i] - q[r[i]]) / (2 * R));
    ans += R * R * (angle - sin(angle)) / 2;
    i = r[i];
  } while (i != s);
  printf("%.10f\n", ans);
  return 0;
}
