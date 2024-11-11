#include <bits/stdc++.h>
using namespace std;
int n, q, a[200005], b[200005], c[200005], d[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      a[p] = x;
      b[p] = i;
      d[i] = d[i - 1];
    } else {
      cin >> c[i];
    }
  }
  d[q] = q;
  for (int i = q - 1; i >= 0; i--) {
    if (c[d[i + 1]] < c[i])
      d[i] = i;
    else
      d[i] = d[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0)
      a[i] = max(a[i], c[d[1]]);
    else {
      a[i] = max(a[i], c[d[b[i]]]);
    }
    cout << a[i] << ' ';
  }
}
