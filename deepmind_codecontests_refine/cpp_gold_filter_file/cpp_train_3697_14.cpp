#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-11;
struct Point {
  double x, y;
  int operator<(const Point &a) const {
    if (fabs(a.x - x) > eps) return x < a.x;
    if (fabs(a.y - y) > eps) return y < a.y;
    return 0;
  }
  int operator==(const Point &a) const {
    if (fabs(a.x - x) > eps) return 0;
    if (fabs(a.y - y) > eps) return 0;
    return 1;
  }
} P[N], c[N];
double sqr(double x) { return x * x; }
int main() {
  int n;
  scanf("%d", &n);
  int T = 0;
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    if (C == 0) {
      ++T;
      continue;
    }
    double x = A * C / (sqr(A) + sqr(B));
    double y = B * C / (sqr(A) + sqr(B));
    P[m++] = (Point){x, y};
  }
  long long ans = (long long)T * (T - 1) / 2 * m;
  for (int i = 0; i < m; ++i) {
    map<Point, int> ext;
    for (int j = i + 1; j < m; ++j) {
      c[j].x = P[j].x - P[i].x;
      c[j].y = P[j].y - P[i].y;
      if (fabs(c[j].x) > eps) {
        if (c[j].x < 0) {
          c[j].x = -c[j].x;
          c[j].y = -c[j].y;
        }
      } else if (c[j].y < 0) {
        c[j].x = -c[j].x;
        c[j].y = -c[j].y;
      }
      double len = sqrt(sqr(c[j].x) + sqr(c[j].y)) / 360;
      c[j].x /= len;
      c[j].y /= len;
      ext[c[j]]++;
    }
    for (int j = i + 1; j < m; ++j)
      if (ext[c[j]] > 0) {
        int t = ext[c[j]];
        ext[c[j]] = 0;
        ans += (long long)t * (t - 1) / 2;
      }
  }
  cout << ans << endl;
}
