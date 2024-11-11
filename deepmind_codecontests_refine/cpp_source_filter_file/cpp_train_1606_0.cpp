#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    long long a[n], b[n];
    long long x[n], y[n];
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    for (long long i = 0; i < n / 2; i++) {
      x[i] = 1;
      y[i] = 1;
    }
    long long i = 0, j = 0;
    while (i + j < n) {
      if (a[i] <= b[j])
        x[i++] = 1;
      else
        b[j++] = 1;
    }
    for (long long i = 0; i < n; i++) cout << x[i];
    cout << '\n';
    for (long long i = 0; i < n; i++) cout << y[i];
  }
  return 0;
}
