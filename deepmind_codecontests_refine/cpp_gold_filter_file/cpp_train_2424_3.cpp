#include <bits/stdc++.h>
using namespace std;
int t, n, a[105];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i % 2 == 0) {
        cout << -a[i] << " " << a[i - 1] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
