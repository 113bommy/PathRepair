#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, x, y, z;
int l[100500], r[100500], l300[100500], r300[100500], k2;
void work(int x) {
  for (i = 1, k = y; i < 150; i++) k = l[k];
  k2 = r[y];
  for (i = 1; i <= 150; i++) {
    r300[k] = k2;
    l300[k2] = k;
    k = r[k];
    k2 = r[k2];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> t;
  for (i = 1; i <= n; i++) cin >> r[i], l[r[i]] = i;
  for (i = 1; i <= n; i++) {
    for (j = 1, k = i; j <= 150; j++) k = r[k];
    r300[i] = k;
    l300[k] = i;
  }
  while (t--) {
    cin >> x >> y >> z;
    if (x == 1) {
      swap(r[y], r[z]);
      l[r[y]] = y;
      l[r[z]] = z;
      work(y);
      work(z);
    } else {
      while (z > 150) y = r300[y], z -= 150;
      while (z) y = r[y], z--;
      cout << y << '\n';
    }
  }
}
