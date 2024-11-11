#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, s = 0;
  cin >> n >> m >> k;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  if (m <= k) {
    cout << 0 << endl;
    return 0;
  }
  m -= k - 1;
  s = a[0];
  for (i = 1; i < n; i++) {
    if (s >= m) break;
    s += a[i] - 1;
  }
  if (i == n && s < m)
    cout << -1 << endl;
  else
    cout << i << endl;
}
