#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int ma = max(m, max(n, k));
  int i, j, x, y, z;
  int r[ma + 2], rt[ma + 2], c[ma + 1], ct[ma + 1];
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  memset(rt, 0, sizeof(rt));
  memset(ct, 0, sizeof(ct));
  for (i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (x == 1) {
      rt[y] = i + 1;
      r[y] = z;
    } else if (x == 2) {
      ct[y] = i + 1;
      c[y] = z;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (rt[i] > ct[j])
        cout << r[i] << " ";
      else if (rt[i] < ct[j])
        cout << c[j] << " ";
      else
        cout << 0 << " ";
    }
    cout << endl;
  }
  return 0;
}
