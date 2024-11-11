#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
int x[3], y[3];
vector<int> xs, ys;
int main() {
  for (int i(0); i < (int)(3); i++) cin >> x[i] >> y[i];
  int ans = 1000 * 1000;
  int b[3] = {0, 1, 2};
  int xx = max(max(x[0], x[1]), x[2]) - min(min(x[0], x[1]), x[2]) + 1;
  int yy = max(max(y[0], y[1]), y[2]) - min(min(y[0], y[1]), y[2]) + 1;
  do {
    int t1 = xx + abs(y[b[1]] - y[b[0]]) + abs(y[b[2]] - y[b[0]]);
    if (t1 < ans) {
      ans = t1;
      xs.clear();
      ys.clear();
      for (int nx(min(min(x[0], x[1]), x[2]));
           nx <= (int)(max(max(x[0], x[1]), x[2])); nx++)
        xs.push_back(nx), ys.push_back(y[b[0]]);
      for (int ny = y[b[1]]; ny != y[b[0]];
           ny = (ny < y[b[0]] ? ny + 1 : ny - 1))
        xs.push_back(x[b[1]]), ys.push_back(ny);
      for (int ny = y[b[2]]; ny != y[b[0]];
           ny = (ny < y[b[0]] ? ny + 1 : ny - 1))
        xs.push_back(x[b[2]]), ys.push_back(ny);
    }
    int t2 = yy + abs(x[b[1]] - x[b[0]]) + abs(x[b[2]] - x[b[0]]);
    if (t2 < ans) {
      ans = t2;
      xs.clear();
      ys.clear();
      for (int ny(min(min(y[0], y[1]), y[2]));
           ny <= (int)(max(max(y[0], y[1]), y[2])); ny++)
        xs.push_back(x[b[0]]), ys.push_back(ny);
      for (int nx = x[b[1]]; nx != x[b[0]];
           nx = (nx < x[b[0]] ? nx + 1 : nx - 1))
        ys.push_back(y[b[1]]), xs.push_back(nx);
      for (int nx = x[b[2]]; nx != x[b[0]];
           nx = (nx < x[b[0]] ? nx + 1 : nx - 1))
        ys.push_back(y[b[2]]), xs.push_back(nx);
    }
  } while (next_permutation(b, b + 3));
  cout << ans << endl;
  for (int i(0); i < (int)(xs.size()); i++)
    cout << xs[i] << " " << ys[i] << endl;
  return 0;
}
