#include <bits/stdc++.h>
int sgn(double x) { return x < -1e-10 ? -1 : x > 1e-10; }
struct v2d {
  double x, y;
  friend v2d operator+(const v2d& a, const v2d& b) {
    return v2d{a.x + b.x, a.y + b.y};
  }
  friend v2d operator-(const v2d& a, const v2d& b) {
    return v2d{a.x - b.x, a.y - b.y};
  }
  friend double operator|(const v2d& a, const v2d& b) {
    return a.x * b.x + a.y * b.y;
  }
  friend double operator*(const v2d& a, const v2d& b) {
    return a.x * b.y - a.y * b.x;
  }
  friend bool operator<(const v2d& a, const v2d& b) {
    return sgn(a.x - b.x) ? sgn(a.x - b.x) < 0 : sgn(a.y - b.y) < 0;
  }
};
double cross(v2d a, v2d b, v2d c) { return (b - a) * (c - a); }
int oritest(v2d a, v2d b, v2d c) { return sgn((b - a) | (c - a)); }
int is2s(v2d a, v2d b, v2d c, v2d d, v2d& p) {
  double s1, s2;
  int d1, d2, d3, d4;
  d1 = sgn(s1 = cross(a, b, c));
  d2 = sgn(s2 = cross(a, b, d));
  d3 = sgn(cross(c, d, a));
  d4 = sgn(cross(c, d, b));
  if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) {
    p.x = (c.x * s2 - d.x * s1) / (s2 - s1);
    p.y = (c.y * s2 - d.y * s1) / (s2 - s1);
    return 1;
  }
  if (d1 == 0 && oritest(c, a, b) <= 0 || d2 == 0 && oritest(d, a, b) <= 0 ||
      d3 == 0 && oritest(a, c, d) <= 0 || d4 == 0 && oritest(b, c, d) <= 0)
    return 2;
  return 0;
}
int n, k;
struct poly {
  std::vector<v2d> p;
  double area() {
    double ret = 0;
    for (size_t i = 0; i + 1 < p.size(); ++i)
      ret += (p[i].y + p[i + 1].y) * (p[i + 1].x - p[i].x) / 2;
    return ret;
  }
  poly union_with(const poly& o) {
    poly ret;
    std::vector<v2d> t;
    for (size_t i = 0; i < p.size(); ++i)
      if (sgn(round(p[i].x) - p[i].x) == 0)
        t.push_back(p[i]);
      else if (sgn((o.p[(int)ceil(p[i].x)] - o.p[(int)floor(p[i].x)]) *
                   (p[i] - o.p[(int)floor(p[i].x)])) >= 0)
        t.push_back(p[i]);
    for (size_t i = 0; i < o.p.size(); ++i) t.push_back(o.p[i]);
    v2d ip;
    for (size_t j = 0; j + 1 < p.size(); ++j)
      for (size_t i = (p[j].x > 3 ? (int)(p[j].x - 3) : 0);
           i <= (ceil(p[j].x) + 3 > k ? k : (int)ceil(p[j].x) + 3); ++i)
        if (is2s(o.p[i], o.p[i + 1], p[j], p[j + 1], ip) == 1) t.push_back(ip);
    std::sort(t.begin(), t.end());
    for (size_t i = 0; i < t.size(); ++i)
      if (i == t.size() - 1 || sgn(t[i + 1].x - t[i].x) > 0)
        ret.p.push_back(t[i]);
    return ret;
  }
  void print() {
    for (auto& i : p) printf("%f,%f ", i.x, i.y);
    puts("");
  }
} cur;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= k; ++i) {
    v2d t = v2d{1. * i, 0};
    scanf("%lf", &t.y);
    cur.p.push_back(t);
  }
  printf("%.12f\n", cur.area());
  for (int i = 1; i < n; ++i) {
    poly tp;
    for (int j = 0; j <= k; ++j) {
      v2d t = v2d{1. * j, 0};
      scanf("%lf", &t.y);
      tp.p.push_back(t);
    }
    poly nxt = cur.union_with(tp);
    printf("%.12f\n", nxt.area() - cur.area());
    cur = nxt;
  }
  return 0;
}
