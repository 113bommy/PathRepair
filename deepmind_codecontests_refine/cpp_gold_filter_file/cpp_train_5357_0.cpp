#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  int p[n], q[n];
  for (int c = 0; c < n; c++) cin >> p[c] >> q[c];
  int b[m], d[m];
  for (int c = 0; c < m; c++) cin >> b[c] >> d[c];
  int ans = 0;
  for (int c = l; c <= r; c++) {
    bool posibil = 0;
    for (int c2 = 0; c2 < m; c2++) {
      int l2 = b[c2] + c;
      int r2 = d[c2] + c;
      for (int k = 0; k < n; k++) {
        if ((l2 <= q[k] && r2 >= p[k]) || (r2 <= p[k] && l2 >= q[k]))
          posibil = 1;
      }
    }
    if (posibil) ans++;
  }
  cout << ans;
  return 0;
}
