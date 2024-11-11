#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long maxn = (long long)3e5 + 5;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
const double eps = 1e-10;
long long T = 1;
double dis(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
void solve() {
  double ans, ans1, ans2, ans3, ans4;
  ans = ans1 = ans2 = ans3 = ans4 = inf;
  double a, b, c;
  pair<double, double> p1, p2;
  cin >> a >> b >> c >> p1.first >> p1.second >> p2.first >> p2.second;
  ans = fabs(p1.first - p2.first) + fabs(p1.second - p2.second);
  if (fabs(a) < eps) {
    pair<double, double> q1 = {p1.first, -c / b};
    pair<double, double> q2 = {p2.first, -c / b};
    ans1 = dis(p1, q1) + dis(q1, q2) + dis(q2, p2);
  } else if (fabs(b) < eps) {
    pair<double, double> q1 = {-c / a, p1.second};
    pair<double, double> q2 = {-c / a, p2.second};
    ans2 = fabs(p1.first - q1.first) + dis(q1, q2) + fabs(p2.first - q2.first);
  } else {
    pair<double, double> q1, q2, q3, q4;
    q1 = make_pair(p1.first, -(a * p1.first + c) / b);
    q3 = make_pair(-(b * p1.second + c) / a, p1.second);
    q2 = make_pair(p2.first, -(a * p2.first + c) / b);
    q4 = make_pair(-(b * p2.second + c) / a, p2.second);
    ans1 = dis(p1, q1) + dis(q1, q2) + dis(q2, p2);
    ans2 = dis(p1, q1) + dis(q1, q4) + dis(q4, p2);
    ans3 = dis(p1, q3) + dis(q3, q2) + dis(q2, p2);
    ans4 = dis(p1, q3) + dis(q3, q4) + dis(q4, p2);
  }
  cout << fixed << setprecision(10)
       << min(ans, min(ans1, min(ans2, min(ans3, ans4))));
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  while (T--) solve();
  return 0;
}
