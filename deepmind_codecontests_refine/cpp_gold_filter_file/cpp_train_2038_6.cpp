#include <bits/stdc++.h>
using namespace std;
complex<double> s, e, f[2], p[1010];
int g[2], t, n, l, r;
complex<double> operator*(const complex<double>& d, double c) {
  return complex<double>(c, 0) * d;
}
double crs(complex<double> a, complex<double> b) { return imag(a * conj(b)); }
double dis(complex<double> a, complex<double> b) { return abs(a - b); }
void ins(complex<double> a, complex<double> b, complex<double> c,
         complex<double> d, int id) {
  double t1 = crs(b - a, c - a), t2 = crs(d - a, b - a), t3 = crs(a - c, d - c),
         t4 = crs(d - c, b - c);
  if (fabs(t1) < 1e-9 && fabs(t2) < 1e-9) return;
  if (fabs(dis(a, c) + dis(c, b) - dis(a, b)) < 1e-9) {
    f[t] = c;
    g[t++] = id;
  }
  if (t1 * t2 > 1e-9 && t3 * t4 > 1e-9)
    f[t] = (t2 * c + t1 * d) * (1 / (t1 + t2)), g[t++] = id;
}
double calc(int st, int ed, complex<double> s, complex<double> e) {
  st = (st + 1) % n;
  double t = dis(s, p[st]) + dis(p[ed], e);
  for (int i = st; i != ed; i = (i + 1) % n) t += dis(p[i], p[i + 1]);
  return t;
}
int main() {
  scanf("%d%d", &l, &r), s = complex<double>(l, r);
  scanf("%d%d", &l, &r), e = complex<double>(l, r);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &l, &r), p[i] = complex<double>(l, r);
  p[n] = p[0];
  for (int i = 0; i < n; i++) ins(s, e, p[i], p[i + 1], i);
  if (t > 1) {
    if (dis(s, f[0]) > dis(s, f[1])) swap(f[0], f[1]), swap(g[0], g[1]);
    printf("%.9f\n",
           min(2 * dis(f[0], f[1]), min(calc(g[0], g[1], f[0], f[1]),
                                        calc(g[1], g[0], f[1], f[0]))) +
               dis(s, f[0]) + dis(f[1], e));
  } else
    printf("%.9f\n", dis(s, e));
}
