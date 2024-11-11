#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1e9;
const int N = 200000;
int n;
int x0, sdkfaslhagaklsldk;
long double T;
int x[N], y[N], r[N];
long double thold[N];
long double get_d(long double x, long double y) { return sqrt(x * x + y * y); }
long double get_w(int id) {
  long double D1 = get_d(x[id], y[id]);
  long double res = asin(r[id] / D1);
  thold[id] = D1 * cos(res);
  return res;
}
pair<long double, long double> solve_tan(int id) {
  long double cen_ang = atan2(y[id], x[id]);
  long double shi = get_w(id);
  return make_pair(cen_ang - shi, cen_ang + shi);
}
long double v;
vector<pair<long double, int> > events;
long double get_dist(long double x1, long double aasdfasdfasdf, long double x2,
                     long double y2) {
  return sqrt((x2 - x1) * (x2 - x1) +
              (y2 - aasdfasdfasdf) * (y2 - aasdfasdfasdf));
}
long double G(long double x1, long double aasdfasdfasdf, long double x2,
              long double y2) {
  return ((x2 - x1) * (x2 - x1) + (y2 - aasdfasdfasdf) * (y2 - aasdfasdfasdf));
}
bool check(long double ang, int id) {
  long double tx = cos(ang) * v;
  long double ty = sin(ang) * v;
  long double Da = get_dist(x[id], y[id], tx, ty);
  long double Db = get_dist(0, 0, x[id], y[id]);
  long double Dc = get_dist(0, 0, tx, ty);
  if (Da <= r[id]) return true;
  if (Dc > thold[id]) return true;
  return false;
}
void ADD(long double l, long double r) {
  assert(l >= -1e-9 && r <= 2 * 3.141592653589793 + 1e-9);
  events.push_back(make_pair(l - 1e-9, 1));
  events.push_back(make_pair(r + 1e-9, -1));
}
void add_seg(long double l, long double r) {
  if (l < 0) {
    ADD(2 * 3.141592653589793 + l, 2 * 3.141592653589793);
    ADD(0, r);
  } else {
    ADD(l, r);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> x0 >> sdkfaslhagaklsldk >> v >> T;
  cin >> n;
  v *= T;
  if (v > 4e9) v = 4e9;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
    x[i] -= x0;
    y[i] -= sdkfaslhagaklsldk;
    if (1ll * x[i] * x[i] + 1ll * y[i] * y[i] <= 1ll * r[i] * r[i]) {
      cout << 1 << endl;
      return 0;
    }
  }
  if (v < 1e-9) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    pair<long double, long double> P = solve_tan(i);
    if (P.second > 2 * 3.141592653589793)
      P.first -= 2 * 3.141592653589793, P.second -= 2 * 3.141592653589793;
    if (P.second < 0)
      P.second += 2 * 3.141592653589793, P.first += 2 * 3.141592653589793;
    long double l, r;
    l = P.first;
    r = P.first + P.second;
    r /= 2;
    for (int iter = 0; iter <= 60; iter++) {
      long double mid = l + r;
      mid /= 2;
      if (check(mid, i))
        r = mid;
      else
        l = mid;
    }
    long double center = P.first + P.second;
    center /= 2;
    r = 2 * center - l;
    if (r < 0) {
      l += 2 * 3.141592653589793;
      r += 2 * 3.141592653589793;
    }
    add_seg(l, r);
  }
  sort(events.begin(), events.end());
  int cnt = 0;
  long double ans = 0;
  for (int i = 0; i < events.size(); i++) {
    assert(cnt >= 0);
    if (cnt > 0) {
      ans += events[i].first - events[i - 1].first;
    }
    cnt += events[i].second;
  }
  cout.precision(12);
  cout << fixed << ans * 1.0 / (2 * 3.141592653589793) << endl;
  cin.get();
  cin.get();
  return 0;
}
