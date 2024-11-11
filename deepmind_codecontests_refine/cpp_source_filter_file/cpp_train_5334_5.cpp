#include <bits/stdc++.h>
using namespace std;
bool solve() {
  int c[4], x[3], y[3];
  for (int i = 0; i < 4; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }
  if (x[2] - x[1] == 0 && abs(c[0]) + abs(c[1]) > 0) {
    return false;
  }
  if (y[2] - y[1] == 0 && abs(c[2]) + abs(c[3]) > 0) {
    return false;
  }
  int nx = x[0] + c[1] - c[0];
  int ny = y[0] + c[3] - c[2];
  return (nx >= x[1] && nx <= x[2] && ny >= y[1] && nx <= y[2]);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool ok = solve();
    cout << (ok ? "Yes" : "No") << "\n";
  }
  fclose(stdin);
  return 0;
}
