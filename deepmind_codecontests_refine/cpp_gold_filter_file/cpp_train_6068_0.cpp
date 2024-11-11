#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int x = a[0];
    for (long long int i = n - 1; i > 0; i--) {
      a[i] -= a[i - 1];
      if (a[i] < 0) x += a[i];
    }
    if (x >= 0)
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
    }
  }
}
