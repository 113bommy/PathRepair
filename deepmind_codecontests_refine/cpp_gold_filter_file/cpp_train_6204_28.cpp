#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1e3 + 5;
const long long kInf = (1LL << 60);
long long intersection(long long rx, long long ry, long long vx, long long vy,
                       long long y, long long x0, long long x1) {
  long long tvy = y - ry;
  if (tvy * vy < 0 || vy == 0) return kInf;
  long long minx = min(x0 * vy, x1 * vy);
  long long maxx = max(x0 * vy, x1 * vy);
  if ((vy > 0 &&
           !(x0 * vy <= rx * vy + tvy * vx && rx * vy + tvy * vx <= x1 * vy) ||
       (vy < 0 &&
        !(x1 * vy <= rx * vy + tvy * vx && rx * vy + tvy * vx <= x0 * vy))))
    return kInf;
  if (vx == 0 && (rx == x0 || rx == x1)) return kInf;
  return tvy;
}
long long compare(pair<long long, long long>& a,
                  pair<long long, long long>& b) {
  long long sgn = a.first * b.second - a.second * b.first;
  if (sgn < 0)
    sgn = -1;
  else if (sgn > 0)
    sgn = 1;
  else
    sgn = 0;
  if (b.second * a.second < 0) sgn = -sgn;
  return sgn;
}
void solve() {
  int n;
  scanf("%d", &n);
  vector<long long> x(2), y(2), rx(n + 1), ry(n + 1), vx(n + 1), vy(n + 1);
  for (int i = 0; i < 2; ++i) {
    scanf("%lld %lld", &x[i], &y[i]);
  }
  pair<pair<long long, long long>, pair<long long, long long>> total;
  bool okk = false;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld %lld %lld", &rx[i], &ry[i], &vx[i], &vy[i]);
    vector<pair<long long, long long>> t(4);
    t[0] = {intersection(rx[i], ry[i], vx[i], vy[i], y[0], x[0], x[1]), vy[i]};
    t[1] = {intersection(rx[i], ry[i], vx[i], vy[i], y[1], x[0], x[1]), vy[i]};
    t[2] = {intersection(ry[i], rx[i], vy[i], vx[i], x[0], y[0], y[1]), vx[i]};
    t[3] = {intersection(ry[i], rx[i], vy[i], vx[i], x[1], y[0], y[1]), vx[i]};
    pair<pair<long long, long long>, pair<long long, long long>> inter;
    bool ok = false;
    if (x[0] < rx[i] && rx[i] < x[1] && y[0] < ry[i] && ry[i] < y[1]) {
      ok = true;
      inter = {{0, 1}, {0, 1}};
      if (vx[i] == 0 && vy[i] == 0) inter = {{0, 1}, {kInf, 1}};
    }
    for (int j = 0; j < 4; ++j) {
      if (t[j].first != kInf) {
        if (!ok) {
          inter = make_pair(t[j], t[j]);
          ok = true;
        } else {
          if (compare(inter.first, t[j]) == 1) inter.first = t[j];
          if (compare(inter.second, t[j]) == -1) inter.second = t[j];
        }
      }
    }
    if (!ok) {
      cout << -1 << "\n";
      return;
    }
    if (!okk) {
      total = inter;
      okk = true;
    } else {
      if (compare(total.first, inter.first) == -1) total.first = inter.first;
      if (compare(total.second, inter.second) == 1) total.second = inter.second;
    }
  }
  if (compare(total.first, total.second) >= 0) {
    cout << -1 << "\n";
  } else {
    cout << fixed << setprecision(9)
         << 1.0 * total.first.first / total.first.second << "\n";
  }
}
int main() {
  int tests = 1;
  for (; tests; --tests) {
    solve();
  }
}
