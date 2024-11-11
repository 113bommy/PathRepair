#include <bits/stdc++.h>
typedef struct {
  double x;
  double y;
  double z;
} pt;
typedef struct {
  pt center;
  double r;
  int m;
  pt spike[100];
} mine;
double R;
int n;
pt A;
pt v;
double speed;
mine m[100];
pt normalize(pt a) {
  double d = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
  pt b;
  b.x = a.x / d;
  b.y = a.y / d;
  b.z = a.z / d;
  return b;
}
pt subtract(pt a, pt b) {
  pt c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  return c;
}
double dot_product(pt a, pt b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
double distance(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
pt proj(pt a, pt b) {
  pt aa = normalize(a);
  double d = dot_product(aa, b);
  pt c;
  c.x = d * aa.x;
  c.y = d * aa.y;
  c.z = d * aa.z;
  return c;
}
double distance_line(pt a, pt b) { return distance(proj(a, b), b); }
double _time = -1;
void update(double n_time) {
  if (_time == -1) {
    _time = n_time;
  }
  if (_time > n_time) {
    _time = n_time;
  }
}
int main() {
  int x, y, z;
  int vx, vy, vz;
  int r;
  scanf("%d %d %d %d %d %d %d", &x, &y, &z, &vx, &vy, &vz, &r);
  A.x = x;
  A.y = y;
  A.z = z;
  v.x = vx;
  v.y = vy;
  v.z = vz;
  speed = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  R = r;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c, d, mm;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &mm);
    m[i].center.x = a;
    m[i].center.y = b;
    m[i].center.z = c;
    double dist = distance_line(v, subtract(m[i].center, A));
    m[i].r = d;
    if (dist <= d + R + 1e-6) {
      pt p = proj(v, subtract(m[i].center, A));
      pt q = subtract(subtract(m[i].center, A), p);
      double abs_p = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
      double abs_q = sqrt(q.x * q.x + q.y * q.y + q.z * q.z);
      if (p.x * v.x > 0 || p.y * v.y > 0 || p.z * v.z > 0) {
        double dd = sqrt((d + R) * (d + R) - abs_q * abs_q);
        if (dd * 0 != 0) dd = 0;
        update((abs_p - dd) / speed);
      }
    }
    m[i].m = mm;
    for (int j = 0; j < mm; j++) {
      int aa, bb, cc;
      scanf("%d %d %d", &aa, &bb, &cc);
      m[i].spike[j].x = aa + a;
      m[i].spike[j].y = bb + b;
      m[i].spike[j].z = cc + c;
      dist = distance_line(v, subtract(m[i].spike[j], A));
      if (dist <= R + 1e-6) {
        pt p = proj(v, subtract(m[i].spike[j], A));
        pt q = subtract(subtract(m[i].spike[j], A), p);
        double abs_p = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
        double abs_q = sqrt(q.x * q.x + q.y * q.y + q.z * q.z);
        if (p.x * v.x > 0 || p.y * v.y > 0 || p.z * v.z > 0) {
          double dd = sqrt(R * R - abs_q * abs_q);
          if (dd * 0 != 0) dd = 0;
          update((abs_p) / speed);
        }
      }
    }
  }
  printf("%.10f\n", _time);
}
