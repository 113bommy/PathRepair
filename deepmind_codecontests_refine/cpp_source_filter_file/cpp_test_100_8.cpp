#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n <= 1) {
      cout << a[0] << endl;
    } else {
      sort(a, a + n);
      int mx = a[1] - a[0];
      for (int i = 1; i < n - 1; i++) {
        mx = max(a[i + 1] - a[i], mx);
      }
      cout << mx << endl;
    }
  }
  return 0;
}
