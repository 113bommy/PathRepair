#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-6;
double sgn(double x) {
  if (x < EPS && x > -EPS) return 0;
  return x < 0 ? -1 : 1;
}
typedef struct point {
  double x, y;
  void read() { scanf("%lf%lf", &x, &y); }
} Point;
struct line {
  point p1, p2;
  void read() { p1.read(), p2.read(); }
} wall, mir;
Point P1, P2, P3, P4;
double cross(point p1, point p2, point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
double dot(point p1, point p2, point p3) {
  return (p2.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p2.y - p1.y);
}
bool on_line(point p1, point p2, point p3) {
  return (sgn(cross(p1, p2, p3)) == 0 && sgn(dot(p1, p2, p3)) <= 0);
}
bool intersect(point p1, point p2, point p3, point p4) {
  if (on_line(p1, p3, p4) || on_line(p2, p3, p4)) return true;
  return (sgn(cross(p1, p2, p3) * cross(p1, p2, p4)) <= 0 &&
          sgn(cross(p3, p4, p1) * cross(p3, p4, p2)) <= 0);
}
double dist(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int main() {
  P1.read();
  P2.read();
  wall.read();
  mir.read();
  if (!intersect(wall.p1, wall.p2, P1, P2) &&
      !(intersect(P1, P2, mir.p1, mir.p2) ||
        (on_line(mir.p1, P1, P2) ^ on_line(mir.p2, P1, P2))))
    printf("YES\n");
  else {
    if (sgn(cross(mir.p1, mir.p2, P2)) == 0 ||
        sgn(cross(mir.p1, mir.p2, P1)) == 0)
      printf("NO\n");
    else {
      P3.x = mir.p1.x + dot(mir.p1, mir.p2, P2) / dist(mir.p1, mir.p2) *
                            (mir.p2.x - mir.p1.x) / dist(mir.p1, mir.p2);
      P3.y = mir.p1.y + dot(mir.p1, mir.p2, P2) / dist(mir.p1, mir.p2) *
                            (mir.p2.y - mir.p1.y) / dist(mir.p1, mir.p2);
      P3.x = 2 * (P3.x - P2.x) + P2.x;
      P3.y = 2 * (P3.y - P2.y) + P2.y;
      if (!intersect(mir.p1, mir.p2, P1, P3))
        printf("NO\n");
      else {
        double d = dist(P1, P3), t1 = 0.0, t2, t3;
        int ct = 0;
        t2 = d;
        while (ct <= 100) {
          t3 = (t1 + t2) / 2;
          P4.x = t3 * (P3.x - P1.x) / d + P1.x;
          P4.y = t3 * (P3.y - P1.y) / d + P1.y;
          if (sgn(cross(mir.p1, mir.p2, P4) * cross(mir.p1, mir.p2, P1)) > 0)
            t1 = t3;
          else if (sgn(cross(mir.p1, mir.p2, P4) * cross(mir.p1, mir.p2, P1)) <=
                   0)
            t2 = t3;
          ct++;
        }
        if (!intersect(wall.p1, wall.p2, P1, P4) &&
            !intersect(wall.p1, wall.p2, P2, P4))
          printf("YES\n");
        else
          printf("NO\n");
      }
    }
  }
  return 0;
}
