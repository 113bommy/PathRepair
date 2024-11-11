#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-8;
const int dx4[4] = {1, 0, 0, -1};
const int dy4[4] = {0, -1, 1, 0};
const int inf = 0x3f3f3f3f;
const int N = 1E3 + 7;
int n;
double dp[N];
int dblcmp(double d) { return d < -eps ? -1 : d > eps; }
struct point {
  int x, y, t;
  double p;
  void input() {
    scanf("%d %d %d", &x, &y, &t);
    scanf("%lf", &p);
  }
  double dis(point p) {
    return sqrt((x - p.x) * (x - p.x) * (y - p.y) * (y - p.y));
  }
  bool operator<(point p) const { return t < p.t; }
} p[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) p[i].input();
  sort(p + 1, p + n + 1);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = p[i].p;
    for (int j = 1; j < i; j++) {
      if (dblcmp(p[i].dis(p[j]) - p[i].t + p[j].t) <= 0)
        dp[i] = max(dp[i], dp[j] + p[i].p);
    }
    ans = max(dp[i], ans);
  }
  printf("%.10f\n", ans);
  return 0;
}
