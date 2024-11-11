#include <bits/stdc++.h>
using namespace std;
int n;
double dp[1002], ans;
struct idk {
  int x, y, t;
  double p;
  bool operator<(const idk &a) const { return t < a.t; }
} v[1002];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i].x >> v[i].y >> v[i].t >> v[i].p;
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = v[i].p;
    for (int j = 1; j < i; j++)
      if ((v[i].x - v[j].x) * (v[i].x - v[j].x) +
              (v[i].y - v[j].y) * (v[i].y - v[j].y) <=
          (v[i].t - v[j].t) * (v[i].t - v[j].t))
        dp[i] = max(dp[i], dp[j] + v[i].p);
    ans = max(ans, dp[i]);
  }
  cout << fixed << setprecision(10) << ans;
  return 0;
}
