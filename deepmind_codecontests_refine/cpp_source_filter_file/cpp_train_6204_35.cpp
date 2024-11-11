#include <bits/stdc++.h>
using namespace std;
const int MaxBs = 30;
int dcmp(long double x1, long double x2) {
  if (fabsl(x1 - x2) <= 1e-8)
    return 0;
  else if (x1 > x2)
    return 1;
  else
    return -1;
}
void BS1(int start, int s1, int s2, int v, long double &ans1,
         long double &ans2) {
  long double st = 0, en = 1e6, mid;
  int l = MaxBs;
  while (st <= en && l--) {
    mid = (st + en) / 2;
    long double cur = start + v * mid;
    if (dcmp(cur, s1) > 0)
      ans1 = mid, en = mid;
    else
      st = mid;
  }
  st = 0, en = 1e6, l = MaxBs;
  while (st <= en && l--) {
    mid = (st + en) / 2;
    long double cur = start + v * mid;
    if (dcmp(cur, s1) > 0) {
      if (dcmp(cur, s2) < 0)
        ans2 = mid, st = mid;
      else
        en = mid;
    } else
      st = mid;
  }
}
void BS2(int start, int s1, int s2, int v, long double &ans1,
         long double &ans2) {
  long double st = 0, en = 1e6;
  int l = MaxBs;
  while (st <= en && l--) {
    long double mid = (st + en) / 2;
    long double cur = start + v * mid;
    if (dcmp(cur, s2) < 0)
      ans1 = mid, en = mid;
    else
      st = mid;
  }
  st = 0, en = 1e6, l = MaxBs;
  while (st <= en && l--) {
    long double mid = (st + en) / 2;
    long double cur = start + v * mid;
    if (dcmp(cur, s2) < 0) {
      if (dcmp(cur, s1) > 0)
        ans2 = mid, st = mid;
      else
        en = mid;
    } else
      st = mid;
  }
}
void BS3(int start, int s1, int s2, int v, long double &ans1,
         long double &ans2) {
  ans1 = 0;
  long double st = 0, en = 1e6;
  int l = MaxBs;
  while (st <= en && l--) {
    long double mid = (st + en) / 2;
    long double cur = start + mid * v;
    if (dcmp(cur, s1) > 0 && dcmp(cur, s2) < 0)
      ans2 = mid, st = mid;
    else
      en = mid;
  }
}
int main() {
  int n, x1, x2, y1, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  vector<pair<long double, long double>> vec;
  bool bad = 0;
  if (x1 == x2 || y1 == y2) bad = 1;
  for (int i = 0; i < n; i++) {
    int rx, ry, vx, vy;
    cin >> rx >> ry >> vx >> vy;
    if (bad) continue;
    if ((rx <= x1 && vx <= 0) || (rx >= x2 && vx >= 0) ||
        (ry <= y1 && vy <= 0) || (ry >= y2 && vy >= 0)) {
      bad = 1;
      continue;
    }
    long double ans1x = 0, ans2x = 1e6, ans1y = 0, ans2y = 1e6;
    if (rx <= x1)
      BS1(rx, x1, x2, vx, ans1x, ans2x);
    else if (rx >= x2)
      BS2(rx, x1, x2, vx, ans1x, ans2x);
    else
      BS3(rx, x1, x2, vx, ans1x, ans2x);
    if (ry <= y1)
      BS1(ry, y1, y2, vy, ans1y, ans2y);
    else if (ry > y2)
      BS2(ry, y1, y2, vy, ans1y, ans2y);
    else
      BS3(ry, y1, y2, vy, ans1y, ans2y);
    long double ans1 = max(ans1x, ans1y), ans2 = min(ans2x, ans2y);
    vec.push_back({ans1, ans2});
  }
  if (bad) {
    cout << -1;
    return 0;
  }
  sort(vec.begin(), vec.end());
  long double ans1 = 0, ans2 = 1e6;
  for (auto &x : vec) ans1 = max(ans1, x.first), ans2 = min(ans2, x.second);
  if (dcmp(ans1, ans2) > 0)
    cout << -1;
  else
    cout << fixed << setprecision(8) << ans1;
  return 0;
}
