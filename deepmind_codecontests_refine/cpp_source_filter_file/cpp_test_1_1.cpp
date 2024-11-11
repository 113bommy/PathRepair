#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long double PI = acos(-1.0L);
const int N = 1e6 + 5;
long double a[N], d[N];
int n, k;
bool cmp(const pair<long double, bool> &e1, const pair<long double, bool> &e2) {
  long double a1, a2;
  int t1, t2;
  tie(a1, t1) = e1, tie(a2, t2) = e2;
  if (abs(a1 - a2) > EPS) return a1 < a2;
  return t1 < t2;
}
bool ok(long double r) {
  long double delta;
  long double L, R;
  long double dif;
  vector<pair<long double, bool> > events;
  for (int i = 0; i < n; ++i) {
    if (d[i] - r > EPS) continue;
    delta = acos(d[i] / r);
    L = a[i] - delta;
    R = a[i] + delta;
    dif = -PI - L;
    if (dif > EPS) {
      events.emplace_back(-PI, 0);
      events.emplace_back(R, 1);
      L = PI - dif;
      R = PI;
    }
    dif = R - PI;
    if (dif > EPS) {
      events.emplace_back(L, 0);
      events.emplace_back(PI, 1);
      R = -PI + dif;
      L = -PI;
    }
    events.emplace_back(L, 0);
    events.emplace_back(R, 1);
  }
  sort(events.begin(), events.end(), cmp);
  long double angle;
  bool type;
  int cnt = 0;
  for (auto &e : events) {
    tie(angle, type) = e;
    if (type == 0) {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt >= k) return true;
  }
  return false;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    a[i] = atan2(y, x);
    d[i] = sqrt(x * x + y * y) / 2;
  }
  long double L = 0, R = 3e5, M;
  for (int i = 0; i < 50; ++i) {
    M = (L + R) / 2;
    if (ok(M)) {
      R = M;
    } else {
      L = M;
    }
  }
  cout << setprecision(10) << fixed << L;
  return 0;
}
