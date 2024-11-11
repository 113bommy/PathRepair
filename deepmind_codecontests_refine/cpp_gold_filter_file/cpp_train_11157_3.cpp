#include <bits/stdc++.h>
using namespace std;
long long int q, w, i, n, r, b, g, a[3000], ans, x, y, z, k, j, t;
string s;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  for (w = 0; w < q; w++) {
    cin >> n >> k;
    cin >> s;
    if (k == 1)
      cout << 0 << "\n";
    else {
      ans = k - 1;
      for (i = 0; i < n; i++) {
        if (s[i] == 'R') a[i] = 1;
        if (s[i] == 'G') a[i] = 2;
        if (s[i] == 'B') a[i] = 3;
      }
      for (i = 0; i < n - k + 1; i++) {
        x = 0;
        y = 0;
        z = 0;
        for (j = 0; j < k; j++) {
          t = j - a[i + j];
          if (t % 3 != 1 && t % 3 != -2) x = x + 1;
          if (t % 3 != 2 && t % 3 != -1) y = y + 1;
          if (t % 3 != 0) z = z + 1;
        }
        if (x < ans) ans = x;
        if (y < ans) ans = y;
        if (z < ans) ans = z;
      }
      cout << ans;
      if (w < q) cout << "\n";
    }
  }
}
