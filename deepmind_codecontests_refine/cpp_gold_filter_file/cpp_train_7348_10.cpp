#include <bits/stdc++.h>
using namespace std;
const int MX = 10005;
const double EPS = 1e-8;
struct Point {
  double x, y;
};
Point operator+(Point a, Point b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}
Point operator*(Point a, double k) {
  a.x *= k;
  a.y *= k;
  return a;
}
Point operator-(Point a, Point b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}
void Read(Point& p) {
  int x, y;
  ignore = scanf("%d %d", &x, &y);
  p.x = x;
  p.y = y;
}
double cp(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double dist(Point p, Point v, Point q) { return (cp(p, v) - cp(q, v)); }
Point intersect(Point p, Point v, Point q, Point u) {
  double T = (cp(p, v) - cp(q, v)) / cp(u, v);
  return q + u * T;
}
Point p[2 * MX];
int n;
double S[2 * MX];
double Calc(Point q, double alpha) {
  Point v = {cos(alpha), sin(alpha)};
  int low, high;
  {
    if (dist(q, v, p[0]) >= dist(q, v, p[n - 1])) {
      high = 0;
    } else {
      high = n - 1;
    }
    int L = 0, R = n - 2;
    while (L <= R) {
      int M = (L + R) / 2;
      bool good;
      if (dist(q, v, p[0]) >= dist(q, v, p[n - 1])) {
        good = (dist(q, v, p[M + 1]) >= dist(q, v, p[M]) &&
                dist(q, v, p[M + 1]) >= dist(q, v, p[0]));
      } else {
        good = (dist(q, v, p[M + 1]) >= dist(q, v, p[M]) ||
                dist(q, v, p[M + 1]) <= dist(q, v, p[0]));
      }
      if (good) {
        L = M + 1;
        high = M + 1;
      } else {
        R = M - 1;
      }
    }
  }
  {
    if (dist(q, v, p[0]) <= dist(q, v, p[n - 1])) {
      low = 0;
    } else {
      low = n - 1;
    }
    int L = 0, R = n - 2;
    while (L <= R) {
      int M = (L + R) / 2;
      bool good;
      if (dist(q, v, p[0]) <= dist(q, v, p[n - 1])) {
        good = (dist(q, v, p[M + 1]) <= dist(q, v, p[M]) &&
                dist(q, v, p[M + 1]) <= dist(q, v, p[0]));
      } else {
        good = (dist(q, v, p[M + 1]) <= dist(q, v, p[M]) ||
                dist(q, v, p[M + 1]) >= dist(q, v, p[0]));
      }
      if (good) {
        L = M + 1;
        low = M + 1;
      } else {
        R = M - 1;
      }
    }
  }
  int left, right;
  {
    int L = low, R = high;
    if (R < L) R += n;
    left = L;
    while (L <= R) {
      int M = (L + R) / 2;
      if (dist(q, v, p[M]) <= 0) {
        left = M;
        L = M + 1;
      } else {
        R = M - 1;
      }
    }
  }
  {
    int L = high, R = low;
    if (R < L) R += n;
    right = L;
    while (L <= R) {
      int M = (L + R) / 2;
      if (dist(q, v, p[M]) >= 0) {
        right = M;
        L = M + 1;
      } else {
        R = M - 1;
      }
    }
  }
  if (left >= n) left -= n;
  if (right >= n) right -= n;
  if (right < left) right += n;
  double res = S[right] - S[left + 1];
  Point p0 = intersect(q, v, p[left], p[left + 1] - p[left]);
  Point p1 = intersect(q, v, p[right], p[right + 1] - p[right]);
  res += cp(p[right], p1);
  res += cp(p1, p0);
  res += cp(p0, p[left + 1]);
  return res;
}
int main() {
  int q;
  ignore = scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) Read(p[i]);
  reverse(p, p + n);
  for (int i = 0; i < n; i++) {
    p[i + n] = p[i];
  }
  for (int i = 1; i < 2 * n; i++) {
    S[i] = S[i - 1] + cp(p[i - 1], p[i]);
  }
  double total = S[n];
  while (q--) {
    Point P;
    Read(P);
    double L = 0, R = acos(-1);
    double tmp = Calc(P, 0);
    if (abs(total - 2 * tmp) < EPS) {
      printf("%.15lf\n", 0.0);
      continue;
    }
    bool left_above = (total - 2 * tmp > 0);
    for (int rep = 0; rep < 60; rep++) {
      double M = (L + R) / 2;
      tmp = Calc(P, M);
      if (abs(total - 2 * tmp) < EPS) break;
      bool above = (total - 2 * tmp > 0);
      if (above == left_above) {
        L = M;
      } else {
        R = M;
      }
    }
    printf("%.15lf\n", (L + R) / 2);
  }
}
