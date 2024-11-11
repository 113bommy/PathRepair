#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 0.00000000001;
int t, n, s[605];
double l, r, m;
struct N {
  double x, y;
  N(double a = 0, double b = 0) { x = a, y = b; }
} A[305];
struct L {
  N a, b;
  double f;
} a[605], b[305], c[605];
N operator+(N a, N b) { return N(a.x + b.x, a.y + b.y); }
N operator-(N a, N b) { return N(a.x - b.x, a.y - b.y); }
double operator*(N a, N b) { return a.x * b.y - a.y * b.x; }
L go(L s, double m) {
  N c = N(-sin(s.f) * m, cos(s.f) * m);
  s.a = s.a + c;
  s.b = s.b + c;
  return s;
}
bool operator<(L a, L b) {
  return fabs(a.f - b.f) > eps ? a.f < b.f : (a.b - a.a) * (b.b - a.a) < -eps;
}
N inter(L a, L b) {
  double k1, k2, t;
  k1 = (b.b - a.a) * (a.b - a.a);
  k2 = (a.b - a.a) * (b.a - a.a);
  t = k1 / (k1 + k2);
  return N(b.b.x + (b.a.x - b.b.x) * t, b.b.y + (b.a.y - b.b.y) * t);
}
bool jud(L a, L b, L t) {
  N p = inter(a, b);
  return (t.b - t.a) * (p - t.a) < eps;
}
void hpi() {
  int l = 1, r = 0;
  t = n;
  for (int i = 1; i <= t; ++i) {
    while (l < r && jud(b[r - 1], b[r], a[i])) --r;
    while (l < r && jud(b[l + 1], b[l], a[i])) ++l;
    b[++r] = a[i];
  }
  while (l < r && jud(b[r - 1], b[r], b[l])) --r;
  while (l < r && jud(b[l + 1], b[l], b[r])) ++l;
  t = r - l + 1;
}
bool jud() {
  hpi();
  if (t < 3) return 1;
  t = n;
  for (int i = 1; i <= t; ++i) a[i + t] = a[i];
  for (int i = 1, j = 1, k = 2; i <= t; ++i) {
    for (;; ++j) {
      if (fabs(c[j].f - a[i].f) < eps) continue;
      N x = inter(a[i], c[j]);
      if ((x.x - c[j].a.x) * (c[j].b.x - x.x) > -eps &&
          (x.y - c[j].a.y) * (c[j].b.y - x.y) > -eps)
        break;
    }
    A[i].x = 1e6;
    for (k = i + 1;; ++k) {
      if (fabs(a[k].f - a[i].f) < eps) continue;
      if (a[i].f + pi > pi) {
        if (a[k].f < a[i].f - eps && a[i].f - pi < a[k].f + eps) break;
      } else if (!(a[i].f < a[k].f - eps && a[k].f < a[i].f + pi - eps))
        break;
      N x = inter(a[i], a[k]);
      if ((x - c[j].a) * (c[j].b - c[j].a) > eps) break;
      if (A[i].x == 1e6)
        A[i] = x;
      else {
        if (a[i].b.x >= a[i].a.x && x.x >= A[i].x ||
            a[i].b.x <= a[i].a.x && x.x <= A[i].x)
          if (a[i].b.y >= a[i].a.y && x.y >= A[i].y ||
              a[i].b.y <= a[i].a.y && x.y <= A[i].y)
            A[i] = x;
      }
    }
    s[i] = k - i;
  }
  for (int i = 1; i <= t; ++i)
    if (s[i] + s[i + s[i] > t ? i + s[i] - t : i + s[i]] >= t) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &A[i].x, &A[i].y);
  A[n + 1] = A[1];
  for (int i = 1; i <= n; ++i) {
    c[i].a = A[i];
    c[i].b = A[i + 1];
    c[i].f = atan2(A[i + 1].y - A[i].y, A[i + 1].x - A[i].x);
  }
  sort(c + 1, c + n + 1);
  for (int i = 1; i <= n; ++i) c[i + n] = c[i];
  l = 0;
  r = 30000;
  for (int fuck = 1; fuck < 80; ++fuck) {
    m = (l + r) / 2;
    for (int i = 1; i <= n; ++i) a[i] = go(c[i], m);
    t = n;
    if (jud())
      r = m;
    else
      l = m;
  }
  m = r + 0.0000000001;
  for (int i = 1; i <= n; ++i) a[i] = go(c[i], m);
  jud();
  printf("%.8lf\n", m);
  for (int i = 1; i <= t; ++i) {
    n = i + s[i];
    if (n > t) n -= t;
    if (s[i] + s[n] >= t) {
      printf("%.8lf %.8lf\n", A[i].x, A[i].y);
      printf("%.8lf %.8lf\n", A[n].x, A[n].y);
      return 0;
    }
  }
  return 0;
}
