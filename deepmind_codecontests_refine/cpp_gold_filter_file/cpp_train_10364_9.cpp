#include <bits/stdc++.h>
using namespace std;
int n, l, vb, vp, k;
double mid;
bool check(double t) {
  double bus_share, gap, grps, bus_time, back_time;
  bus_share = (1.0 * (l - vp * t)) / (vb - vp);
  if (bus_share <= 0) return true;
  grps = (n + k - 1) / k;
  gap = bus_share * (vb - vp);
  back_time = gap / (vb + vp);
  bus_time = bus_share * grps + (grps - 1.0) * (back_time);
  if (bus_time > t)
    return false;
  else
    return true;
}
void bins(double l, double r, int cnt) {
  mid = (l + r) / 2.0;
  if (++cnt == 50) return;
  if (check(mid))
    bins(l, mid, cnt);
  else
    bins(mid, r, cnt);
}
int main(void) {
  cin >> n >> l >> vp >> vb >> k;
  bins(0.0, 1e9, 0);
  cout << setprecision(12) << mid << endl;
  return 0;
}
