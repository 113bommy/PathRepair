#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> c(n + 1, false), d(n + 1, false);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 1) c[y] = true;
    if (y == n) d[x] = true;
    for (int i = 0; i <= n; i++) {
      if (c[i] && d[i]) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
    cout << "IMPOSSIBLE" << endl;
  }