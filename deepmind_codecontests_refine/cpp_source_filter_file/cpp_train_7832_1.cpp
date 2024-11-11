#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i >= 2 && ((a[i] <= a[i - 1] && a[i - 1] <= a[i - 2]) ||
                     (a[i] >= a[i - 1] && a[i] >= a[i - 2]))) {
        a[i - 1] = a[i];
        i--;
        n--;
      }
    }
    cout << n << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
  }
  return 0;
}
