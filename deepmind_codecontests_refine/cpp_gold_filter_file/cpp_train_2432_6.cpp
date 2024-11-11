#include <bits/stdc++.h>
using namespace std;
long long x[100002], y[100002], z[100002], w[100002];
int main() {
  long long i, j, n, m, e, a = 2, b = 1, c = 0, d = 1, x1, x2, x3, y1, y2, y3,
                           v = 0;
  cin >> n;
  cin >> x[0];
  y[0] = x[0];
  for (i = 1; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  reverse(x, x + n);
  for (i = 1; i < n; i++) {
    y[i] = y[i - 1] + x[i];
  }
  w[n] = 0;
  for (i = n - 1; i > 0; i--) {
    w[i] = w[i + 1] + x[i];
    v = v + w[i];
  }
  cin >> e;
  for (j = 0; j < e; j++) {
    cin >> m;
    if (m == 1) {
      cout << v << " ";
    } else {
      d = 0;
      z[0] = 0;
      b = m;
      for (i = 1; i < 1000000; i++) {
        z[i] = z[i - 1] + b;
        b = b * m;
        if (z[i] >= n - 1) break;
      }
      d = (y[n - 1] - y[z[i - 1]]) * i;
      for (c = 1; c < i; c++) {
        d = d + c * (y[z[c]] - y[z[c - 1]]);
      }
      cout << d << " ";
    }
  }
}
