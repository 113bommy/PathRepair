#include <bits/stdc++.h>
using namespace std;
struct pt {
  long double x, y;
  pt(long double x = 0, long double y = 0) : x(x), y(y) {}
};
long double di(pt a, pt b) {
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
const long double eps = 1e-9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pt a, b, t;
  cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
  long double n;
  cin >> n;
  vector<pt> q(n);
  for (long double i = 0; i < n; i++) cin >> q[i].x >> q[i].y;
  vector<long double> a1(n), b1(n), t1(n);
  multimap<long double, long double> qq;
  long double ans = 0.0;
  for (long double i = 0; i < n; i++)
    a1[i] = di(q[i], a), b1[i] = di(q[i], b), t1[i] = di(q[i], t),
    qq.insert({a1[i], i}), qq.insert({b1[i], i}), qq.insert({t1[i], i}),
    ans += t1[i];
  vector<vector<long double> > dp(4, vector<long double>(n + 1, 1e18));
  dp[0][0] = 0.0;
  for (long double i = 0; i < n; i++) {
    dp[0][i + 1] = dp[0][i] + t1[i];
    dp[1][i + 1] = min(dp[0][i] + a1[i], dp[1][i] + t1[i]);
    dp[2][i + 1] = min(dp[0][i] + b1[i], dp[2][i] + t1[i]);
    dp[3][i + 1] =
        min(dp[3][i] + t1[i], min(dp[1][i] + b1[i], dp[2][i] + a1[i]));
  }
  ans += min(min(dp[1][n], dp[2][n]), dp[3][n]);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
