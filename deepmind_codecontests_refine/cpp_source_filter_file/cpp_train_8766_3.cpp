#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long sx, sy, mulx, muly, addx, addy;
  cin >> sx >> sy >> mulx >> muly >> addx >> addy;
  long long x, y, t;
  cin >> x >> y >> t;
  vector<long long> dif;
  vector<array<long long, 2>> v;
  v.push_back({sx, sy});
  for (int i = 1;; ++i) {
    long long nxtx = sx * mulx + addx;
    long long nxty = sy * muly + addy;
    if (nxty > 1e18 || nxty > 1e18 || nxtx < 0 || nxty < 0) break;
    dif.push_back(abs(nxtx - sx) + abs(nxty - sy));
    sx = nxtx, sy = nxty;
    v.push_back({sx, sy});
  }
  int n = v.size();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long cnt = 0;
    long long need = abs(v[i][0] - x) + abs(v[i][1] - y);
    if (need > t)
      continue;
    else
      cnt++;
    long long L = t - need, R = t - need;
    long long cntl = cnt, cntr = cnt;
    for (int j = i; j < dif.size(); ++j) {
      if (R - dif[j] >= 0)
        R -= dif[j], cntr++;
      else
        break;
    }
    for (int j = i - 1; j >= 0; --j) {
      if (L - dif[j] >= 0)
        L -= dif[j], cntl++;
      else
        break;
    }
    ans = max({ans, cntl, cntr});
  }
  cout << ans;
  return 0;
}
