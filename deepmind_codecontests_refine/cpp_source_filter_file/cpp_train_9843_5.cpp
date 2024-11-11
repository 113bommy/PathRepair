#include <bits/stdc++.h>
using namespace std;
const int maxn = 600;
string f[maxn];
int n;
int st[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<pair<int, int>> v, g;
  for (;;) {
    cin >> n;
    if (n == 0) {
      break;
    }
    v.clear();
    for (int i = 0; i < n; ++i) {
      cin >> f[i];
    }
    for (int j = 2; j <= n - 2; ++j) {
      for (int i = n - 2; i >= 2; --i) {
        bool b1 = 1, b2 = 0;
        for (int k = 0; k < 4; ++k) {
          if (f[i - st[k][0]][j - st[k][1]] == '0') {
            b1 = 0;
            break;
          }
          if (f[i - st[k][0]][j - st[k][1]] == '1') {
            b2 = 1;
          }
        }
        if (b1 && b2) {
          v.push_back({i, j});
        }
      }
    }
    int x0 = v[0].first, y0 = v[0].second;
    sort(next(v.begin()), v.end(),
         [x0, y0](const pair<int, int> &p1, const pair<int, int> &p2) {
           long double a1 = atan2(p1.first - x0, p1.second - y0),
                       a2 = atan2(p2.first - x0, p2.second - y0);
           return a1 < a2 - 1e-7 || (abs(a1 - a2) < 1e-7 &&
                                     hypot(p1.first - x0, p1.second - y0) >
                                         hypot(p2.first - x0, p2.second - y0));
         });
    g.clear();
    g.push_back(v.front());
    for (int i = 1; i <= (int)v.size(); ++i) {
      while (g.size() >= 2 &&
             1ll * (g.back().first - g[g.size() - 2].first) *
                         (v[i % v.size()].second - g.back().second) -
                     1ll * (v[i % v.size()].first - g.back().first) *
                         (g.back().second - g[g.size() - 2].second) >=
                 0) {
        g.pop_back();
      }
      if (i != (int)v.size()) {
        g.push_back(v[i]);
      }
    }
    cout << g.size() << '\n';
    for (auto p : g) {
      cout << p.second << ' ' << n - p.first << '\n';
    }
  }
  return 0;
}
