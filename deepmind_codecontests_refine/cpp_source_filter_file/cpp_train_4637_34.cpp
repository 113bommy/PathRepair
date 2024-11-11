#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e4 + 10;
const long double EPS = 1e-8;
int n;
long double x[N], y[N], z[N], vs, vp, px, py, pz;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  cin >> n;
  for (int i = 0; i < n + 1; ++i) cin >> x[i] >> y[i] >> z[i];
  cin >> vp >> vs;
  cin >> px >> py >> pz;
  vector<long double> time;
  auto cal_dist = [&](int i, int j) {
    return pow(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2),
               0.5);
  };
  time.push_back(0.0);
  for (int i = 0; i < n; ++i) time.push_back(cal_dist(i, i + 1) / vs);
  for (int i = 1; i < (int)time.size(); ++i) time[i] += time[i - 1];
  long double l = EPS, r = 2 * time.back();
  long double ans = -1, ax, ay, az;
  for (int iter = 0; iter < 1000; ++iter) {
    long double mid = (l + r) * 0.5;
    int idx = upper_bound(time.begin(), time.end(), mid) - time.begin();
    if (idx == (int)time.size()) {
      r = mid - EPS;
      continue;
    }
    long double ratio = (mid - time[idx - 1]) / (time[idx] - time[idx - 1]);
    long double nx = x[idx - 1] + ratio * (x[idx] - x[idx - 1]);
    long double ny = y[idx - 1] + ratio * (y[idx] - y[idx - 1]);
    long double nz = z[idx - 1] + ratio * (z[idx] - z[idx - 1]);
    double dist = pow(pow(px - nx, 2) + pow(py - ny, 2) + pow(pz - nz, 2), 0.5);
    if (dist < vp * mid or abs(dist - vp * mid) <= 1e-6) {
      ans = mid;
      ax = nx, ay = ny, az = nz;
      r = mid - EPS;
    } else {
      l = mid + EPS;
    }
  }
  if (ans != -1) {
    cout << "YES" << '\n';
    cout << ans << '\n';
    cout << ax << ' ' << ay << ' ' << az << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
