#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n];
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  int d = m - 1, kk = m - 1;
  while (1) {
    if (d < n && a[d] < k) {
      int ans = 10 * (d - m + 1);
      if (a[d]) {
        cout << ans;
        return 0;
      }
    }
    if (kk >= 0 && a[kk] < k) {
      int ans = 10 * (m - 1 - kk);
      if (a[kk]) {
        cout << ans;
        return 0;
      }
    }
    d++;
    kk--;
  }
}
