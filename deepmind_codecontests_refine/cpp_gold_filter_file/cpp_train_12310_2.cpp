#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, i, s;
  cin >> t;
  while (t--) {
    s = 0;
    cin >> n >> k;
    int a[n], b[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    i = 0;
    while (i < n && k--) {
      if (b[i] > a[i]) a[i] = b[i];
      i++;
    }
    for (i = 0; i < n; i++) s += a[i];
    cout << s << endl;
  }
}
