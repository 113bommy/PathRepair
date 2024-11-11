#include <bits/stdc++.h>
double t[100010];
int main() {
  long long n, i, ax, ay, bx, by, tx, ty, x, y;
  double r, a, b;
  std::pair<double, int> q1 = std::make_pair(0.0, -1);
  std::pair<double, int> q2 = std::make_pair(0.0, -1);
  std::pair<double, int> w1 = std::make_pair(0.0, -1);
  std::pair<double, int> w2 = std::make_pair(0.0, -1);
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &ax, &ay, &bx, &by, &tx, &ty);
  scanf("%I64d", &n);
  scanf("%I64d %I64d", &x, &y);
  a = sqrt((x - ax) * (x - ax) + ((y - ay) * (y - ay)));
  b = sqrt((x - bx) * (x - bx) + ((y - by) * (y - by)));
  t[0] = sqrt((x - tx) * (x - tx) + ((y - ty) * (y - ty)));
  r += t[0] * 2;
  q1 = std::make_pair(t[0] - a, 0);
  w1 = std::make_pair(t[0] - b, 0);
  if (n > 1) {
    scanf("%I64d %I64d", &x, &y);
    a = sqrt((x - ax) * (x - ax) + ((y - ay) * (y - ay)));
    b = sqrt((x - bx) * (x - bx) + ((y - by) * (y - by)));
    t[1] = sqrt((x - tx) * (x - tx) + ((y - ty) * (y - ty)));
    r += t[1] * 2;
    q2 = std::make_pair(t[1] - a, 1);
    w2 = std::make_pair(t[1] - b, 1);
    if (q2.first > q1.first) std::swap(q1, q2);
    if (w2.first > w1.first) std::swap(w1, w2);
  }
  for (i = 2; i < n; i++) {
    scanf("%I64d %I64d", &x, &y);
    t[i] = sqrt((x - tx) * (x - tx) + ((y - ty) * (y - ty)));
    r += t[i] * 2;
    a = t[i] - sqrt((x - ax) * (x - ax) + ((y - ay) * (y - ay)));
    b = t[i] - sqrt((x - bx) * (x - bx) + ((y - by) * (y - by)));
    if (a > q1.first) {
      q2 = q1;
      q1 = std::make_pair(a, i);
    } else if (a > q2.first) {
      q2 = std::make_pair(a, i);
    }
    if (b > w1.first) {
      w2 = w1;
      w1 = std::make_pair(b, i);
    } else if (b > w2.first) {
      w2 = std::make_pair(b, i);
    }
  }
  if (n == 1) {
    if (q1.first > w1.first)
      r -= q1.first;
    else
      r -= w1.first;
  } else {
    if ((q1.first >= 0) && (w1.first >= 0)) {
      if (q1.second != w1.second) {
        r -= q1.first;
        r -= w1.first;
      } else {
        double max1 = q1.first + w2.first;
        double max2 = q2.first + w1.first;
        if (max2 > max1) max1 = max2;
        max2 = q1.first;
        if (max2 > max1) max1 = max2;
        max2 = w1.first;
        if (max2 > max1) max1 = max2;
        r -= max1;
      }
    } else {
      if (q1.first > w1.first)
        r -= q1.first;
      else
        r -= w1.first;
    }
  }
  printf("%.12f", r);
  return 0;
}
