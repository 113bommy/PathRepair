#include <bits/stdc++.h>
using namespace std;
const long long inf = 8000000000000000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long y, x, lest, lift, speed;
  cin >> y >> x >> lest >> lift >> speed;
  vector<long long> lst(lest), lft(lift);
  for (long long c = 0; c < lest; c++) cin >> lst[c];
  for (long long c = 0; c < lift; c++) cin >> lft[c];
  long long ask;
  cin >> ask;
  for (long long c = 0; c < ask; c++) {
    long long x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    long long pos_lest_l = -1,
              pos_lest_r =
                  lower_bound(lst.begin(), lst.end(), x1) - lst.begin();
    if (pos_lest_r != 0) {
      if (pos_lest_r == lst.size()) {
        pos_lest_l = pos_lest_r - 1;
        pos_lest_r = -1;
      } else {
        pos_lest_l = pos_lest_r - 1;
      }
    }
    if (pos_lest_r == lst.size()) pos_lest_r = -1;
    long long pos_lift_l = -1,
              pos_lift_r =
                  lower_bound(lft.begin(), lft.end(), x1) - lft.begin();
    if (pos_lift_r != 0) {
      if (pos_lift_r == lft.size()) {
        pos_lift_l = pos_lift_r - 1;
        pos_lift_r = -1;
      } else {
        pos_lift_l = pos_lift_r - 1;
      }
    }
    if (y1 == y2) {
      cout << abs(x1 - x2) << endl;
      continue;
    }
    if (pos_lift_r == lft.size()) pos_lift_r = -1;
    long long res1 = inf, res2 = inf, res3 = inf, res4 = inf;
    if (pos_lest_l >= 0)
      res1 =
          abs(x1 - lst[pos_lest_l]) + abs(lst[pos_lest_l] - x2) + abs(y1 - y2);
    if (pos_lest_r >= 0)
      res2 =
          abs(x1 - lst[pos_lest_r]) + abs(lst[pos_lest_r] - x2) + abs(y1 - y2);
    if (pos_lift_l >= 0)
      res3 = abs(x1 - lft[pos_lift_l]) + abs(lft[pos_lift_l] - x2) +
             ((abs(y1 - y2) - 1) / speed + 1);
    if (pos_lift_r >= 0)
      res4 = abs(x1 - lft[pos_lift_r]) + abs(lft[pos_lift_r] - x2) +
             ((abs(y1 - y2) - 1) / speed + 1);
    cout << min(res1, min(res2, min(res3, res4))) << endl;
  }
  return 0;
}
