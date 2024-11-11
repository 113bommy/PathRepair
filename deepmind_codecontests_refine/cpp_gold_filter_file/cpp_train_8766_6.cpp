#include <bits/stdc++.h>
using namespace std;
using namespace std;
void io() {}
long long x_ini, y_ini, ax, ay, bx, by;
long long xs, ys, t;
vector<pair<long long, long long> > v;
int32_t main() {
  io();
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> x_ini >> y_ini >> ax >> ay >> bx >> by;
  cin >> xs >> ys >> t;
  long long xi = x_ini, yi = y_ini;
  v.push_back({xi, yi});
  for (long long i = 1; i < 200; i++) {
    xi = ax * xi + bx;
    yi = ay * yi + by;
    if (xi <= 0 || yi <= 0 || xi >= 1e17 || yi >= 1e17) break;
    v.push_back({xi, yi});
  }
  long long ans = 0;
  for (long long i = 0; i < v.size(); i++) {
    long long temp = 0;
    long long xj = xs;
    long long yj = ys;
    long long total = 0;
    for (long long j = i; j >= 0; j--) {
      long long diff = abs(xj - v[j].first) + abs(yj - v[j].second);
      xj = v[j].first;
      yj = v[j].second;
      if (total + diff <= t && total + diff >= 0) {
        total += diff;
        temp++;
      } else {
        break;
      }
    }
    if (xj == x_ini && yj == y_ini && temp > 0) {
      for (long long j = i + 1; j <= v.size(); j++) {
        long long diff = abs(xj - v[j].first) + abs(yj - v[j].second);
        xj = v[j].first;
        yj = v[j].second;
        if (total + diff <= t && total + diff >= 0) {
          total += diff;
          temp++;
        } else {
          break;
        }
      }
    }
    ans = max(ans, temp);
  }
  cout << ans << '\n';
}
