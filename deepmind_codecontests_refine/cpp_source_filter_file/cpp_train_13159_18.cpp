#include <bits/stdc++.h>
using namespace std;
int main() {
  long c1, c2, c3, c4;
  while (cin >> c1 >> c2 >> c3 >> c4) {
    long a[100000] = {0}, cp[10] = {0}, x, b[100000] = {0}, n, m, k = 1,
         c[10000] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    c[0] = c3;
    for (int i = 0; i < n; i++) {
      x = a[i];
      cp[0] = x * c1;
      cp[1] = c2;
      sort(cp, cp + 2);
      c[1] = c[1] + cp[0];
    }
    long m1[10000] = {0}, mm[10000] = {0};
    sort(c, c + 2);
    mm[0] = c[0];
    c[0] = c3;
    c[1] = 0;
    for (int i = 0; i < n; i++) {
      x = b[i];
      cp[0] = x * c1;
      cp[1] = c2;
      sort(cp, cp + 2);
      c[1] = c[1] + cp[0];
    }
    sort(c, c + 2);
    mm[1] = c[0];
    m1[0] = mm[0] + mm[1];
    m1[1] = c4;
    m1[2] = c3 * 2;
    sort(m1, m1 + 3);
    cout << m1[0] << "\n";
  }
  return 0;
}
