#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
int n;
double x, y, u, v, xmax, xmin, ymax, ymin;
pair<double, double> where[N], speed[N];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> x >> y >> u >> v;
  xmax = max(x, u);
  ymax = max(y, v);
  xmin = min(x, u);
  ymin = min(y, v);
  for (int i = 1; i <= n; ++i)
    cin >> where[i].first >> where[i].second >> speed[i].first >>
        speed[i].second;
  double low = -1e18, high = 1e18;
  for (int inx = 1; inx <= n; ++inx) {
    double lowcur = 1e18, highcur = -1e18;
    if (where[inx].first >= xmax) {
      if (speed[inx].first >= 0) {
        cout << -1;
        return 0;
      } else
        lowcur = (where[inx].first - xmax) / abs(speed[inx].first),
        highcur = (where[inx].first - xmin) / abs(speed[inx].first);
    } else {
      if (where[inx].first <= xmin) {
        if (speed[inx].first <= 0) {
          cout << -1;
          return 0;
        } else
          lowcur = (xmin - where[inx].first) / speed[inx].first,
          highcur = (xmax - where[inx].first) / speed[inx].first;
      } else {
        lowcur = 0;
        if (speed[inx].first == 0)
          highcur = 1e18;
        else {
          if (speed[inx].first < 0)
            highcur = (where[inx].first - xmin) / abs(speed[inx].first);
          else
            highcur = (xmax - where[inx].first) / speed[inx].first;
        }
      }
    }
    if (where[inx].second >= ymax) {
      if (speed[inx].second >= 0) {
        cout << -1;
        return 0;
      } else
        lowcur =
            max(lowcur, (where[inx].second - ymax) / abs(speed[inx].second)),
        highcur =
            min(highcur, (where[inx].second - ymin) / abs(speed[inx].second));
    } else {
      if (where[inx].second <= ymin) {
        if (speed[inx].second <= 0) {
          cout << -1;
          return 0;
        } else
          lowcur = max(lowcur, (ymin - where[inx].second) / speed[inx].second),
          highcur =
              min(highcur, (ymax - where[inx].second) / speed[inx].second);
      } else {
        lowcur = max(lowcur, (double)0);
        if (speed[inx].second == 0)
          highcur = min(highcur, (double)1e18);
        else {
          if (speed[inx].second < 0)
            highcur = min(highcur,
                          (where[inx].second - ymin) / abs(speed[inx].second));
          else
            highcur =
                min(highcur, (ymax - where[inx].second) / speed[inx].second);
        }
      }
    }
    low = max(low, lowcur);
    high = min(high, highcur);
  }
  if (low > high)
    cout << -1;
  else
    cout << setprecision(20) << fixed << low;
  return 0;
}
