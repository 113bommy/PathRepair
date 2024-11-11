#include <bits/stdc++.h>
using namespace std;
int p[2000], q[2000], row[2000], col[2000];
int main() {
  int n, m, k, i, j, x, y, c;
  cin >> n >> m >> k;
  for (i = 1; i <= k; i++) {
    cin >> c >> x >> y;
    if (c == 1) {
      row[x] = y;
      p[x] = i;
    } else {
      col[x] = y;
      q[x] = i;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (p[i] == 0 && q[j] == 0)
        cout << 0 << " ";
      else if (p[i] > q[j])
        cout << row[i] << " ";
      else
        cout << col[j] << " ";
    }
    cout << endl;
  }
}
