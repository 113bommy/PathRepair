#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
long long n, m, r, k, lbx, lby, ubx, uby;
long long cal(long long x, long long y) {
  long long mx = min(r, n - r + 1);
  long long my = min(r, m - r + 1);
  long long rx = min(min(x, mx), min(n - x + 1, mx));
  long long ry = min(min(y, my), min(m - y + 1, my));
  return rx * ry;
}
long long solve(long long lbx, long long lby, long long ubx, long long uby) {
  long long res = 0;
  for (long long i = lbx; i <= ubx; i++) {
    for (long long j = lby; j <= uby; j++) {
      vec.push_back(cal(i, j));
    }
  }
  sort(vec.begin(), vec.end());
  for (long long i = vec.size() - k; i < vec.size(); i++) {
    res += vec[i];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m >> r >> k;
  lbx = lby = 1;
  ubx = n;
  uby = m;
  while (true) {
    long long h = ubx - lbx + 1;
    long long w = uby - lby + 1;
    if (h * w <= 100000 || min(h, w) <= 2000 && max(h, w) <= 5000) {
      break;
    }
    if ((h - 2) * w < k || h * (w - 2) < k || (h - 2) * (w - 2) < k) {
      break;
    }
    if (h > 2000) {
      lbx++;
      ubx--;
    }
    if (w > 2000) {
      lby++;
      uby--;
    }
  }
  cout << setprecision(10) << fixed;
  cout << 1.0 * solve(lbx, lby, ubx, uby) / (n - r + 1) / (m - r + 1) << endl;
  return 0;
}
