#include <bits/stdc++.h>
using namespace std;
struct vec {
  double x;
  double y;
  vec operator*(double d) {
    vec v;
    v.x = x * d;
    v.y = y * d;
    return v;
  }
  void norm() {
    double d;
    d = sqrt(x * x + y * y);
    x = x / d;
    y = y / d;
  }
};
struct pt {
  double x;
  double y;
  vec operator-(pt p) {
    vec v;
    v.x = x - p.x;
    v.y = y - p.y;
    return v;
  }
  pt operator+(vec v) {
    pt p;
    p.x = x + v.x;
    p.y = y + v.y;
    return p;
  }
};
int cross(pt p1, pt p2, pt p3) {
  double x1 = p2.x - p1.x;
  double y1 = p2.y - p1.y;
  double x2 = p3.x - p1.x;
  double y2 = p3.y - p1.y;
  double t = x1 * y2 - y1 * x2;
  if (fabs(t) < 0.0000001) return 0;
  if (t > 0)
    return 1;
  else
    return -1;
}
bool intersect(pt p1, pt p2, pt p3, pt p4, int tp) {
  long long a, b, c, d;
  a = cross(p1, p2, p3);
  b = cross(p1, p2, p4);
  c = cross(p3, p4, p1);
  d = cross(p3, p4, p2);
  if (fabs(a) < 0.0000001 && fabs(b) < 0.0000001) {
    if (tp == 1) {
      if (max(p1.x, p2.x) < min(p3.x, p4.x) ||
          min(p1.x, p2.x) > max(p3.x, p4.x))
        return 0;
      else
        return 1;
    } else
      return 0;
  }
  if (fabs(a) < 0.0000001) {
    if (p3.x > min(p1.x, p2.x) && p3.x < max(p1.x, p2.x))
      return 1;
    else
      return 0;
  }
  if (fabs(b) < 0.0000001) {
    if (p4.x > min(p1.x, p2.x) && p4.x < max(p1.x, p2.x))
      return 1;
    else
      return 0;
  }
  if (a * b < 0 && c * d < 0)
    return 1;
  else
    return 0;
}
double dis_from_line(pt p1, pt p2, pt p3) {
  double x1 = p3.x - p2.x;
  double y1 = p3.y - p2.y;
  double x2 = p1.x - p2.x;
  double y2 = p1.y - p2.y;
  double d = sqrt(x2 * x2 + y2 * y2);
  return (x1 * y2 - y1 * x2) / d;
}
double dis(pt p1, pt p2) {
  double x = p1.x - p2.x;
  double y = p1.y - p2.y;
  return sqrt(x * x + y * y);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct line {
  long long a, b, c;
};
int main() {
  pt pv, pp, pw1, pw2, pm1, pm2;
  cin >> pv.x >> pv.y >> pp.x >> pp.y >> pw1.x >> pw1.y >> pw2.x >> pw2.y >>
      pm1.x >> pm1.y >> pm2.x >> pm2.y;
  if (!intersect(pv, pp, pw1, pw2, 1)) {
    if (!intersect(pv, pp, pm1, pm2, 0)) {
      cout << "YES";
      return 0;
    }
  }
  int a1, a2;
  a1 = cross(pm1, pm2, pv);
  a2 = cross(pm1, pm2, pp);
  if (fabs(a1) < 0.0000001 || fabs(a2) < 0.0000001) {
    cout << "NO";
    return 0;
  }
  if ((a1 > 0 && a2 > 0) || (a1 < 0 && a2 < 0)) {
    double dv = dis_from_line(pm1, pm2, pv);
    double dp = dis_from_line(pm1, pm2, pp);
    double d = dis(pp, pv);
    double av = (d * dv) / (dp + dv);
    vec nn;
    nn = pp - pv;
    nn.norm();
    nn = nn * av;
    pt temp;
    temp = pv + nn;
    line m;
    m.a = -(pm2.y - pm1.y);
    m.b = pm2.x - pm1.x;
    m.c = -m.b * pm1.y - m.a * pm1.x;
    line m_n;
    m_n.a = m.b;
    m_n.b = -m.a;
    m_n.c = -m_n.a * temp.x - m_n.b * temp.y;
    pt sec;
    if (m.a == 0) {
      sec.y = -m.c / m.b;
      sec.x = temp.x;
    } else {
      sec.y =
          double(m.a * m_n.c - m_n.a * m.c) / double(m_n.a * m.b - m.a * m_n.b);
      sec.x = double(-m.b * sec.y - m.c) / double(m.a);
    }
    int minx = min(pm1.x, pm2.x);
    int miny = min(pm1.y, pm2.y);
    int maxx = max(pm1.x, pm2.x);
    int maxy = max(pm1.y, pm2.y);
    if (sec.x < minx || sec.x > maxx || sec.y < miny || sec.y > maxy) {
      cout << "NO";
      return 0;
    }
    if (intersect(sec, pv, pw1, pw2, 1)) {
      cout << "NO";
      return 0;
    }
    if (intersect(sec, pp, pw1, pw2, 1)) {
      cout << "NO";
      return 0;
    } else {
      cout << "YES";
      return 0;
    }
  } else {
    cout << "NO";
    return 0;
  }
  return 0;
}
