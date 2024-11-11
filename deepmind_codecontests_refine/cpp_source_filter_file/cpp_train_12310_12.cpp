#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a[100], b[100], n, i, j, k, s = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> k;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (i = 0; i < n; i++) {
      if (a[i] < b[n - i - 1]) {
        int temp = a[i];
        a[i] = b[n - 1 - i];
        b[n - 1 - i] = temp;
        k--;
      }
      if (k == 0) break;
    }
    for (i = 0; i < n; i++) s += a[i];
    cout << s << endl;
    s = 0;
  }
  return 0;
}
