#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
struct line {
  double x, y, vx, vy;
  void read() {
    double t1, t2;
    cin >> t1 >> x >> y >> t2 >> vx >> vy;
    vx = (vx - x) / (t2 - t1);
    vy = (vy - y) / (t2 - t1);
    x -= vx * t1;
    y -= vy * t1;
  }
} L[1005];
struct vec {
  double x, y;
} b[1005];
double cross(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }
double a[1005];
int tot;
bool cmp(const vec a, const vec b) {
  if (fabs(cross(a, b)) < eps) {
    if (fabs(a.x - b.x) < eps) return a.y < b.y;
    return a.x < b.x;
  }
  return cross(a, b) < 0;
}
int main() {
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  int ans = 0;
  double px, py, pvx, pvy, t;
  for (int i = 1; i <= N; i++) L[i].read();
  for (int i = 1; i <= N; i++) {
    tot = 0;
    for (int j = 1; j <= N; j++)
      if (i != j) {
        px = L[j].x - L[i].x;
        py = L[j].y - L[i].y;
        pvx = L[j].vx - L[i].vx;
        pvy = L[j].vy - L[i].vy;
        t = 0;
        if (!((fabs(pvx) < eps)))
          t = px / pvx;
        else if (!(fabs(pvy) < eps))
          t = py / pvy;
        if (fabs(px - t * pvx) < eps && fabs(py - t * pvy) < eps) {
          a[++tot] = t;
          b[tot].x = pvx, b[tot].y = pvy;
        }
      }
    sort(a + 1, a + tot + 1);
    int cnt = 0;
    for (int j = 1; j <= tot; j++) {
      if (fabs(a[j] - a[j - 1]) < eps)
        cnt++;
      else
        cnt = 1;
      ans = max(ans, cnt);
    }
    sort(b + 1, b + tot + 1, cmp);
    cnt = 0;
    for (int j = 1; j <= tot; j++) {
      if (fabs(cross(b[j], b[j - 1])) < eps) {
        if (fabs(b[j].x - b[j - 1].x) > eps || fabs(b[j].y - b[j - 1].y) > eps)
          cnt++;
      } else
        cnt = 1;
      ans = max(ans, cnt);
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
