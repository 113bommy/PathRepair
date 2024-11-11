#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
double l[maxn], r[maxn];
double lv[maxn], rv[maxn];
double s;
double eps = 1e-9;
double sol(double sheng, double dis, double v) {
  double tt1 = sheng / v, tt2 = dis / (s - v);
  if (tt1 < tt2) return tt1;
  return tt2 + (sheng - tt2 * v) / (s + v);
}
bool pan(double sheng1, double dis1, double v1, double sheng2, double dis2,
         double v2) {
  double tt1 = sheng1 / v1, tt2 = dis1 / (s - v1);
  double t1, t2;
  if (tt1 < tt2)
    t1 = tt1;
  else
    t1 = (sheng1 - tt2 * v1) / (s + v1) + tt2;
  tt1 = sheng2 / v2, tt2 = dis2 / (s - v2);
  if (tt1 < tt2)
    t2 = tt1;
  else
    t2 = (sheng2 - tt2 * v2) / (s + v2) + tt2;
  return t1 <= t2 + eps;
}
int main() {
  int n;
  double ans = 1e7;
  ios::sync_with_stdio(0);
  cin >> n >> s;
  int pos, fang;
  double v;
  double lmin = 1e7, rmin = 1e7;
  for (int i = 0; i < n; i++) {
    cin >> pos >> v >> fang;
    if (fang == 1) {
      lv[pos] = max(lv[pos], v);
      lmin = min(lmin, pos / v);
    } else {
      rv[pos] = max(rv[pos], v);
      rmin = min(rmin, (1e6 - pos) / v);
    }
  }
  int no = -1;
  for (int i = 0; i <= 1e6; i++) {
    if (no == -1) {
      if (lv[i] < 0.1) {
        l[i] = lmin;
      } else {
        no = i;
        l[i] = min(lmin, i / (s + lv[i]));
      }
    } else {
      if (lv[i] > 0.1) {
        if (pan(no, i - no, lv[no], i, 0, lv[i])) {
          no = i;
        }
      }
      l[i] = min(lmin, sol(no, i - no, lv[no]));
    }
  }
  no = -1;
  for (int i = 1e6; i > -1; i--) {
    if (no == -1) {
      if (rv[i] < 0.1) {
        r[i] = rmin;
      } else {
        no = i;
        r[i] = min(rmin, (1e6 - i) / (s + rv[i]));
      }
    } else {
      if (rv[i] > 0.1) {
        if (pan(1e6 - no, no - i, rv[no], 1e6 - i, 0, rv[i])) {
          no = i;
        }
      }
      r[i] = min(rmin, sol(1e6 - no, no - i, rv[no]));
    }
  }
  for (int i = 0; i <= 1e6; i++) {
    ans = min(ans, max(l[i], r[i]));
  }
  cout << fixed << setprecision(9) << ans << endl;
}
