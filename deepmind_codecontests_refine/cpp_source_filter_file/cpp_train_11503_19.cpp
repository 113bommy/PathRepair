#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ma = -1, tem;
  bool b = 0;
  cin >> n >> m;
  int d[m], h[m];
  for (int i = 0; i < m; i++) cin >> d[i] >> h[i];
  ma = max(h[0], h[m - 1]);
  ma = max(ma, (h[0] + (d[0] - 1)));
  ma = max(ma, (h[m - 1] + (n - d[m - 1])));
  if (m == 1)
    cout << ma;
  else {
    for (int i = 1; i < m; i++) {
      if (h[i] - h[i - 1] > abs(d[i] - d[i - 1])) {
        b = 1;
        break;
      }
      tem = d[i] - d[i - 1];
      tem -= abs(h[i - 1] - h[i]);
      ma = max(ma, (max(h[i], h[i - 1]) + (tem / 2)));
    }
    if (b)
      cout << "IMPOSSIBLE";
    else
      cout << ma;
  }
  return 0;
}
