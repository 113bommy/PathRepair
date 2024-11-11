#include <bits/stdc++.h>
using namespace std;
int n, m, a[100], t, i, r;
int main() {
  cin >> m >> n;
  r = 10e4;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (m == n) {
    r = min(r, a[n - 1] - a[0]);
  } else {
    for (i = 0; i <= n - m; i++) {
      r = min(r, a[i + m - 1] - a[i]);
    }
  }
  cout << r;
}
