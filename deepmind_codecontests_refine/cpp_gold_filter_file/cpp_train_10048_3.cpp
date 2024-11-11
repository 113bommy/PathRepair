#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} debug1;
const long long inf = 0x7fffffff;
const int ND = 112345;
pair<long long, long long> co[ND];
int n;
long long dp1_min[ND], dp1_max[ND];
long long dp2_min[ND], dp2_max[ND];
long long f(long long a, long long b) { return ((a - b) * (a - b)); }
long long sq(long long a) { return (a * a); }
bool valid(long long sum) {
  long long min1 = f(dp1_max[n - 1], dp1_min[n - 1]);
  long long min2 =
      (co[0].first - co[n - 1].first) * (co[0].first - co[n - 1].first);
  if (min1 <= sum or min2 <= sum) return true;
  for (int i = 0; i < n; ++i) {
    int st, en;
    long long val = co[i].first;
    if (val < 0) {
      st = i;
      en = upper_bound(co, co + n, make_pair(abs(val), -inf)) - co - 1;
      int res = -1;
      while (st <= en) {
        int mid = (st + en) / 2;
        long long temp = co[mid].first;
        long long dist = f(val, temp);
        if (dist <= sum) {
          res = mid;
          st = mid + 1;
        } else
          en = mid - 1;
      }
      if (res == -1) continue;
      if (res - i + 1 == n) return true;
      long long ymin = inf, ymax = -inf;
      if (res < n - 1) {
        ymin = min(ymin, dp2_min[res + 1]);
        ymax = max(ymax, dp2_max[res + 1]);
      }
      if (i > 0) {
        ymin = min(ymin, dp1_min[i - 1]);
        ymax = max(ymax, dp1_max[i - 1]);
      }
      long long temp = f(ymin, ymax);
      temp = max(temp, sq(val) + sq(max(abs(ymax), abs(ymin))));
      if (temp <= sum) return true;
    } else {
      en = i;
      st = upper_bound(co, co + n, make_pair(-val, -inf)) - co;
      int res = -1;
      while (st <= en) {
        int mid = (st + en) / 2;
        long long temp = co[mid].first;
        long long dist = f(val, temp);
        if (dist <= sum) {
          res = mid;
          en = mid - 1;
        } else
          st = mid + 1;
      }
      if (res == -1) continue;
      if (i - res + 1 == n) return true;
      long long ymin = inf, ymax = -inf;
      if (res > 0) {
        ymin = min(ymin, dp1_min[res - 1]);
        ymax = max(ymax, dp1_max[res - 1]);
      }
      if (i < n - 1) {
        ymin = min(ymin, dp2_min[i + 1]);
        ymax = max(ymax, dp2_max[i + 1]);
      }
      long long temp = f(ymin, ymax);
      temp = max(temp, sq(val) + sq(max(abs(ymax), abs(ymin))));
      if (temp <= sum) return true;
    }
  }
  return false;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> co[i].first >> co[i].second;
  }
  sort(co, co + n);
  dp1_min[0] = dp1_max[0] = co[0].second;
  dp2_min[n - 1] = dp2_max[n - 1] = co[n - 1].second;
  for (int i = 1; i < n; ++i) {
    dp1_min[i] = min(dp1_min[i - 1], co[i].second);
    dp1_max[i] = max(dp1_max[i - 1], co[i].second);
  }
  for (int i = n - 2; i >= 0; --i) {
    dp2_min[i] = min(dp2_min[i + 1], co[i].second);
    dp2_max[i] = max(dp2_max[i + 1], co[i].second);
  }
  long long st = 0LL, en = 100000000000000000LL;
  long long ans = -1;
  while (st <= en) {
    long long mid = (st + en) / 2LL;
    if (valid(mid)) {
      en = mid - 1;
      ans = mid;
    } else {
      st = mid + 1;
    }
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
