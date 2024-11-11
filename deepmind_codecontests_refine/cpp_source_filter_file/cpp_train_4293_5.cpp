#include <bits/stdc++.h>
using namespace std;
long long t, n, a[105], dd[105], kt, b[205], m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(dd, 0, sizeof(dd));
    memset(b, 0, sizeof(b));
    m = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      dd[a[i]] = 1;
    }
    for (long long i = 1; i <= n; i++) {
      kt = 0;
      for (long long j = a[i] + 1; j <= 2 * n; j++)
        if (dd[j] == 0) {
          kt = j;
          break;
        }
      if (kt == 0) {
        m = -1;
        break;
      } else {
        m++;
        b[m] = a[i];
        m++;
        b[m] = kt;
        dd[kt] = 1;
      }
    }
    if (m == -1)
      cout << m << '\n';
    else {
      for (long long i = 1; i <= m; i++) cout << b[i] << " ";
      cout << '\n';
    }
  }
  return 0;
}
