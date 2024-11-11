#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
struct Point {
  long long x, y;
  bool operator<(const Point& o) const { return x < o.x; }
};
long long floor(long long a, long long b) {
  return a >= 0 ? a / b : (a - b + 1) / b;
}
long long ceil(long long a, long long b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}
long long floor(const Point& a, const Point& b, long long x) {
  return a.y + floor((b.y - a.y) * (x - a.x), b.x - a.x);
}
long long ceil(const Point& a, const Point& b, long long x) {
  return a.y + ceil((b.y - a.y) * (x - a.x), b.x - a.x);
}
double gao(vector<Point> v) {
  int n = v.size();
  int x1 = min_element(v.begin(), v.end())->x;
  int x2 = max_element(v.begin(), v.end())->x;
  vector<Point> y1, y2;
  rotate(v.begin(), min_element(v.begin(), v.end()), v.end());
  for (int i = 1;; ++i) {
    if (y1.empty()) {
      if (v[i].x > x1) {
        y1.push_back(v[i - 1]);
      } else {
        continue;
      }
    }
    y1.push_back(v[i]);
    if (v[i].x == x2) {
      break;
    }
  }
  for (int i = n - 1;; --i) {
    if (y2.empty()) {
      if (v[i].x > x1) {
        y2.push_back(v[(i + 1) % n]);
      } else {
        continue;
      }
    }
    y2.push_back(v[i]);
    if (v[i].x == x2) {
      break;
    }
  }
  if (y1[0].y > y2[0].y || (y1[0].y == y2[0].y && y1[1].y > y2[1].y)) {
    swap(y1, y2);
  }
  vector<long long> x(x2 - x1 + 1, 0);
  int k1 = 1, k2 = 1;
  for (int i = x1; i <= x2; ++i) {
    if (y1[k1].x < i) {
      ++k1;
    }
    if (y2[k2].x < i) {
      ++k2;
    }
    x[i - x1] = floor(y2[k2 - 1], y2[k2], i) - ceil(y1[k1 - 1], y1[k1], i) + 1;
  }
  long long cnt = 0, sx = 0;
  for (int i = 0; i < (int)x.size(); ++i) {
    cnt += x[i];
    sx += i * x[i];
  }
  double sum = 0;
  for (int i = 0; i < (int)x.size(); ++i) {
    sum += (cnt - 1.0) * x[i] * i * i;
    sum -= 1.0 * x[i] * i * (sx - i);
  }
  return sum / cnt / (cnt - 1);
}
int main() {
  int n, x, y;
  double ans = 0;
  vector<Point> v;
  scanf("%d", &n);
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    v[i].x = x;
    v[i].y = y;
  }
  ans = gao(v);
  for (int i = 0; i < n; ++i) {
    swap(v[i].x, v[i].y);
  }
  ans += gao(v);
  printf("%.10lf\n", ans);
  return 0;
}
