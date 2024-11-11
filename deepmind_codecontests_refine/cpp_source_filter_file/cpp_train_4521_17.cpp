#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(int x) {
  if (fabs(x) < eps) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
struct Point {
  double x, y;
  Point(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  double operator^(const Point &b) const { return x * b.y - y * b.x; }
  double operator*(const Point &b) const { return x * b.x + y * b.y; }
};
struct Line {
  Point s, e;
  double k;
  Line() {}
  Line(Point _s, Point _e) {
    s = _s;
    e = _e;
    k = atan2(e.y - s.y, e.x - s.x);
  }
  Point operator&(const Line &b) const {
    Point res = s;
    double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return res;
  }
};
bool HPIcmp(Line a, Line b) {
  if (fabs(a.k - b.k) > eps) return a.k < b.k;
  return ((a.s - b.s) ^ (b.e - b.s)) < 0;
}
Line Q[330];
void HPI(Line line[], int n, Point res[], int &resn) {
  int tot = n;
  sort(line, line + n, HPIcmp);
  tot = 1;
  for (int i = 1; i < n; i++)
    if (fabs(line[i].k - line[i - 1].k) > eps) line[tot++] = line[i];
  int head = 0, tail = 1;
  Q[0] = line[0];
  Q[1] = line[1];
  resn = 0;
  for (int i = 2; i < tot; i++) {
    if (fabs((Q[tail].e - Q[tail].s) ^ (Q[tail - 1].e - Q[tail - 1].s)) < eps ||
        fabs((Q[head].e - Q[head].s) ^ (Q[head + 1].e - Q[head + 1].s)) < eps)
      return;
    while (head < tail && (((Q[tail] & Q[tail - 1]) - line[i].s) ^
                           (line[i].e - line[i].s)) > eps)
      tail--;
    while (head < tail && (((Q[head] & Q[head + 1]) - line[i].s) ^
                           (line[i].e - line[i].s)) > eps)
      head++;
    Q[++tail] = line[i];
  }
  while (head < tail && (((Q[tail] & Q[tail - 1]) - Q[head].s) ^
                         (Q[head].e - Q[head].s)) > eps)
    tail--;
  while (head < tail && (((Q[head] & Q[head - 1]) - Q[tail].s) ^
                         (Q[tail].e - Q[tail].s)) > eps)
    head++;
  if (tail <= head + 1) return;
  for (int i = head; i < tail; i++) res[resn++] = Q[i] & Q[i + 1];
  if (head < tail - 1) res[resn++] = Q[head] & Q[tail];
}
double CalcArea(Point p[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++) res += (p[i] ^ p[(i + 1) % n]);
  return fabs(res / 2);
}
Point p[330][660];
Line line[330][660];
int a[330];
int cnt[330];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    for (int i = 0; i < k; i++) {
      p[i][0] = Point(i, 0);
      p[i][1] = Point(i + 1, 0);
      p[i][2] = Point(i + 1, 1000);
      p[i][3] = Point(i, 1000);
      line[i][0] = Line(p[i][0], p[i][1]);
      line[i][1] = Line(p[i][1], p[i][2]);
      line[i][2] = Line(p[i][2], p[i][3]);
      line[i][3] = Line(p[i][3], p[i][0]);
      cnt[i] = 4;
    }
    double area = k * 1000;
    while (n--) {
      for (int i = 0; i <= k; i++) scanf("%d", &a[i]);
      double nowarea = 0;
      for (int i = 0; i < k; i++) {
        line[i][cnt[i]++] = Line(Point(i, a[i]), Point(i + 1, a[i + 1]));
        int cc;
        HPI(line[i], cnt[i], p[i], cc);
        cnt[i] = 0;
        for (int j = 0; j < cc; j++) {
          if (fabs(p[i][j].x - p[i][(j + 1) % cc].x) < eps &&
              fabs(p[i][j].y - p[i][(j + 1) % cc].y) < eps)
            continue;
          line[i][cnt[i]++] = Line(p[i][j], p[i][(j + 1) % cc]);
        }
        nowarea += CalcArea(p[i], cc);
      }
      printf("%.6lf\n", area - nowarea);
      area = nowarea;
    }
  }
  return 0;
}
