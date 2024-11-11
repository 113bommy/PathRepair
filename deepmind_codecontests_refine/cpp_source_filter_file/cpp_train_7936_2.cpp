#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, j, i, n, s[8001], a[8001], l, r, c, sl, k, col[8001];
  bool check;
  cin >> t;
  for (j = 0; j < t; ++j) {
    cin >> n;
    s[0] = 0;
    for (i = 0; i <= n; ++i) col[i] = 0;
    for (i = 1; i <= n; ++i) {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
      col[a[i]] += 1;
    }
    c = 0;
    for (i = 2; i <= n; ++i) {
      check = true;
      if (col[i] > 0) {
        for (sl = 0; sl <= n && check; ++sl) {
          l = sl + 2;
          r = n;
          while (l < r) {
            k = (l + r) / 2;
            if (s[k] >= s[sl] + i) {
              r = k;
            } else
              l = k + 1;
          }
          if (s[l] == s[sl] + i && l >= sl + 2) {
            check = false;
            c += col[i];
          }
        }
      }
    }
    cout << c << endl;
  }
  return 0;
}
