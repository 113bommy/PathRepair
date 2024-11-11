#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12, Pi = 3.14159265358979323846;
long double read() {
  double x;
  scanf("%lf", &x);
  return x;
}
int n, q, lid = -1, hid = -1, A, B, C, D, E;
int X, Y, Z;
struct Point {
  long double x, y;
} pt[60010], O, M, N;
long double operator*(const Point x, const Point y) {
  return x.x * y.y - x.y * y.x;
}
Point operator-(Point x, Point y) { return (Point){x.x - y.x, x.y - y.y}; }
Point operator+(Point x, Point y) { return (Point){x.x + y.x, x.y + y.y}; }
struct Line {
  Point x, y;
};
Point get_intersect(Line x, Line y) {
  long double a1 = x.x.y - x.y.y, a2 = y.x.y - y.y.y, b1 = x.y.x - x.x.x,
              b2 = y.y.x - y.x.x, c1 = x.x.x * x.y.y - x.x.y * x.y.x,
              c2 = y.x.x * y.y.y - y.x.y * y.y.x;
  return (Point){(c1 * b2 - c2 * b1) / (b1 * a2 - b2 * a1),
                 (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1)};
}
long long sum[60010];
long double check(long double x) {
  long double y = x + Pi, res = 0.0;
  Point a = (Point){cos(x), sin(x)}, b = (Point){-cos(x), -sin(x)};
  int l = X, r = Y, mid;
  if (a * (pt[l] - O) > 0.0) {
    Point t = get_intersect((Line){O, O + a}, (Line){pt[l - 1], pt[l]});
    res += (O * t + t * pt[l] + (sum[r - 1] - sum[l - 1]) + pt[r] * M + M * O) -
           (O * N + N * t + t * O);
  } else if (a * (pt[r] - O) < 0.0) {
    Point t = get_intersect((Line){O, O + a}, (Line){pt[r], pt[r + 1]});
    res += (O * t + t * M + M * O) -
           (O * N + N * pt[l] + (sum[r - 1] - sum[l - 1]) + pt[r] * t + t * O);
  } else {
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (a * (pt[mid] - O) < 0.0)
        l = mid;
      else
        r = mid - 1;
    }
    Point t = get_intersect((Line){O, O + a}, (Line){pt[l], pt[l + 1]});
    res += (O * t + t * pt[l + 1] + (sum[Y - 1] - sum[l]) + pt[Y] * M + M * O) -
           (O * N + N * pt[X] + (sum[l - 1] - sum[X - 1]) + pt[l] * t + t * O);
  }
  l = Y + 1, r = Z;
  if (b * (pt[l] - O) > 0.0) {
    Point t = get_intersect((Line){O, O + b}, (Line){pt[l - 1], pt[l]});
    res += (O * M + M * t + t * O) -
           (O * t + t * pt[l] + (sum[Z - 1] - sum[l - 1]) + pt[Z] * N + N * O);
  } else if (b * (pt[r] - O) < 0.0) {
    Point t = get_intersect((Line){O, O + b}, (Line){pt[r], pt[r + 1]});
    res += (O * M + M * pt[l] + (sum[r - 1] - sum[l - 1]) + pt[r] * t + t * O) -
           (O * t + t * N + N * O);
  } else {
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (b * (pt[mid] - O) < 0.0)
        l = mid;
      else
        r = mid - 1;
    }
    Point t = get_intersect((Line){O, O + b}, (Line){pt[l], pt[l + 1]});
    res += (O * M + M * pt[Y + 1] + (sum[l - 1] - sum[Y]) + pt[l] * t + t * O) -
           (O * t + t * pt[l + 1] + (sum[Z - 1] - sum[l]) + pt[Z] * N + N * O);
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = n; i; i--) {
    pt[i].x = read(), pt[i].y = read();
    for (int j = 1; j <= 5; j++) pt[i + j * n] = pt[i];
  }
  for (int i = 1; i < 6 * n; i++)
    sum[i] = sum[i - 1] + (long long)(pt[i] * pt[i + 1] + eps);
  for (int i = 1; i <= n; i++) {
    if (lid == -1 || pt[i].y < pt[lid].y) lid = i;
    if (hid == -1 || pt[i].y > pt[hid].y) hid = i;
  }
  A = lid, B = hid + n * 3, C = lid + n * 5;
  while (B - A >= n) A += n;
  while (C - B >= n) C -= n;
  while (q--) {
    long double x = read(), y = read();
    O = (Point){x, y};
    int tmp_l = A, tmp_r = B, tmp_mid;
    while (tmp_l < tmp_r) {
      tmp_mid = tmp_l + tmp_r >> 1;
      if (y + eps < pt[tmp_mid].y)
        tmp_r = tmp_mid;
      else
        tmp_l = tmp_mid + 1;
    }
    D = tmp_l;
    tmp_l = B, tmp_r = C;
    while (tmp_l < tmp_r) {
      tmp_mid = tmp_l + tmp_r + 1 >> 1;
      if (y + eps < pt[tmp_mid].y)
        tmp_l = tmp_mid;
      else
        tmp_r = tmp_mid - 1;
    }
    E = tmp_l;
    X = D, Y = E, Z = D;
    while (Z <= C) Z += n;
    Z--;
    N = get_intersect((Line){pt[X - 1], pt[X]}, (Line){O, O + (Point){1, 0}});
    M = get_intersect((Line){pt[Y], pt[Y + 1]}, (Line){O, O + (Point){-1, 0}});
    long double l = 0, r = Pi, mid, lv = check(l);
    if (lv < 0)
      for (int i = 1; i <= 60; i++) {
        mid = (l + r) / 2;
        if (check(mid) < 0)
          l = mid;
        else
          r = mid;
      }
    else
      for (int i = 1; i <= 60; i++) {
        mid = (l + r) / 2;
        if (check(mid) < 0)
          r = mid;
        else
          l = mid;
      }
    printf("%.20lf\n", (double)(fabs(l) < eps || fabs(l - Pi) < eps ? 0.0 : l));
  }
  return 0;
}
