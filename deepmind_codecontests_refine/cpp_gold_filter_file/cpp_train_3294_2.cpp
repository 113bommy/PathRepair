#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int a[x];
    for (int i = 0; i < x; i++) cin >> a[i];
    int bg = 0, fi = n + 1, m, hf;
    int ans = INT_MIN;
    for (int i = 0; i < x; i++) {
      if (i == 0) {
        m = a[i] - bg;
        if (m > ans) ans = m;
      } else {
        m = a[i] - a[i - 1] - 1;
        hf = (m + 1) / 2;
        if (hf + 1 > ans) ans = hf + 1;
      }
    }
    m = fi - a[x - 1];
    if (m > ans) ans = m;
    cout << ans << endl;
  }
  return 0;
}
