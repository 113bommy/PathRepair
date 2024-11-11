#include <bits/stdc++.h>
using namespace std;
long long int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o,
    p = 0, q = 0, r, t, u, v, w, x, y, z, temp = 0, t1, t2, sum = 0, mi = 0,
    mx = 0;
double ans = 0;
int main() {
  string s, t;
  cin >> n >> m;
  if (n > m + 1 || m > 2 * (n + 1))
    cout << -1;
  else {
    if (n == m + 1) {
      for (i = 0; i < n; i++) {
        s += "10";
      }
      s = '0' + s;
      cout << s;
    } else {
      t = "110";
      while (m != n && n != 0) {
        s += t;
        n -= 1;
        m -= 2;
      }
      for (i = 0; i < m; i++) {
        s += "1";
        if (n) {
          s += '0';
          n--;
        }
      }
      cout << s;
    }
  }
}
