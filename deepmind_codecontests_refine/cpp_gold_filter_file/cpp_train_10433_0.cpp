#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e16;
long long X, Y, ax, ay, bx, by, xs, ys, t;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> X >> Y >> ax >> ay >> bx >> by >> xs >> ys >> t;
  vector<pair<long long, long long> > v;
  v.push_back(make_pair(X, Y));
  for (int i = (0); i < (60); ++i) {
    long long x = v.back().first;
    long long y = v.back().second;
    long long nx = x * ax + bx;
    long long ny = y * ay + by;
    if (nx > INF || ny > INF || nx < 0 || ny < 0) break;
    v.push_back(make_pair(nx, ny));
  }
  vector<long long> d((int)(v).size());
  for (int i = (1); i < ((int)(v).size()); ++i) {
    long long x = v[i - 1].first;
    long long y = v[i - 1].second;
    long long nx = v[i].first;
    long long ny = v[i].second;
    d[i] = nx - x + ny - y + d[i - 1];
  }
  long long ret = 0;
  for (int i = (0); i < ((int)(v).size()); ++i)
    for (int j = (0); j < ((int)(v).size()); ++j) {
      if (i > j) continue;
      for (int k = (0); k < ((int)(v).size()); ++k) {
        if (k < i || k > j) continue;
        long long second = abs(xs - v[k].first) + abs(ys - v[k].second);
        long long T = d[k] - d[i] + d[j] - d[i];
        long long TT = d[j] - d[k] + d[j] - d[i];
        if (second + T <= t || second + TT <= t) {
          ret = max(ret, (long long)j - i + 1);
        }
      }
    }
  cout << ret << '\n';
  return 0;
}
