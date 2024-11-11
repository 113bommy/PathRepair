#include <bits/stdc++.h>
using namespace std;
const long long maxm = 3e4 + 5;
long long a[maxm];
long long b[maxm];
long long d[maxm];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (long long i = 1; i <= n; i++) {
      a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    for (long long i = 1; i <= n; i++) {
      d[i] = 0;
    }
    long long ma = 0;
    for (long long i = 1; i <= n; i++) {
      d[i] = d[a[i] - 1] + 1;
      ma = max(ma, d[i]);
    }
    cout << n - ma << endl;
  }
  return 0;
}
