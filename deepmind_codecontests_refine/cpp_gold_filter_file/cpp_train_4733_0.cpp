#include <bits/stdc++.h>
using namespace std;
int n, x, y;
set<pair<int, int> > xs, ys;
int solve(set<pair<int, int> > &xs, set<pair<int, int> > &ys) {
  set<pair<int, int> >::iterator at = xs.begin(), bt = xs.end(),
                                 ct = ys.begin(), dt = ys.end(), it;
  bt--, dt--;
  set<pair<int, int> > nx, ny;
  int cnt = 0;
  while (true) {
    if (cnt % 4 == 0) {
      it = at;
      it++;
      if (it == xs.end()) return 1;
      if (at->first < it->first - 1) {
        for (at = xs.begin(); at != it;) {
          nx.insert(*at);
          ny.insert(pair<int, int>(at->second, at->first));
          ys.erase(pair<int, int>(at->second, at->first));
          xs.erase(at++);
        }
        return solve(xs, ys) + solve(nx, ny);
      }
      at++;
    }
    if (cnt % 4 == 1) {
      it = bt;
      it--;
      if (bt->first - 1 > it->first) {
        for (bt = xs.end(), bt--; bt != it;) {
          nx.insert(*bt);
          ny.insert(pair<int, int>(bt->second, bt->first));
          ys.erase(pair<int, int>(bt->second, bt->first));
          xs.erase(bt--);
        }
        return solve(xs, ys) + solve(nx, ny);
      }
      bt--;
    }
    if (cnt % 4 == 2) {
      it = ct;
      it++;
      if (ct->first < it->first - 1) {
        for (ct = ys.begin(); ct != it;) {
          ny.insert(*ct);
          nx.insert(pair<int, int>(ct->second, ct->first));
          xs.erase(pair<int, int>(ct->second, ct->first));
          ys.erase(ct++);
        }
        return solve(xs, ys) + solve(nx, ny);
      }
      ct++;
    }
    if (cnt % 4 == 3) {
      it = dt;
      it--;
      if (dt->first - 1 > it->first) {
        for (dt = ys.end(), dt--; dt != it;) {
          ny.insert(*dt);
          nx.insert(pair<int, int>(dt->second, dt->first));
          xs.erase(pair<int, int>(dt->second, dt->first));
          ys.erase(dt--);
        }
        return solve(xs, ys) + solve(nx, ny);
      }
      dt--;
    }
    cnt++;
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    xs.insert(pair<int, int>(x, y));
    ys.insert(pair<int, int>(y, x));
  }
  cout << solve(xs, ys) << endl;
  return 0;
}
