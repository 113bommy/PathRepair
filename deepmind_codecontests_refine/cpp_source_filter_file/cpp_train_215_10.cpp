#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, n, m, x = 0, y, z;
  cin >> n >> m;
  long long a[n + 5];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  k = (n + 1) / 2;
  if (a[k] == m) {
    cout << 0 << endl;
    return 0;
  }
  if (a[k] > m) {
    x = abs(a[k] - m);
    a[k] = a[k] - x;
    for (i = k; i >= 1; i--) {
      if (a[i - 1] > a[i] && i - 1 >= 1) {
        z = abs(a[i] - a[i - 1]);
        x = x + z;
        a[i] = a[i] - z;
      }
    }
    cout << x << endl;
    return 0;
  }
  x = abs(a[k] - m);
  a[k] = m;
  for (i = k + 1; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      z = abs(a[i] - a[i - 1]);
      x = x + z;
      a[i] = a[i] + z;
    }
  }
  cout << x << endl;
}
