#include <bits/stdc++.h>
using namespace std;
typedef char* cstr;
const int oo = (~0u) >> 1;
const long long int ooll = (~0ull) >> 1;
const double inf = 1e100;
const double eps = 1e-9;
const double pi = acos(-1.0);
template <typename type>
inline bool cmax(type& a, const type& b) {
  return a < b ? a = b, true : false;
}
template <typename type>
inline bool cmin(type& a, const type& b) {
  return a > b ? a = b, true : false;
}
template <typename type>
inline int sgn(const type& first) {
  return (first > 0) - (first < 0);
}
template <>
inline int sgn(const double& first) {
  return (first > +eps) - (first < -eps);
}
template <typename type>
void inc(vector<type>& st, int first, type inc) {
  while (first < ((int)(st).size()))
    st[first] += inc, first += (first) & (-(first));
}
template <typename type>
type sum(vector<type>& st, int first) {
  type s = 0;
  while (first > 0) s += st[first], first -= (first) & (-(first));
  return s;
}
int main() {
  pair<double, double> p, s;
  double pv, sv, R, r;
  cin >> p.first >> p.second >> pv;
  R = sqrt((p.first) * (p.first) + (p.second) * (p.second));
  cin >> s.first >> s.second >> sv >> r;
  double pt = atan2(p.second, p.first);
  double st = atan2(s.second, s.first);
  double sr = sqrt((s.first) * (s.first) + (s.second) * (s.second));
  double a = acos(r / sr) + acos(r / R);
  double myeps = 1e-5;
  double ans = inf, nxtdel, nnxtdel, nnnxtdel, nnnnxtdel;
  for (double delta = -pi; delta <= pi; delta += myeps) {
    double tt = st + delta;
    pair<double, double> t;
    t.first = R * cos(tt), t.second = R * sin(tt);
    double t1;
    if (abs(delta) <= a)
      t1 = sqrt((t.first - s.first) * (t.first - s.first) +
                (t.second - s.second) * (t.second - s.second)) /
           sv;
    else
      t1 = ((abs(delta) - a) * r + sqrt((sr) * (sr) - (r) * (r)) +
            sqrt((R) * (R) - (r) * (r))) /
           sv;
    double t2 = (tt - pt) * R / pv;
    double first = (t1 - t2) / (2.0 * pi * R / pv);
    if (first - int(first) <= eps)
      first = int(first);
    else
      first = int(first + 1);
    double rt = first * (2.0 * pi * R / pv) + t2;
    if (cmin(ans, rt)) nxtdel = delta;
  }
  for (double del = -1.0; del <= 1.0; del += myeps) {
    double delta = nxtdel + del * (1e-3);
    double tt = st + delta;
    pair<double, double> t;
    t.first = R * cos(tt), t.second = R * sin(tt);
    double t1;
    if (abs(delta) <= a)
      t1 = sqrt((t.first - s.first) * (t.first - s.first) +
                (t.second - s.second) * (t.second - s.second)) /
           sv;
    else
      t1 = ((abs(delta) - a) * r + sqrt((sr) * (sr) - (r) * (r)) +
            sqrt((R) * (R) - (r) * (r))) /
           sv;
    double t2 = (tt - pt) * R / pv;
    double first = (t1 - t2) / (2.0 * pi * R / pv);
    if (first - int(first) <= eps)
      first = int(first);
    else
      first = int(first + 1);
    double rt = first * (2.0 * pi * R / pv) + t2;
    if (cmin(ans, rt)) nnxtdel = delta;
  }
  for (double del = -1.0; del <= 1.0; del += myeps) {
    double delta = nnxtdel + del * (1e-6);
    double tt = st + delta;
    pair<double, double> t;
    t.first = R * cos(tt), t.second = R * sin(tt);
    double t1;
    if (abs(delta) <= a)
      t1 = sqrt((t.first - s.first) * (t.first - s.first) +
                (t.second - s.second) * (t.second - s.second)) /
           sv;
    else
      t1 = ((abs(delta) - a) * r + sqrt((sr) * (sr) - (r) * (r)) +
            sqrt((R) * (R) - (r) * (r))) /
           sv;
    double t2 = (tt - pt) * R / pv;
    double first = (t1 - t2) / (2.0 * pi * R / pv);
    if (first - int(first) <= eps)
      first = int(first);
    else
      first = int(first + 1);
    double rt = first * (2.0 * pi * R / pv) + t2;
    if (cmin(ans, rt)) nnnxtdel = delta;
  }
  for (double del = -1.0; del <= 1.0; del += myeps) {
    double delta = nnnxtdel + del * (1e-9);
    double tt = st + delta;
    pair<double, double> t;
    t.first = R * cos(tt), t.second = R * sin(tt);
    double t1;
    if (abs(delta) <= a)
      t1 = sqrt((t.first - s.first) * (t.first - s.first) +
                (t.second - s.second) * (t.second - s.second)) /
           sv;
    else
      t1 = ((abs(delta) - a) * r + sqrt((sr) * (sr) - (r) * (r)) +
            sqrt((R) * (R) - (r) * (r))) /
           sv;
    double t2 = (tt - pt) * R / pv;
    double first = (t1 - t2) / (2.0 * pi * R / pv);
    if (first - int(first) <= eps)
      first = int(first);
    else
      first = int(first + 1);
    double rt = first * (2.0 * pi * R / pv) + t2;
    if (cmin(ans, rt)) nnnnxtdel = delta;
  }
  for (double del = -1.0; del <= 1.0; del += myeps) {
    double delta = nnnnxtdel + del * (1e-12);
    double tt = st + delta;
    pair<double, double> t;
    t.first = R * cos(tt), t.second = R * sin(tt);
    double t1;
    if (abs(delta) <= a)
      t1 = sqrt((t.first - s.first) * (t.first - s.first) +
                (t.second - s.second) * (t.second - s.second)) /
           sv;
    else
      t1 = ((abs(delta) - a) * r + sqrt((sr) * (sr) - (r) * (r)) +
            sqrt((R) * (R) - (r) * (r))) /
           sv;
    double t2 = (tt - pt) * R / pv;
    double first = (t1 - t2) / (2.0 * pi * R / pv);
    if (first - int(first) <= eps)
      first = int(first);
    else
      first = int(first + 1);
    double rt = first * (2.0 * pi * R / pv) + t2;
    cmin(ans, rt);
  }
  printf("%.50f\n", ans);
}
