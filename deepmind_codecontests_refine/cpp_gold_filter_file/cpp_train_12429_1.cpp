#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-7;
const double pi = acos(-1.0);
const int maxx = 100010;
const int mod = int(1e9 + 7);
struct P {
  long long x, y, t;
  double p;
  bool friend operator<(P a, P b) { return (a.t < b.t); }
} p[1100];
double dp[1100];
long long cal(P a, P b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
  long long n;
  scanf("%lld", &n);
  for (int i = 0; i < n; ++i) {
    P &com = p[i];
    scanf("%lld", &com.x);
    scanf("%lld", &com.y);
    scanf("%lld", &com.t);
    scanf("%lf", &com.p);
  }
  sort(p, p + n);
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    dp[i] = p[i].p;
    ans = max(ans, dp[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (cal(p[j], p[i]) <= (p[i].t - p[j].t) * (p[i].t - p[j].t)) {
        dp[i] = max(dp[i], p[i].p + dp[j]);
      }
    }
    ans = max(ans, dp[i]);
  }
  printf("%.6f\n", ans);
  return 0;
}
