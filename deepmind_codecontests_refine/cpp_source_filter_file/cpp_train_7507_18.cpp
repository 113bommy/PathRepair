#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1100] = {}, b[1100] = {}, r[1100] = {}, m, e, c, d, f[1100] = {},
         g[1100] = {}, h[1100] = {}, p;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> e >> c >> d;
    a[e] = c;
    b[e] = d;
    r[e] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] && !r[i]) {
      int mi = b[i], cur = a[i], beg = i;
      a[i] = 0;
      while (a[cur]) {
        mi = min(mi, b[cur]);
        p = cur;
        cur = a[cur];
        a[p] = 0;
      }
      if (cur != beg) {
        f[++f[0]] = beg;
        g[f[0]] = cur;
        h[f[0]] = mi;
      }
    }
  }
  cout << f[0] << '\n';
  for (int i = 1; i <= f[0]; ++i)
    cout << f[i] << ' ' << g[i] << ' ' << h[i] << '\n';
}
