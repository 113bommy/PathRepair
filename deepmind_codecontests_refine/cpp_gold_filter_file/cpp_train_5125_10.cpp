#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, *a, i, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    a = new int[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 1; i < n && d > 0; i++) {
      if (a[i] * i <= d) {
        a[0] += a[i];
        d -= i * a[i];
      } else {
        a[0] += d / i;
        d = 0;
      }
    }
    cout << a[0] << endl;
  }
}
