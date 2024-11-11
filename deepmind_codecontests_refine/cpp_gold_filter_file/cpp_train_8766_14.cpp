#include <bits/stdc++.h>
using namespace std;
const long long INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
int main() {
  long long ox, oy, sx, sy, ax, ay, bx, by, t;
  std::vector<pair<long long, long long> > genrate;
  cin >> ox >> oy >> ax >> ay >> bx >> by;
  cin >> sx >> sy >> t;
  long long x = ox, y = oy;
  while (x <= 3e116 && y <= 3e16) {
    genrate.push_back({x, y});
    x = ax * x + bx;
    y = ay * y + by;
  }
  long long mxcnt = 0;
  for (int i = 0; i < genrate.size(); i++) {
    long long time = t;
    long long dis = abs(genrate[i].first - sx) + abs(genrate[i].second - sy);
    std::vector<pair<long long, long long> > v = genrate;
    time -= dis;
    v[i] = {-1, -1};
    int x = v.size();
    long long mn = INF, indx, nsx = genrate[i].first, nsy = genrate[i].second;
    long long cnt = 0;
    if (dis <= t) {
      cnt = 1;
      while (x--) {
        mn = INF;
        for (int j = 0; j < v.size(); j++) {
          if (v[j].first != -1 && v[j].second != -1) {
            dis = abs(v[j].first - nsx) + abs(v[j].second - nsy);
            if (dis < mn) {
              mn = dis;
              indx = j;
            }
          }
        }
        if (mn <= time) {
          time -= mn;
          cnt++;
          nsx = v[indx].first, nsy = v[indx].second;
          v[indx] = {-1, -1};
        } else
          break;
      }
    }
    mxcnt = max(cnt, mxcnt);
  }
  cout << mxcnt << endl;
  return 0;
}
