#include <bits/stdc++.h>
using namespace std;
const long double eps = 1.0e-12;
struct point {
  long long x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
};
point operator+(point &a, point &b) {
  point c(a.x + b.x, a.y + b.y);
  return c;
}
point operator-(point &a, point &b) {
  point c(a.x - b.x, a.y - b.y);
  return c;
}
long long operator*(point &a, point &b) { return a.x * b.x + a.y * b.y; }
int n, m;
point a[100010];
point b[20010];
int p[20010];
long long vect(point v, point u) { return v.x * u.y - v.y * u.x; }
long long absf(long long x) {
  if (x < 0) return -x;
  return x;
}
long long area(point x, point y, point w) { return absf(vect(y - x, w - x)); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%I64d%I64d", &x, &y);
    a[i] = point(x, y);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%I64d%I64d", &x, &y);
    b[i] = point(x, y);
  }
  for (int i = 0; i < m; i++) {
    if (area(a[0], a[1], b[i]) == 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (area(a[0], a[n - 1], b[i]) == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  bool bad = 0;
  for (int t = 0; t < m; t++) {
    int lo = 1;
    int hi = n - 1;
    while (lo < hi - 1) {
      int mi = (lo + hi) / 2;
      if (vect(a[mi] - a[0], b[t] - a[0]) >= 0) {
        hi = mi - 1;
      } else
        lo = mi;
    }
    while (lo < n - 1 && vect(a[lo + 1] - a[0], b[t] - a[0]) < 0) lo++;
    if (lo == n - 1 || (lo == 1 && vect(a[1] - a[0], b[t] - a[0]) >= 0)) {
      bad = 1;
      break;
    } else {
      if (area(a[lo], a[lo + 1], b[t]) == 0 ||
          area(a[0], a[lo], a[lo + 1]) != area(a[0], a[lo], b[t]) +
                                              area(a[0], a[lo + 1], b[t]) +
                                              area(a[lo], a[lo + 1], b[t])) {
        bad = 1;
        break;
      }
    }
  }
  if (bad)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
