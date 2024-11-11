#include <bits/stdc++.h>
using namespace std;
int n, q, a[300003], near[300003][20], last[300003];
signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    for (int k = 0; k < 20; k++) {
      near[i][k] = n + 1;
      if (((1 << k) & a[i]) && last[k]) near[i][k] = last[k];
      for (int j = 0; j < 20; j++) {
        if (last[j] && ((a[i] >> j) & 1)) {
          near[i][k] = min(near[i][k], near[last[j]][k]);
        }
      }
      if (near[i][k] == n + 1) near[i][k] = i;
    }
    for (int k = 0; k < 20; k++)
      if ((a[i] >> k) & 1) last[k] = i;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 20; i++) {
      if (((a[r] >> i) & 1) && near[l][i] != l && near[l][i] <= r) {
        puts("Shi");
        l = r;
        break;
      }
    }
    if (l < r) puts("Fou");
  }
}
