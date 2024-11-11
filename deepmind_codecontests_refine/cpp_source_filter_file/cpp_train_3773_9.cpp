#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    if (n % 2 == 0) {
      for (long long i = 0; i < n / 2; i++) {
        cout << a[n / 2 - i - 1] << " " << a[n / 2 + i] << " ";
      }
    } else {
      cout << a[n / 2] << " ";
      for (long long i = 0; i < n / 2; i++) {
        cout << a[n / 2 - 1 - i] << " " << a[n / 2 + i - 1] << " ";
      }
    }
    cout << '\n';
  }
}
