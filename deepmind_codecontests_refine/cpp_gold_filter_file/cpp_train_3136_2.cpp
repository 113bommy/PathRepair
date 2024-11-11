#include <bits/stdc++.h>
using namespace std;
const int N = 3030;
const double pi = acos(-1), eps = 1e-9;
struct Point {
  int x, y, deg, id;
};
int T, n, m, deg[N], bel[N];
void Solve(vector<Point> p) {
  int mx = 0;
  for (int i = 0; i < p.size(); i++)
    if (p[i].deg > p[mx].deg) mx = i;
  if (p[mx].deg == 1) {
    int ind = 0;
    for (int i = 0; i < p.size(); i++)
      if (!p[i].deg) ind = i;
    for (int i = 0; i < p.size(); i++)
      if (ind != i) cout << p[i].id + 1 << " " << p[ind].id + 1 << endl;
    return;
  }
  vector<pair<double, int> > all;
  int now = 0;
  for (int i = 0; i < p.size(); i++) {
    if (i == mx) continue;
    double from = atan2(p[i].y - p[mx].y, p[i].x - p[mx].x);
    double to = from + (from <= 0 ? pi : -pi);
    all.push_back({from, i});
    all.push_back({to, -i - 1});
    if (from > eps) now -= p[i].deg - 1;
    bel[i] = from > eps;
  }
  sort(all.begin(), all.end());
  for (auto v : all) {
    if (now > 0 && now < p[mx].deg) break;
    if (v.second < 0) {
      bel[-v.second - 1] = 0;
      now += p[-v.second - 1].deg - 1;
    } else {
      bel[v.second] = 1;
      now -= p[v.second].deg - 1;
    }
  }
  vector<Point> left, right;
  for (int i = 0; i < p.size(); i++)
    if (i != mx) (bel[i] ? left : right).push_back(p[i]);
  left.push_back({p[mx].x, p[mx].y, now, p[mx].id});
  right.push_back({p[mx].x, p[mx].y, p[mx].deg - now, p[mx].id});
  Solve(left);
  Solve(right);
}
int main(void) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &deg[i]);
    vector<Point> p(n + m);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
      p[i].id = i;
    }
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &p[i + n].x, &p[i + n].y);
      p[i + n].deg = deg[i];
      p[i + n].id = i;
    }
    puts("YES");
    Solve(p);
  }
  return 0;
}
