#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-6;
long double D(pair<long double, long double> a,
              pair<long double, long double> b = {0, 0}) {
  return sqrtl((a.first - b.first) * (a.first - b.first) +
               (a.second - b.second) * (a.second - b.second));
}
long double eq(pair<long double, long double> a,
               pair<long double, long double> b) {
  return (abs(a.first - b.first) + abs(a.second - b.second) < eps);
}
pair<long double, long double> sub(pair<long double, long double> a,
                                   pair<long double, long double> b) {
  return {a.first - b.first, a.second - b.second};
}
long double cross(pair<long double, long double> a,
                  pair<long double, long double> b) {
  long double den = D(sub(a, b));
  long double num = a.first * b.second - a.second * b.first;
  return abs(num / den);
}
long double D1, D2;
long double sq(long double a) { return a * a; }
vector<long double> ds(pair<long double, long double> a,
                       pair<long double, long double> b) {
  pair<long double, long double> from = a, to = b;
  if (eq(from, {0, 0}) || eq(to, {0, 0}) || eq(from, to)) {
    return {D(from), D(to)};
  }
  long double perp = cross(from, to);
  long double dis = sqrt(sq(D(a) - sq(perp)) + sqrt(sq(D(b) - sq(perp))));
  if (dis - eps > D(a, b)) {
    return {D(a), D(b)};
  } else {
    return {D(a), perp, D(b)};
  }
}
void modify(pair<long double, long double> las,
            pair<long double, long double> final, bool &f, int &ans) {
  auto vv = ds(las, final);
  for (int i = 0; i < vv.size(); i++) {
    if (f) {
      if (vv[i] < D1 + eps) {
        ans++;
        f = 0;
      }
    } else {
      if (vv[i] > D2 + eps) {
        f = 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N >> D1 >> D2;
  long double ox, oy;
  pair<long double, long double> las = {0, 0};
  int ans = 0;
  bool fdone = 1;
  for (int i = 0; i < N; i++) {
    pair<long double, long double> cur;
    cin >> ox >> oy >> cur.first >> cur.second;
    cur.first -= ox;
    cur.second -= oy;
    if (i == 0) {
      if (D(cur) < D1 + eps) {
        ans++;
        fdone = 0;
      }
    } else {
      modify(las, cur, fdone, ans);
    }
    las = cur;
  }
  cout << ans;
  return 0;
}
