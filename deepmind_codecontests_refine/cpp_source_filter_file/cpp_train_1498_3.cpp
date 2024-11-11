#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const long long inf = 1LL << 60;
const long long one = 1000000;
inline int compare(const double &a, const double &b) {
  if (fabs(a - b) < eps) return 0;
  return a < b ? -1 : 1;
}
struct problem {
  int scoreSmall, scoreLarge, timeSmall, timeLarge;
  double probFail;
  bool operator<(const problem &p) const {
    double aTime = timeSmall + p.timeSmall;
    double bTime = timeSmall + p.timeSmall;
    aTime = (aTime + timeLarge) * (1.0 - probFail) * p.probFail +
            (aTime + timeLarge + p.timeLarge) * (1.0 - p.probFail);
    bTime = (bTime + p.timeLarge) * (1.0 - p.probFail) * probFail +
            (bTime + timeLarge + p.timeLarge) * (1.0 - probFail);
    return compare(aTime, bTime) < 0;
  }
} LIST[1000];
pair<long long, double> dp[1001][1561];
void best(pair<long long, double> &l, const pair<long long, double> &r) {
  if (l.first < r.first ||
      (l.first == r.first && compare(l.second, r.second) > 0))
    l = r;
}
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &LIST[i].scoreSmall, &LIST[i].scoreLarge,
          &LIST[i].timeSmall, &LIST[i].timeLarge);
    scanf("%lf", &LIST[i].probFail);
  }
  sort(LIST, LIST + n);
  reverse(LIST, LIST + n);
  for (int i = n; i >= 0; --i) {
    for (int rem = 0; rem <= t; ++rem) {
      auto &res = dp[i][rem];
      if (i == n) {
        res = rem ? make_pair(-inf, inf) : make_pair(0LL, 0LL);
        continue;
      }
      res = make_pair(-inf, inf);
      auto item = dp[i + 1][rem];
      best(res, item);
      if (rem >= LIST[i].timeSmall) {
        item = dp[i + 1][rem - LIST[i].timeSmall];
        item.first += LIST[i].scoreSmall * one;
        item.second += LIST[i].timeSmall;
        best(res, item);
      }
      if (rem >= LIST[i].timeSmall + LIST[i].timeLarge) {
        item = dp[i + 1][rem - LIST[i].timeSmall - LIST[i].timeLarge];
        item.first += LIST[i].scoreSmall * one +
                      LIST[i].scoreLarge *
                          (long long)(one - one * LIST[i].probFail + eps);
        item.second = (item.second + LIST[i].timeSmall) * LIST[i].probFail +
                      rem * (1.0 - LIST[i].probFail);
        best(res, item);
      }
    }
  }
  pair<long long, double> ans(0, 0);
  for (int i = 0; i <= t; ++i) best(ans, dp[0][i]);
  printf("%.17lf %.17lf\n", ans.first * 1.0 / one, ans.second);
  return 0;
}
