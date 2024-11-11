#include <bits/stdc++.h>
using namespace std;
const double INF = 1e20, EPS = 1e-9, PI = acos((double)-1);
const double eps = 1e-12;
struct P {
  double first, second;
  P() {}
  P(double first, double second) : first(first), second(second) {}
  P operator+(P p) { return P(first + p.first, second + p.second); }
  P operator-(P p) { return P(first - p.first, second - p.second); }
  P operator*(double k) { return P(first * k, second * k); }
  double operator^(P p) { return first * p.second - second * p.first; }
  double operator*(P p) { return first * p.first + second * p.second; }
  P rot(double the) {
    double s = sin(the), c = cos(the);
    return P(first * c - second * s, first * s + second * c);
  }
  P rot() { return P(-second, first); }
  void eat() { scanf("%lf%lf", &first, &second); }
  double mag() { return sqrt(first * first + second * second); }
  double mag2() { return (first * first + second * second); }
  bool operator<(const P &p) const {
    if ((fabs((first) - (p.first)) < EPS)) return ((second) < (p.second) - EPS);
    return ((first) < (p.first) - EPS);
  }
  bool operator==(const P &p) const {
    return (fabs((first) - (p.first)) < EPS) &&
           (fabs((second) - (p.second)) < EPS);
  }
  P nor() {
    if ((fabs((mag()) - (0)) < EPS)) return *this;
    return *this * (1. / mag());
  }
  P ref(P n) {
    n = n.nor();
    return n * (n * (*this)) * 2 - *this;
  }
};
double A(P a, P b, P c) { return (b - a) ^ (c - a); }
bool SS(P a, P b, P c, P d, P &res) {
  P cd = d - c, ab = b - a;
  if ((fabs((cd ^ ab) - (0)) < EPS)) return 0;
  double t = ((a ^ ab) - (c ^ ab)) / (cd ^ ab);
  double s = ((c ^ cd) - (a ^ cd)) / (ab ^ cd);
  res = c + cd * t;
  return 1;
}
void Hull(P *p, P *h, int n, int &m) {
  sort(p, p + n);
  m = 0;
  for (int i = (0); i < (int)(n); i++) {
    while (m >= 2 && ((A(h[m - 2], h[m - 1], p[i])) < (0) + EPS)) --m;
    h[m++] = p[i];
  }
  int k = m;
  for (int i = n - 1; i >= 0; i--) {
    while (m > k && ((A(h[m - 2], h[m - 1], p[i])) < (0) + EPS)) --m;
    h[m++] = p[i];
  }
  if (m) --m;
}
const int N = 203600 * 5;
double R;
int n, nh;
P p[N], h[N];
bool bad[N] = {0};
P s[N];
int idx[N];
int ns;
double MyAcos(double first) {
  if ((fabs((first) - (-1)) < EPS)) return acos(-1.0);
  if ((fabs((first) - (1)) < EPS)) return acos(1.0);
  return acos(first);
}
double Ang(double a, double b, double c) {
  double first = (a * a + b * b - c * c) / (2 * a * b);
  return MyAcos(first);
}
bool Good(P A, P B, P C) {
  double area = (B - A) ^ (C - A);
  if ((fabs((area) - (0)) < EPS)) return 1;
  double d = (A - B).mag();
  double the = MyAcos(d / 2 / R);
  double alp = PI + 2 * the;
  double a = (B - C).mag(), b = (C - A).mag(), c = (A - B).mag();
  double bet = Ang(a, b, c);
  return ((bet) < (alp / 2) + EPS);
}
int main() {
  scanf("%d%lf", &n, &R);
  for (int i = (0); i < (int)(n); i++) p[i].eat();
  Hull(p, h, n, nh);
  ns = 0;
  for (int i = (0); i < (int)(nh * 2); i++) {
    while (ns >= 2 && !Good(s[ns - 2], h[i % nh], s[ns - 1])) {
      bad[idx[ns - 1]] = true;
      --ns;
    }
    s[ns] = h[i % nh];
    idx[ns] = i % nh;
    ns++;
  }
  vector<int> vec;
  for (int i = (0); i < (int)(nh); i++)
    if (!bad[i]) vec.push_back(i);
  double ans = 0;
  for (int i = (0); i < (int)(vec.size()); i++) {
    int ia = vec[i];
    int ib = vec[(i + 1) % vec.size()];
    double d = (h[ia] - h[ib]).mag();
    double the = Ang(R, R, d);
    ans += R * R * (the - sin(the)) * .5;
    ans += (h[ia] ^ h[ib]) * .5;
  }
  printf("%.20f\n", ans + 1e-11);
  return 0;
}
