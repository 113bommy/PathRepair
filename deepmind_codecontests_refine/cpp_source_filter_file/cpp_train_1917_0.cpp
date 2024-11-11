#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double inf = 1e9;
struct ball {
  long double x, v, m;
};
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
bool lt(long double a, long double b) { return b - a > eps; }
int main() {
  int n;
  long double t;
  cin >> n >> t;
  vector<ball> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].v >> v[i].m;
  }
  long double curr = 0;
  while (true) {
    long double minn = inf;
    vector<pair<int, int> > c;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (eq(v[i].v, v[j].v)) {
          continue;
        }
        long double dt = (v[j].x - v[i].x) / (v[i].v - v[j].v);
        if (lt(dt, 0) || eq(dt, 0)) {
          continue;
        }
        if (lt(dt, minn)) {
          minn = dt;
          c = {make_pair(i, j)};
        } else if (eq(t, minn)) {
          c.push_back(make_pair(i, j));
        }
      }
    }
    if (lt(t, curr + minn)) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      v[i].x += v[i].v * minn;
    }
    curr += minn;
    for (pair<int, int>& p : c) {
      int i = p.first, j = p.second;
      long double v1 = ((v[i].m - v[j].m) * v[i].v + 2 * v[j].m * v[j].v) /
                       (v[i].m + v[j].m);
      long double v2 = ((v[j].m - v[i].m) * v[j].v + 2 * v[i].m * v[i].v) /
                       (v[i].m + v[j].m);
      v[i].v = v1;
      v[j].v = v2;
    }
  }
  for (int i = 0; i < n; ++i) {
    v[i].x += v[i].v * (t - curr);
  }
  cout << fixed;
  cout.precision(12);
  for (int i = 0; i < n; ++i) {
    cout << v[i].x << "\n";
  }
}
