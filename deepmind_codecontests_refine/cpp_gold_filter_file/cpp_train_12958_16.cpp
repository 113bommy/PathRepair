#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    x.push_back(x[i]);
    y.push_back(y[i] + 1);
    x.push_back(x[i]);
    y.push_back(y[i] - 1);
    x.push_back(x[i] - 1);
    y.push_back(y[i]);
    x.push_back(x[i] + 1);
    y.push_back(y[i]);
  }
  n *= 5;
  int lx = inf, rx = -inf, uy = -inf, dy = inf;
  for (int i = 0; i < n; ++i) {
    lx = min(lx, x[i]);
    rx = max(rx, x[i]);
    uy = max(uy, y[i]);
    dy = min(dy, y[i]);
  }
  int ru = lx + dy;
  int ld = rx + uy;
  int lu = rx - dy;
  int rd = lx - uy;
  for (int i = 0; i < n; ++i) {
    ru = max(ru, x[i] + y[i]);
    ld = min(ld, x[i] + y[i]);
    lu = min(lu, x[i] - y[i]);
    rd = max(rd, x[i] - y[i]);
  }
  ru = rx + uy - ru;
  ld = ld - (lx + dy);
  lu = lu - (lx - uy);
  rd = (rx - dy) - rd;
  int ans = (rx - lx) * 2 + (uy - dy) * 2 - ru - ld - lu - rd;
  cout << ans << endl;
  return 0;
}
