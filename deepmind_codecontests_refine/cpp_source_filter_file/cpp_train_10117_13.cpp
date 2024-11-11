#include <bits/stdc++.h>
using namespace std;
const int p = 5000005;
int a[p], b[p], t, x, y, n, res, z, m[710][710];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> z >> x >> y;
    if (z == 1) {
      a[x] += y;
      for (int i = 1; i < 701; i++) {
        m[i][x % i] += y;
      };
    } else {
      if (x <= 701) {
        cout << m[x][y] << '\n';
      } else {
        res = 0;
        for (int i = y; i < 500001; i += x) {
          res += a[i];
        };
        cout << res << '\n';
      }
    }
  }
}
