#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, mx = -1, cnt = 0;
  cin >> n >> r;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (i > mx) {
      int p = i - r + 1, q = i + r - 1, fl = 0;
      if (p < 0) p = 0;
      if (r > n - 1) r = n - 1;
      for (int j = p; j <= q; j++) {
        if (a[j] == 1) {
          mx = j + r - 1;
          fl = 1;
        }
      }
      if (fl)
        cnt++;
      else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
