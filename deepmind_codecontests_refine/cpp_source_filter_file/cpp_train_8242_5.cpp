#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<set<int>> row(n), col(m);
  for (int i = 0; i < n; ++i) {
    row[i].insert(-1);
    row[i].insert(m);
  }
  for (int i = 0; i < m; ++i) {
    col[i].insert(-1);
    col[i].insert(n);
  }
  for (int i = 0; i < k; ++i) {
    row[x[i]].insert(y[i]);
    col[y[i]].insert(x[i]);
  }
  int nx = 0, ny = -1;
  long long walk = 0;
  int cnt = 0;
  int u = -1, d = n, l = -1, r = m;
  while (1) {
    if (cnt % 4 == 0) {
      int wx = nx;
      int wy = min(r, *row[nx].upper_bound(ny));
      if (wy - ny - 1 == 0) break;
      walk += wy - ny - 1;
      ny = wy - 1;
      u++;
      r = wy;
    } else if (cnt % 4 == 1) {
      int wx = min(d, *col[ny].upper_bound(nx));
      int wy = ny;
      if (wx - nx - 1 == 0) break;
      walk += wx - nx - 1;
      nx = wx - 1;
      r++;
      d = wx;
    } else if (cnt % 4 == 2) {
      int wx = nx;
      int wy = max(l, *(--row[nx].upper_bound(ny)));
      if (ny - wy - 1 == 0) break;
      walk += ny - wy - 1;
      ny = wy + 1;
      d--;
      l = wy;
    } else {
      int wx = max(u, *(--col[ny].upper_bound(nx)));
      int wy = ny;
      if (nx - wx - 1 == 0) break;
      walk += nx - wx - 1;
      nx = wx + 1;
      l--;
      u = wx;
    }
    cnt++;
  }
  if (n * m == k + walk)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
  return 0;
}
