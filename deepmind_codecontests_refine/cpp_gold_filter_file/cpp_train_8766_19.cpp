#include <bits/stdc++.h>
using namespace std;
long long dis(pair<long long, long long> a, long long cx, long long cy) {
  return (abs(a.first - cx) + abs(a.second - cy));
}
signed main() {
  ios_base::sync_with_stdio;
  cin.tie(0);
  cout.tie(0);
  ;
  long long x0, y0, ax, ay, bx, by, xs, ys, t;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  vector<pair<long long, long long> > space;
  space.push_back(make_pair(x0, y0));
  long long x = x0, y = y0;
  while (x < 20000000000000000 && y < 20000000000000000) {
    x = ax * x + bx;
    y = ay * y + by;
    space.push_back(make_pair(x, y));
  }
  long long len = space.size(), res = 0;
  for (long long i = 0; i < len; i++) {
    long long temp = t, ans1 = 0, ans2 = 0, cx = xs, cy = ys;
    for (long long j = i; j >= 0; j--) {
      if (dis(space[j], cx, cy) <= temp) {
        temp -= dis(space[j], cx, cy);
        ans1++;
        cx = space[j].first;
        cy = space[j].second;
      } else
        break;
    }
    temp = t, cx = xs, cy = ys;
    for (long long j = i; j < len; j++) {
      if (dis(space[j], cx, cy) <= temp) {
        temp -= dis(space[j], cx, cy);
        ans2++;
        cx = space[j].first;
        cy = space[j].second;
      } else
        break;
    }
    res = max(res, max(ans1, ans2));
  }
  cout << res;
}
