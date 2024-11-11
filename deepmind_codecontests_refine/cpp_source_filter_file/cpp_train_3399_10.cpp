#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int c;
char used[3];
vector<int> g[3];
void dfs(int v) {
  used[v] = true;
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(6);
  int n;
  cin >> n;
  int x[3], y[3], r[3];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
  vector<pair<double, double> > d[3];
  vector<pair<double, double> > v;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int di = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      int dirp = (r[i] + r[j]) * (r[i] + r[j]);
      int dirm = (r[i] - r[j]) * (r[i] - r[j]);
      if (dirp > di && di > dirm) {
        double angle = atan2(y[j] - y[i], x[j] - x[i]);
        double lo = 0, hi = atan2(0, -1);
        for (int t = 0; t < 120; t++) {
          double mi = (lo + hi) / 2;
          double an = angle + mi;
          double x0 = cos(an) * r[i] + x[i];
          double y0 = sin(an) * r[i] + y[i];
          double di =
              sqrt((x0 - x[j]) * (x0 - x[j]) + (y0 - y[j]) * (y0 - y[j]));
          if (di < r[j])
            lo = mi;
          else
            hi = mi;
        }
        angle += lo;
        double x1 = cos(angle) * r[i] + x[i];
        double y1 = sin(angle) * r[i] + y[i];
        angle -= 2 * lo;
        double x2 = cos(angle) * r[i] + x[i];
        double y2 = sin(angle) * r[i] + y[i];
        v.push_back({x1, y1});
        v.push_back({x2, y2});
        d[i].push_back({x1, y1});
        d[i].push_back({x2, y2});
        d[j].push_back({x1, y1});
        d[j].push_back({x2, y2});
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
      c++;
    }
  }
  int _v = 0, e = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (abs(v[i].first - v[j].first) < eps &&
          abs(v[i].second - v[j].second) < eps)
        ok = false;
    }
    if (ok) {
      _v++;
      for (int j = 0; j < 3; j++) {
        ok = false;
        for (int k = 0; k < d[j].size(); k++) {
          if (abs(v[i].first - d[j][k].first) < eps &&
              abs(v[i].second - d[j][k].second) < eps)
            ok = true;
        }
        e += ok;
      }
    }
  }
  cout << e - _v + c + 1 << endl;
}
