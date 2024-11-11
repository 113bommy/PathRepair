#include <bits/stdc++.h>
using namespace std;
long long a[105], ans[105], b[105];
signed main() {
  long long n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  long long m;
  cin >> m;
  while (m--) {
    long long k, t = 0, c = 0, pos;
    cin >> k >> pos;
    sort(b, b + n);
    memset(ans, 0, sizeof(ans));
    for (i = n - k; i < n; i++) {
      if (b[i] == b[n - k]) t++;
    }
    for (i = 0; i < n; i++) {
      if (a[i] == b[n - k] && t) {
        ans[c++] = a[i];
        t--;
      } else if (a[i] > b[i]) {
        ans[c++] = a[i];
      }
    }
    cout << ans[pos - 1] << endl;
  }
}
