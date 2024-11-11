#include <bits/stdc++.h>
using namespace std;
long long a[500005][2], b[500005], m = 1e9, siz, n, r;
double dist(long long x1, long long y1, long long x2, long long y2) {
  double f1 = x1, f2 = x2, g1 = y1, g2 = y2;
  double d = f1 - f2, d1 = y1 - y2;
  d = d * d;
  d1 = d1 * d1;
  d = d + d1;
  d = sqrt(d);
  return d;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long k = 0, t = 0, x, sum = 0, q = 0, z = 0, y = 0, i, j, l, x1, y1, x2,
            y2;
  cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  double d1, d2, d = 0;
  if (n == 1) {
    i = 0;
    d = dist(a[i][0], a[i][1], x, y);
    d2 = dist(a[i][0], a[i][1], x1, y1);
    d1 = dist(a[i][0], a[i][1], x2, y2);
    cout << setprecision(9) << min(d2, d1) + d;
    return 0;
  }
  pair<double, long long> p1[n], p2[n];
  for (i = 0; i < n; i++) {
    p1[i].first = dist(a[i][0], a[i][1], x, y) - dist(a[i][0], a[i][1], x1, y1);
    p1[i].second = i;
    p2[i].first = dist(a[i][0], a[i][1], x, y) - dist(a[i][0], a[i][1], x2, y2);
    p2[i].second = i;
  }
  sort(p1, p1 + n);
  sort(p2, p2 + n);
  if (p1[n - 1].second == p2[n - 1].second) {
    m = 2;
    k = p1[n - 1].second;
    q = p2[n - 2].second;
    if (p2[n - 2].first < 0) q = -1;
  } else {
    k = p1[n - 1].second;
    q = p2[n - 1].second;
    m = 1;
  }
  if (p1[n - 1].first < 0) {
    if (p2[n - 1].first < 0) {
      if (p1[n - 1].first > p2[n - 1].first)
        k = p1[n - 1].second, q = -1;
      else {
        k = -1;
        q = p2[n - 1].second;
      }
    } else {
      k = -1;
      q = p2[n - 1].second;
    }
  } else if (p2[n - 1].first < 0) {
    q = -1;
    k = p1[n - 1].second;
  }
  double r1 = 1e18;
read:
  for (i = 0; i < n; i++) {
    d1 = dist(a[i][0], a[i][1], x, y);
    if (k == i) {
      d2 = dist(a[i][0], a[i][1], x1, y1);
    } else if (q == i) {
      d2 = dist(a[i][0], a[i][1], x2, y2);
    } else {
      d2 = d1;
    }
    d = d + d1 + d2;
  }
  r1 = min(r1, d);
  if (m == 2) {
    m = 0;
    k = p1[n - 2].second;
    q = p2[n - 1].second;
    if (p1[n - 2].first < 0) k = -1;
    goto read;
  }
  cout << setprecision(9) << r1;
  return 0;
}
