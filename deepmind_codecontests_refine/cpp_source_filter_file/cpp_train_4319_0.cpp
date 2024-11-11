#include <bits/stdc++.h>
using namespace std;
bool stable(int x, int y, map<pair<int, int>, int> &f) {
  if (f.find({x, y}) == f.end()) {
    return 0;
  }
  int i, j;
  for (i = -1; i < 2; ++i) {
    if (f.find({x + i, y + 1}) == f.end()) {
      continue;
    }
    for (j = -1; j < 2; ++j) {
      if (j + i == 0) {
        continue;
      }
      if (f.find({x + i + j, y}) != f.end()) {
        break;
      }
    }
    if (j == 2) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int m, i, j, k, x, y;
  cin >> m;
  long long r = 0, mod = 1e9 + 7;
  vector<pair<int, int> > v(m);
  map<pair<int, int>, int> f;
  for (i = 0; i < m; ++i) {
    cin >> j >> k;
    v[i] = {j, k};
    f[{j, k}] = i;
  }
  set<int> gm;
  for (i = 0; i < m; ++i) {
    if (stable(v[i].first, v[i].second, f)) {
      gm.insert(i);
    }
  }
  for (i = 0; i < m; ++i) {
    r *= m;
    r %= mod;
    if (i % 2 == 0) {
      k = *gm.rbegin();
    } else {
      k = *gm.begin();
    }
    gm.erase(k);
    r += k;
    x = v[k].first;
    y = v[k].second;
    f.erase({x, y});
    for (j = -2; j < 3; ++j) {
      if (stable(x + j, y - 1, f)) {
        gm.insert(f[{x + j, y - 1}]);
      }
      if (f.find({x + j, y}) != f.end() && !stable(x + j, y, f)) {
        gm.erase(f[{x + j, y}]);
      }
    }
  }
  cout << r % mod << endl;
  return 0;
}
