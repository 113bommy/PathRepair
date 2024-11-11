#include <bits/stdc++.h>
using namespace std;
long long k, k1, k2, k3, k4, k5, q, x, y, t, u, g, p, ma, mi, r, f1, f2, f, l,
    n, i, m, j, a[1000007], b, c[65], b1[300005], c1[300005], d[300005];
double h, e1, e2, e3, e4, e5;
string s1, s2;
int main() {
  cin >> t;
  for (u = 1; u <= t; u++) {
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i < n; i++) {
      if (a[i] > 0 && a[i + 1] > 0) {
        a[i + 1] = a[i + 1] + a[i];
        a[i] = 0;
      }
      if (a[i] > 0 && a[i + 1] < 0) {
        a[i + 1] = a[i + 1] + a[i];
        a[i] = 0;
      }
    }
    p = 0;
    for (i = 1; i <= n; i++)
      if (a[i] > 0) p = p + a[i];
    cout << p << endl;
  }
  return 0;
}
