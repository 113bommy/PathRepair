#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
  point operator+(const point A) { return point(x + A.x, y + A.y); }
  point operator-(const point A) { return point(x - A.x, y - A.y); }
  double operator*(const point A) { return x * A.y - y * A.x; }
  point operator*(const double A) { return point(x * A, y * A); }
};
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
point Line_Intersection(point p, point v, point q, point w) {
  point u = p - q;
  double t = (w * u) / (v * w);
  return p + v * t;
}
int N;
const int maxn = 2010;
double D[maxn];
point A[maxn];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int aa, bb, cc;
    scanf("%d%d%d", &aa, &bb, &cc);
    if (aa == 0)
      A[i] = Line_Intersection(point(0, (-cc + 0.0) / bb), point(-bb, aa),
                               point(0, 0), point(aa, bb));
    else
      A[i] = Line_Intersection(point((-cc + 0.0) / aa, 0), point(-bb, aa),
                               point(0, 0), point(aa, bb));
  }
  int ans = 0;
  const double pi = acos(-1.0);
  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++)
      if (j != i) {
        point t = A[j] - A[i];
        if (t.x == 0 && t.y == 0) {
          ans += N - 2;
          continue;
        }
        D[++cnt] = atan2(t.y, t.x);
        while (D[cnt] >= 0) D[cnt] -= pi;
      }
    sort(D + 1, D + N);
    for (int j = 1; j < N; j++)
      ans += j - (upper_bound(D + 1, D + N, D[j] - 1e-9) - D);
  }
  cout << ans / 3 << endl;
  return 0;
}
