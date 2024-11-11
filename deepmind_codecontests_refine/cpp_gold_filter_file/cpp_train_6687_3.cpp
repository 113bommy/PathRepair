#include <bits/stdc++.h>
using namespace std;
long long t, d, m;
long long a[50], len = 0, sum;
signed main() {
  cin >> t;
  while (t--) {
    cin >> d >> m;
    for (long long i = 0; i <= 30; i++) {
      if (d < (1 << i)) {
        a[i] = d;
        len = i;
        break;
      }
      d -= (1 << i);
      a[i] = 1 << i;
      if (d == 0) {
        len = i;
        break;
      }
    }
    sum = 1;
    for (long long i = 1, tmp; i <= len; i++) {
      tmp = sum * a[i] % m + a[i];
      tmp %= m;
      sum = (sum + tmp) % m;
    }
    cout << sum % m << endl;
  }
}
