#include <bits/stdc++.h>
using namespace std;
long double rx[100005], ry[100005], vx[100005], vy[100005];
long double st[100005], en[100005];
int main() {
  ios_base::sync_with_stdio(0);
  ;
  long long precision = numeric_limits<long double>::digits10;
  ;
  int n;
  cin >> n;
  long double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  for (int i = 1; i <= n; i++) cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
  bool pos = true;
  for (int i = 1; i <= n; i++) {
    long double t1, t2, t3, t4;
    if (vx[i] > 0) {
      t1 = (x1 - rx[i]) / vx[i];
      t2 = (x2 - rx[i]) / vx[i];
    } else if (vx[i] < 0) {
      t2 = (x1 - rx[i]) / vx[i];
      t1 = (x2 - rx[i]) / vx[i];
    } else {
      if (rx[i] > x1 and rx[i] < x2) {
        t1 = 0, t2 = LDBL_MAX;
      } else {
        pos = false;
        break;
      }
    }
    if (vy[i] > 0) {
      t3 = (y1 - ry[i]) / vy[i];
      t4 = (y2 - ry[i]) / vy[i];
    } else if (vy[i] < 0) {
      t4 = (y1 - ry[i]) / vy[i];
      t3 = (y2 - ry[i]) / vy[i];
    } else {
      if (ry[i] > y1 and ry[i] < y2) {
        t3 = 0, t4 = LDBL_MAX;
      } else {
        pos = false;
        break;
      }
    }
    if (t1 < t2 and t3 < t4) {
      t1 = max(t1, t3);
      t2 = min(t2, t4);
      if (t1 <= t2) {
        st[i] = t1;
        en[i] = t2;
      } else {
        pos = false;
        break;
      }
    } else {
      pos = false;
      break;
    }
  }
  if (!pos)
    cout << -1 << endl;
  else {
    long double sta = LDBL_MIN, end = LDBL_MAX;
    for (int i = 1; i <= n; i++) sta = max(sta, st[i]);
    for (int i = 1; i <= n; i++) end = min(end, en[i]);
    if (end >= 0 and sta < end) {
      cout << setprecision(precision);
      cout << max(sta, (long double)0) << endl;
    } else
      cout << "-1" << endl;
  }
}
