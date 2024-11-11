#include <bits/stdc++.h>
using namespace std;
int main() {
  long double px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  long double vLen = sqrt(vx * vx + vy * vy);
  long double vix = vy, viy = -vx;
  long double viLen = sqrt(vix * vix + viy * viy);
  vector<pair<long double, long double>> ans(7);
  ans[0] = make_pair(px + vx * b / vLen, py + vy * b / vLen);
  ans[1] = make_pair(px - vix * a / 2 / viLen, py - viy * a / 2 / viLen);
  ans[2] = make_pair(px - vix * c / 2 / viLen, py - viy * c / 2 / viLen);
  ans[5] = make_pair(px + vix * c / 2 / viLen, py + viy * c / 2 / viLen);
  ans[6] = make_pair(px + vix * a / 2 / viLen, py + viy * a / 2 / viLen);
  ans[3] =
      make_pair(ans[2].first - vx * d / vLen, ans[2].second - vy * d / vLen);
  ans[4] =
      make_pair(ans[5].first - vx * d / vLen, ans[5].second - vy * d / vLen);
  for (int i = 0; i < 7; i++)
    cout << fixed << setprecision(15) << ans[i].first << " " << ans[i].second
         << endl;
  return 0;
}
