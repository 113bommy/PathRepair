#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, n, m, b, e, d;
  cin >> n >> m;
  int r[5005], c[5005], r1[5005], c1[5005];
  for (i = 0; i < n; i++) {
    r[i] = 0;
  }
  for (j = 0; j < m; j++) {
    c[j] = 0;
  }
  cin >> k;
  int h = 1;
  while (k--) {
    cin >> d >> b >> e;
    if (d == 1) {
      r[b] = e;
      r1[b] = h;
    } else if (d == 2) {
      c[b] = e;
      c1[b] = h;
    }
    h++;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (r1[i] > c1[j])
        cout << r[i] << " ";
      else
        cout << c[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
