#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long z;
  z = 1;
  while (z--) {
    unsigned long long int i, j, k, m,
        x = 0, y, z, s0 = 0, s1 = 0, s2 = 0, l, r, u, d, s3 = 0, s5 = 0, s6 = 0,
        s4 = 0, p1 = 0, p2 = 0, p3 = 0, ans = 0, mid = 0, n;
    cin >> n >> m;
    long long int a[n], b[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
      cin >> b[i];
    }
    l = 0;
    r = 200000000000;
    while (l <= r) {
      mid = (l + r) / 2;
      s1 = 0;
      bool p = true;
      for (i = 0; i < n; i++) {
        if ((a[i] * mid) > b[i]) s1 = s1 + a[i] * mid - b[i];
        if (s1 > m) {
          p = false;
          break;
        }
      }
      if (p) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << mid << "\n";
  }
}
