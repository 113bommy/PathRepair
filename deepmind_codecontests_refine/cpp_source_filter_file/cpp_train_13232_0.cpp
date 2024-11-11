#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 7;
const long long int inf = 1e16 + 9;
const long long int mod = 1e9 + 7;
int main() {
  long long int n, m, l, i, j, k, p, d, ans = 0;
  cin >> n >> m >> l;
  long long int a[n + 1], b[n + 1];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > l) {
      b[i] = 1;
    } else
      b[i] = 0;
  }
  b[i] = 0;
  for (i = 1; i <= n; i++) {
    if (b[i] == 0 && b[i - 1] == 1) ans++;
  }
  for (i = 0; i < m; i++) {
    cin >> k;
    if (k == 0) {
      printf("%lld\n", ans);
    } else {
      cin >> p >> d;
      p--;
      if (a[p] <= l && a[p] + d > l) {
        if (p == 0) {
          if (b[1] == 0) ans++;
        } else if (p == n - 1) {
          if (b[n - 2] == 0) ans++;
        } else {
          if (b[p - 1] == 0 && b[p + 1] == 0) ans++;
          if (b[p - 1] == 1 && b[p - 1] == 1) ans--;
        }
        b[p] = 1;
      }
      a[p] += d;
    }
  }
  return 0;
}
