#include <bits/stdc++.h>
using namespace std;
int a[100003], b[100003];
int main() {
  int n, m, i, j, k, l, c = 0, it, maxe = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  for (i = 0; i < n; i++) {
    it = lower_bound(b, b + m, a[i]) - b;
    if (it == 0) {
      l = abs(b[it] - a[i]);
      maxe = max(l, maxe);
    } else if (it == n) {
      l = abs(b[it - 1] - a[i]);
      maxe = max(maxe, l);
    } else {
      l = abs(b[it] - a[i]);
      k = abs(b[it - 1] - a[i]);
      l = min(k, l);
      maxe = max(maxe, l);
    }
  }
  cout << maxe << "\n";
}
