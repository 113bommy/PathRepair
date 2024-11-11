#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], x[n];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) x[i] = 10e8;
  int dt[m], dl[m], dr[m], dd[m];
  for (int j = 0; j < m; j++) {
    int t, l, d, r;
    cin >> t >> l >> r >> d;
    l--;
    r--;
    if (t == 1)
      for (int i = l; i <= r; i++) a[i] += d;
    else
      for (int i = l; i <= r; i++) x[i] = min(x[i], d - a[i]);
    dt[j] = t, dl[j] = l, dr[j] = r, dd[j] = d;
  }
  int backup[n];
  for (int i = 0; i < n; i++) backup[i] = x[i];
  bool ok = true;
  for (int j = 0; j < m; j++) {
    int t = dt[j], l = dl[j], d = dd[j], r = dr[j];
    int maxi = 0;
    if (t == 1)
      for (int i = l; i <= r; i++) backup[i] += d;
    else {
      for (int i = l; i <= r; i++) maxi = max(maxi, backup[i]);
      if (maxi != d) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << x[i] << " ";
  } else
    cout << "NO" << endl;
}
