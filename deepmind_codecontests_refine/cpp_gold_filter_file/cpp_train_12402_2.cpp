#include <bits/stdc++.h>
using namespace std;
int n, a[200005], ans;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  if (a[n] == 0) {
    cout << -1;
    return 0;
  }
  int i = 1, j = 0;
  while (i <= n && j < 30) {
    int p = -1;
    for (int k = j; k < 30; k++) {
      if (a[i] & (1 << k)) {
        p = k;
        break;
      }
    }
    if (p == -1) {
      i++;
      continue;
    }
    if (p != j) {
      for (int k = 1; k <= n; k++) {
        a[k] += ((a[k] & (1 << j)) > 0) * ((1 << p) - (1 << j)) +
                (((a[k] & (1 << p)) > 0)) * ((1 << j) - (1 << p));
      }
    }
    for (int k = j + 1; k < 30; k++) {
      if (a[i] & (1 << k)) {
        for (int t = i; t <= n; t++) {
          a[t] ^= (1 << k) * ((a[t] & (1 << j)) > 0);
        }
      }
    }
    ans++;
    i++;
    j++;
  }
  cout << ans;
}
