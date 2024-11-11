#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long a, b, c;
double ans1, ans2, ans3, ans4;
void solve(long long a, long long b, long long c, double& x1, double& x2) {
  long long D = 1LL * b * b - 1LL * 4 * a * c;
  if (D < 0) {
    x1 = 1e9;
    x2 = 1e9;
    return;
  }
  x1 = -1.0 * b / 2 / a + 1.0 * sqrt(D) / 2 / a;
  x2 = -1.0 * b / 2 / a - 1.0 * sqrt(D) / 2 / a;
  if (x1 < 0) x1 = 1e9;
  if (x2 < 0) x2 = 1e9;
  return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long t, v;
  cin >> v >> t;
  v *= v;
  long long vx, vy, wx, wy;
  cin >> vx >> vy >> wx >> wy;
  vx *= -1, vy *= -1, wx *= -1, wy *= -1;
  x = x2 - x1;
  y = y2 - y1;
  a = vx * vx + vy * vy - v;
  b = 2 * (vx * x + vy * y);
  c = x * x + y * y;
  solve(a, b, c, ans1, ans2);
  if (ans1 > t) {
    ans1 = 1e10;
  }
  if (ans2 > t) {
    ans2 = 1e10;
  }
  x = x2 - x1 + vx * t - wx * t;
  y = y2 - y1 + vy * t - wy * t;
  a = wx * wx + wy * wy - v;
  b = 2 * (wx * x + wy * y);
  c = x * x + y * y;
  solve(a, b, c, ans3, ans4);
  if (ans3 < t) {
    ans3 = 1e9;
  }
  if (ans4 < t) {
    ans4 = 1e9;
  }
  double ans = min(min(ans1, ans2), min(ans3, ans4));
  printf("%.15f\n", ans);
}
