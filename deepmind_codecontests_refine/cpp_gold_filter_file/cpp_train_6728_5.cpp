#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int ti = 150;
const double pi = acos(-1), eps = 1e-6;
double block = pi / ti;
int n, T, X;
struct point {
  double x, y;
} p[N];
inline point operator+(point a, point b) {
  return (point){a.x + b.x, a.y + b.y};
}
inline point operator-(point a, point b) {
  return (point){a.x - b.x, a.y - b.y};
}
inline point operator*(point a, double b) { return (point){a.x * b, a.y * b}; }
inline point operator/(point a, double b) { return (point){a.x / b, a.y / b}; }
inline int fcmp(double x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }
inline bool operator==(point a, point b) {
  return fcmp(a.x - b.x) == 0 && fcmp(a.y - b.y) == 0;
}
inline point rotate(point a, double ang) {
  return (point){a.x * cos(ang) - a.y * sin(ang),
                 a.x * sin(ang) + a.y * cos(ang)};
}
inline double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
inline point across(point a, point b, point c, point d) {
  double s1 = cross(a - c, d - c), s2 = cross(d - c, b - c);
  return a + (b - a) * s1 / (s1 + s2);
}
inline double len(point a) { return sqrt(a.x * a.x + a.y * a.y); }
inline double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double l[N];
inline double f(double an) {
  double ave = 0.0;
  point tmp = rotate((point){10000000.0, 0}, an),
        line1 = rotate((point){100.0, 0}, an), line2 = rotate(line1, pi / 2);
  for (int i = 1; i <= n; i++) {
    point P = p[i] + line2;
    point PP = across(P, p[i], (point){0, 0}, line1);
    l[i] = len(PP - tmp);
  }
  for (int i = n; i >= 1; i--) l[i] -= l[1], ave += l[i];
  double re = 0.0;
  sort(l + 1, l + 1 + n);
  ave /= n;
  for (int i = 1; i <= n / 2; i++)
    re += fabs(fabs(l[i] - ave) - fabs(l[n - i + 1] - ave));
  return re;
}
int ans, x, id[N];
pair<double, int> P[N];
point sum;
int check(int x) {
  point mid = (p[x] + p[X]) / 2;
  point mid2 = sum - mid;
  mid2 = (point){mid2.y, -mid2.x};
  for (int i = 1; i <= n; i++) P[i] = make_pair(dot(p[i], mid2), i);
  sort(P + 1, P + 1 + n);
  for (int i = 1; i <= n; i++) id[P[i].second] = i;
  if (id[X] + id[x] != n + 1) return 0;
  double ave = P[1].first + P[n].first;
  for (int i = 1; i <= n; i++)
    if (fcmp(P[i].first + P[n - i + 1].first - ave) != 0) return 0;
  return 1;
}
int main() {
  {
    sum = (point){0, 0};
    scanf("%d", &n);
    ans = 0;
    int inf = 1;
    for (int i = 1; i <= n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y), sum = sum + p[i];
    sum = sum / n;
    for (int i = 1; i <= n; i++) {
      bool is = 0;
      for (int j = 1; j <= n; j++)
        if (p[i] + p[j] == sum + sum) is = 1;
      if (!is) inf = 0, X = i;
    }
    if (inf) {
      puts("-1");
      return 0;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) ans += check(i);
    printf("%d\n", ans);
  }
  return 0;
}
