#include <bits/stdc++.h>
using namespace std;
const double inf = 1e100;
const int iinf = 1 << 30;
int a[1000][1000];
vector<int> v[1000], v2[1000], vv;
int dfs(int q) {
  vv.push_back(q);
  if (v[q].size() > 0)
    return min(dfs(v[q][0]), a[q][v[q][0]]);
  else
    return iinf;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    int t = c / (2 * m);
    int r = (c) % (2 * m - 2) + 1;
    int res = 0;
    if (r <= m) {
      if (x >= r) {
        res = x - r;
        if (x <= y)
          res += y - x;
        else
          res += m - x + m - y;
      } else {
        res = m - x + m - r;
        if (x >= y)
          res += x - y;
        else
          res += x + y - 2;
      }
    } else {
      r = 2 * m - r;
      if (x > r) {
        res = x + r - 2;
        if (x <= y)
          res += y - x;
        else
          res += m - x + m - y;
      } else {
        res = r - x;
        if (x >= y)
          res += x - y;
        else
          res += x + y - 2;
      }
    }
    if (x == y)
      cout << c << endl;
    else
      cout << c + res << endl;
  }
  return 0;
}
