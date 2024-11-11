#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n, m, k, p, q, i;
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  p = -500;
  q = 500;
  for (i = m - 1; i > 0; i--) {
    if (a[i] <= k && a[i] != 0) {
      p = i;
      break;
    }
  }
  for (i = m + 1; i <= n; i++) {
    if (a[i] <= k && a[i] != 0) {
      q = i;
      break;
    }
  }
  cout << min(q - m, m - p) * 10;
  return 0;
}
