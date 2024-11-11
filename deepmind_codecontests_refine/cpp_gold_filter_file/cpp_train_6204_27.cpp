#include <bits/stdc++.h>
using namespace std;
int nxi() {
  int a;
  cin >> a;
  return a;
}
vector<long long> a;
void inc(int i, long long v) {
  for (; i < a.size(); i |= i + 1) {
    a[i] = max(a[i], v);
  }
}
long long get(int r) {
  long long ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    ans = max(ans, a[r]);
  }
  return ans;
}
long long get(int l, int r) { return get(r) - get(l - 1); }
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
struct pp {
  int x, y, vx, vy;
};
int sign(int x) { return x < 0 ? -1 : 1; }
int main() {
  int n = nxi();
  int cx1 = nxi(), cy1 = nxi(), cx2 = nxi(), cy2 = nxi();
  vector<pp> mouses(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &mouses[i].x, &mouses[i].y, &mouses[i].vx, &mouses[i].vy);
  }
  vector<pair<double, double>> times;
  for (auto& mo : mouses) {
    int found = 0;
    double time1, time2;
    if (min(cx1, cx2) < mo.x && mo.x < max(cx1, cx2) && min(cy1, cy2) < mo.y &&
        mo.y < max(cy1, cy2)) {
      found++;
      time1 = 0;
      if (mo.vx == 0 && mo.vy == 0) {
        found++;
        time2 = 1000000000.0;
      }
    }
    if ((mo.y != cy1 && mo.y != cy2 || mo.vy != 0) && mo.vx != 0) {
      double t = double(cx1 - mo.x) / mo.vx;
      if (t + 1e-11 > 0) {
        double my = mo.y + mo.vy * t;
        if (min(cy1, cy2) - 1e-11 < my && my < max(cy1, cy2) + 1e-11) {
          if (found == 0) {
            found++;
            time1 = t;
          } else {
            if (found == 1 && fabs(time1 - t) > 1e-11) {
              found++;
              time2 = t;
            }
          }
        }
      }
    }
    if ((mo.y != cy1 && mo.y != cy2 || mo.vy != 0) && mo.vx != 0) {
      double t = double(cx2 - mo.x) / mo.vx;
      if (t + 1e-11 > 0) {
        double my = mo.y + mo.vy * t;
        if (min(cy1, cy2) - 1e-11 < my && my < max(cy1, cy2) + 1e-11) {
          if (found == 0) {
            found++;
            time1 = t;
          } else {
            if (found == 1 && fabs(time1 - t) > 1e-11) {
              found++;
              time2 = t;
            }
          }
        }
      }
    }
    if ((mo.x != cx1 && mo.x != cx2 || mo.vx != 0) && mo.vy != 0) {
      double t = double(cy1 - mo.y) / mo.vy;
      if (t + 1e-11 > 0) {
        double mx = mo.x + mo.vx * t;
        if (min(cx1, cx2) - 1e-11 < mx && mx < max(cx1, cx2) + 1e-11) {
          if (found == 0) {
            found++;
            time1 = t;
          } else {
            if (found == 1 && fabs(time1 - t) > 1e-11) {
              found++;
              time2 = t;
            }
          }
        }
      }
    }
    if ((mo.x != cx1 && mo.x != cx2 || mo.vx != 0) && mo.vy != 0) {
      double t = double(cy2 - mo.y) / mo.vy;
      if (t + 1e-11 > 0) {
        double mx = mo.x + mo.vx * t;
        if (min(cx1, cx2) - 1e-11 < mx && mx < max(cx1, cx2) + 1e-11) {
          if (found == 0) {
            found++;
            time1 = t;
          } else {
            if (found == 1 && fabs(time1 - t) > 1e-11) {
              found++;
              time2 = t;
            }
          }
        }
      }
    }
    if (found == 2) {
      if (time2 < time1) swap(time1, time2);
      times.push_back(make_pair(time1, time2));
    }
  }
  bool res = false;
  double ans;
  if (times.size() == n) {
    res = true;
    ans = times[0].first;
    for (int i = 1; i < times.size(); i++) {
      ans = max(ans, times[i].first);
    }
    for (int i = 0; i < times.size(); i++) {
      if (ans + 1e-11 > times[i].second) res = false;
    }
  }
  if (res) {
    cout.precision(9);
    cout << fixed << ans;
  } else {
    cout << -1;
  }
  return 0;
}
