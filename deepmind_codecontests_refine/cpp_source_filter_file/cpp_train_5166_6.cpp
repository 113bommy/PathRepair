#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, m, q, t, k = 0;
  cin >> n >> m >> q;
  t = m - n + 1;
  long long int a[n], b[m], c[t];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      k += a[i];
    else
      k -= a[i];
  }
  c[0] = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      c[0] += b[i];
    else
      c[0] -= b[i];
  }
  for (int i = 1; i < t; i++) {
    c[i] = -c[i - 1] + b[i - 1];
    if (n % 2 == 0)
      c[i] -= b[n + i - 1];
    else
      c[i] += b[n + i - 1];
  }
  sort(c, c + t);
  if (k > c[t - 1])
    cout << k - c[t - 1] << endl;
  else if (k < c[0])
    cout << c[0] - k << endl;
  else {
    int p = 0, e = t, x;
    while (e - p > 1) {
      x = (e + p) / 2;
      if (k >= c[x])
        p = x;
      else
        e = x;
    }
    if (c[e] - k > k - c[p])
      cout << k - c[p] << endl;
    else
      cout << c[e] - k << endl;
  }
  for (int i = 0; i < q; i++) {
    int l, r, y;
    cin >> l >> r >> y;
    if (r % 2 == 0 && l % 2 == 0) k -= y;
    if (r % 2 != 0 && l % 2 != 0) k += y;
    if (k > c[t - 1])
      cout << k - c[t - 1] << endl;
    else if (k < c[0])
      cout << c[0] - k << endl;
    else {
      int p = 0, e = t, x;
      while (e - p > 1) {
        x = (e + p) / 2;
        if (k >= c[x])
          p = x;
        else
          e = x;
      }
      if (c[e] - k > k - c[p])
        cout << k - c[p] << endl;
      else
        cout << c[e] - k << endl;
    }
  }
}
