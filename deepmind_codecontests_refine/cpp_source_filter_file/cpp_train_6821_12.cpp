#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, x, y, l;
  cin >> n >> m >> k;
  long long a[n][m];
  memset(a, 0, sizeof(a));
  long long r[n][2], c[m][2];
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  for (int i = 0; i < k; i++) {
    cin >> x >> y >> l;
    if (x == 1) {
      r[y - 1][0] = l;
      r[y - 1][1] = i;
    } else {
      c[y - 1][0] = l;
      c[y - 1][1] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[j][1] > r[i][1])
        a[i][j] = c[j][0];
      else
        a[i][j] = r[i][0];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
