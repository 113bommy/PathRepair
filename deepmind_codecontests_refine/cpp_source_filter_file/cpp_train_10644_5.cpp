#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  long double phase;
  point(int x = 0, int y = 0)
      : x(x), y(y), phase((x == 0 && y == 0 ? 0.0l : atan2l(x, y))) {}
  bool operator<(const point& rhs) const { return phase < rhs.phase; }
  long double dist(point rhs = point(0, 0)) {
    return hypotl(x - rhs.x, y - rhs.y);
  }
};
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<vector<long double> > dists;
  {
    vector<point> bases;
    while (n--) {
      int x, y;
      scanf("%d%d", &x, &y);
      bases.emplace_back(x, y);
    }
    sort(bases.begin(), bases.end());
    vector<vector<point> > arms;
    for (auto& i : bases) {
      if (arms.empty()) {
        arms.push_back({i});
        dists.push_back({i.dist()});
        continue;
      }
      point b = arms.back().back();
      if (abs(abs(b.dist() - i.dist()) - b.dist(i)) <= 1e-8l) {
        arms.back().push_back(i);
        dists.back().push_back(i.dist());
      } else {
        arms.push_back({i});
        dists.push_back({i.dist()});
      }
    }
    bases.clear();
    arms.clear();
    for (auto& i : dists) sort(i.begin(), i.end());
  }
  vector<long double> diffs;
  for (auto& i : dists) {
    vector<long double> psd;
    psd.push_back(0.0);
    for (auto& j : i) psd.push_back(psd.back() + j);
    int far = 0, close = 0;
    for (int j = 0; j < i.size(); j++) {
      if (far <= k / 2) {
        diffs.push_back(i[i.size() - 1 - far] * (k - 1 - far * 2) -
                        psd[close] * 2);
        far++;
      } else {
        diffs.push_back(i[close] * (k - 1 - far * 2) - psd[close] * 2);
        close++;
      }
    }
  }
  sort(diffs.begin(), diffs.end());
  long double ans = 0.0l;
  for (int i = k; i--;) {
    ans += diffs.back();
    diffs.pop_back();
  }
  printf("%.8Lf\n", ans);
}
