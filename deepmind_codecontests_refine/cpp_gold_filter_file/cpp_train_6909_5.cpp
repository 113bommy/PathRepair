#include <bits/stdc++.h>
using namespace std;
long long j, n, k, m, res, mn, mx, a[100005], x, i, r;
int main() {
  cin >> n >> x;
  mn = 1999999999;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (mn >= a[i]) {
      if (mn > a[i]) {
        mn = a[i];
        m = i;
        if (x - 1 > i)
          r = x - i - 1;
        else
          r = x - 1 + n - i - 1;
      } else if (x - 1 >= i && x - i - 1 < r) {
        mn = a[i];
        m = i;
        r = x - i - 1;
      } else if (x - 1 <= i && n - 2 + x - i < r) {
        mn = a[i];
        m = i;
        r = n - 2 + x - i;
      }
    }
  }
  k = 0;
  for (j = x - 1; j != m; j--) {
    if (j == m) break;
    a[j] -= (a[m] + 1);
    k += (a[m] + 1);
    if (j == 0) j = n;
  }
  for (j = x; j != m; j++) {
    if (j == n) j = 0;
    if (j == m) break;
    a[j] -= a[m];
    k += a[m];
  }
  a[m] += k;
  for (i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
