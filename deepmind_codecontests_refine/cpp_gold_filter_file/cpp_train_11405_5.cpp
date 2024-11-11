#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, t, c, a[101], k[101], d;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l >> r >> t >> c;
    for (int j = l; j <= r; j++) {
      if (t < k[j] || k[j] == 0) {
        k[j] = t;
        d -= a[j];
        a[j] = c;
        d += a[j];
      }
    }
  }
  cout << d;
}
