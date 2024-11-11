#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const long long INF = 4e18 + 5;
struct pt {
  int x, y;
  void print() { printf("(%d, %d) ", x, y); }
} p[1010];
int n;
double len(pt a, pt b) {
  double x = b.x - a.x, y = b.y - a.y;
  return sqrt(x * x + y * y);
}
double dist(pt a, pt b, pt c) {
  double A = b.y - a.y, B = a.x - b.x, C = 1ll * b.x * a.y - b.y * a.x;
  return fabs(A * c.x + B * c.y + C) / len(a, b);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  double ans = 9e18L;
  for (int i = 0; i < n; ++i) ans = min(ans, len(p[i], p[(i + 1) % n]) / 2.0);
  for (int i = 0; i < n; ++i) {
    pt a = p[(i - 1 + n) % n];
    pt b = p[(i + 1) % n];
    ans = min(ans, dist(a, b, p[i]) / 2.0);
  }
  printf("%.7f\n", ans);
  return 0;
}
