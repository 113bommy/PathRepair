#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n, a[123456], b[123456], c, d, e, s, t;
string p, q, r, w;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    b[i] = b[i - 1] + a[i];
    e += b[i - 1];
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> d;
    s = b[n - 2];
    t = d;
    if (d == 1) {
      cout << e << ' ';
      continue;
    }
    while (n - 1 > t) {
      s += b[n - 2 - t];
      t = t * d;
    }
    cout << s << ' ';
  }
  return 0;
}
