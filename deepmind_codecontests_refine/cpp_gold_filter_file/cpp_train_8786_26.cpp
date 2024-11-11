#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, i, l, j, s, t, a[200], b, c, d;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  cin >> x >> y;
  for (i = 1; i <= n; i++) s += a[i];
  for (i = 1; i <= n; i++) {
    m += a[i];
    if (m >= x && m <= y && s - m >= x && s - m <= y) {
      cout << i + 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
