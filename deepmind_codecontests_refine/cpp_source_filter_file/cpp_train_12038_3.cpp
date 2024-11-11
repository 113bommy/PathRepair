#include <bits/stdc++.h>
using namespace std;
int n;
const double ep = 1e-8;
inline char nc() {
  static char buf[100000], *l = buf, *r = buf;
  return l == r && (r = (l = buf) + fread(buf, 1, 100000, stdin), l == r)
             ? EOF
             : *l++;
}
template <class T>
void read(T &x) {
  x = 0;
  int f = 1, ch = nc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 - '0' + ch;
    ch = nc();
  }
  x *= f;
}
struct pnt {
  double x, y;
  pnt(double x = 0, double y = 0) : x(x), y(y) {}
  pnt operator+(const pnt &b) const { return pnt(x + b.x, y + b.y); }
  pnt operator-(const pnt &b) const { return pnt(x - b.x, y - b.y); }
  pnt operator*(const double &b) { return pnt(x * b, y * b); }
  pnt operator/(const double &b) { return pnt(x / b, y / b); }
  double operator&(const pnt &b) { return x * b.x + y * b.y; }
  pnt rot() { return pnt(-y, x); }
  double dist() { return sqrt(x * x + y * y); }
  void input() { read(x), read(y); }
} p[100005], A, B, M, dir;
double r[100005], R, R2;
void answer(double R) {
  cout << fixed << setprecision(10) << R << endl;
  exit(0);
}
bool far(pnt C, double cr, pnt D, double dr) {
  double d = (C - D).dist();
  if (d > cr + dr - ep) return 1;
  return 0;
}
bool con(pnt C, double cr, pnt D, double dr) {
  double d = (C - D).dist();
  if (cr > d + dr - ep) return 1;
  return 0;
}
using pdd = pair<double, double>;
double far_yes_max(pnt p, double r) {
  double st = R, en = 1e11;
  if (!far(M, R, p, r)) return R;
  int step = 100;
  while (step--) {
    double mid = (en + st) * .5;
    pnt O = M + dir * sqrt(mid * mid - R2);
    if (far(O, mid, p, r))
      st = mid;
    else
      en = mid;
  }
  return st;
}
double con_yes_min(pnt p, double r) {
  double st = R, en = 1e11;
  int step = 100;
  while (step--) {
    double mid = (en + st) * .5;
    pnt O = M + dir * sqrt(mid * mid - R2);
    if (con(O, mid, p, r))
      en = mid;
    else
      st = mid;
  }
  return en;
}
double con_yes_max(pnt p, double r) {
  double st = R, en = 1e11;
  int step = 100;
  while (step--) {
    double mid = (en + st) * .5;
    pnt O = M + dir * sqrt(mid * mid - R2);
    if (con(O, mid, p, r))
      st = mid;
    else
      en = mid;
  }
  return st;
}
double far_yes_min(pnt p, double r) {
  double st = R, en = 1e11;
  int step = 100;
  while (step--) {
    double mid = (en + st) * .5;
    pnt O = M + dir * sqrt(mid * mid - R2);
    if (far(O, mid, p, r))
      en = mid;
    else
      st = mid;
  }
  return en;
}
vector<pdd> vec;
int main() {
  A.input(), B.input();
  read(n);
  for (int i = 1; i <= n; i++) {
    p[i].input();
    read(r[i]);
  }
  M = (A + B) * 0.5;
  R = (A - B).dist() * 0.5;
  R2 = R * R;
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    bool f = far(M, R, p[i], r[i]) || con(M, R, p[i], r[i]);
    if (!f) {
      flag = 1;
      break;
    }
  }
  if (!flag) answer(R);
  double ans = 1e12;
  dir = (B - A).rot();
  dir = dir / dir.dist();
  for (int t = 0; t < 2; t++) {
    vec.clear();
    for (int i = 1; i <= n; i++) {
      double f, s;
      if ((dir & p[i] - B) > -ep) {
        if (con(M, R, p[i], r[i])) continue;
        if (far(M, R, p[i], r[i]))
          f = far_yes_max(p[i], r[i]);
        else
          f = R;
        s = con_yes_min(p[i], r[i]);
      } else {
        if (far(M, R, p[i], r[i])) continue;
        if (con(M, R, p[i], r[i]))
          f = con_yes_max(p[i], r[i]);
        else
          f = R;
        s = far_yes_min(p[i], r[i]);
      }
      if (abs(s - f) > ep) vec.push_back(pdd(f, s));
    }
    sort(vec.begin(), vec.end());
    double res = R + 2 * ep;
    for (auto x : vec) {
      if (x.first < res - ep) {
        res = max(res, x.second);
      } else
        break;
    }
    ans = min(ans, res);
    dir = pnt(-dir.x, -dir.y);
  }
  answer(ans);
  return 0;
}
