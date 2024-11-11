#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long base = 37;
long long large = 1000000000000000000LL;
int main() {
  int n;
  cin >> n;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  bool flag = true;
  int cnt = 0;
  vector<pair<double, int> > ti;
  for (int i = 0; i < n; i++) {
    if (!flag) {
    }
    int x, y;
    int vx, vy;
    cin >> x >> y >> vx >> vy;
    long double t1 = -1e50;
    long double t2 = 1e50;
    long double t3 = t1, t4 = t2;
    if (vx == 0) {
      if (x <= x1 || x >= x2) {
        flag = false;
        continue;
      }
    } else {
      t1 = min(1.0 * (x1 - x) / vx, 1.0 * (x2 - x) / vx);
      t2 = max(1.0 * (x1 - x) / vx, 1.0 * (x2 - x) / vx);
    }
    if (vy == 0) {
      if (y <= y1 || y >= y2) {
        flag = false;
        continue;
      }
    } else {
      t3 = min(1.0 * (y1 - y) / vy, 1.0 * (y2 - y) / vy);
      t4 = max(1.0 * (y1 - y) / vy, 1.0 * (y2 - y) / vy);
    }
    if (vx == 0 && vy == 0) {
      ti.push_back(pair<double, int>(0.0, 1));
      ti.push_back(pair<double, int>(t2, 0));
      continue;
    }
    t1 = max(t1, t3);
    t2 = min(t2, t4);
    if (t2 <= t1) {
      flag = false;
      continue;
    }
    if (t2 < 0) {
      flag = false;
      continue;
    }
    t1 = max(t1, (long double)0.0);
    if (t1 == t2) {
      flag = false;
      continue;
    }
    ti.push_back(pair<double, int>(t1, 1));
    ti.push_back(pair<double, int>(t2, 0));
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  sort(ti.begin(), ti.end());
  bool can = false;
  long double tist = -1.0;
  for (int i = 0; i < (int)ti.size(); i++) {
    if (ti[i].second == 1) {
      cnt++;
      if (cnt == n) {
        can = true;
        tist = ti[i].first;
      }
    } else {
      cnt--;
    }
  }
  if (can) {
    cout << setprecision(10) << fixed;
    cout << tist << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
