#include <bits/stdc++.h>
using namespace std;
int x[55][55], a, b, n, m;
int solve() {
  int res = 1000000000;
  for (int _n((n - a + 1) - 1), i(0); i <= _n; i++)
    for (int _n((n - b + 1) - 1), j(0); j <= _n; j++) {
      int cnt = 0;
      for (int _n((a)-1), k(0); k <= _n; k++)
        for (int _n((b)-1), t(0); t <= _n; t++) cnt += x[i + k][j + t];
      res = min(res, cnt);
    }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int _n((n)-1), i(0); i <= _n; i++)
    for (int _n((m)-1), j(0); j <= _n; j++) scanf("%d", &x[i][j]);
  scanf("%d%d", &a, &b);
  int r1 = solve();
  swap(a, b);
  int r2 = solve();
  cout << min(r1, r2) << endl;
  return 0;
}
