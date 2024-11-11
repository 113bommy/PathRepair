#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long max, min, i, j, a[105], q, k, n;
  cin >> q;
  while (q--) {
    max = 0;
    min = 0x3f3f3f3f;
    memset(a, 0, sizeof(a));
    cin >> n >> k;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] <= min) min = a[i];
      if (a[i] >= max) max = a[i];
    }
    if (max - min > 2 * k) {
      cout << -1 << endl;
    } else {
      cout << min + k << endl;
    }
  }
  return 0;
}
