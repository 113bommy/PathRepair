#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n % m == 0) {
    if (n % 2 == 0 && m % 2 == 0) {
      for (long long i = 0; i < n / m; i++) {
        cout << n / m << " ";
      }
    } else {
      for (long long i = 1; i < n / m; i++) {
        cout << n / m << " ";
      }
    }
  } else {
    long long r = n % m;
    long long d = n / m;
    long long val1 = r * (d + 1);
    long long val2 = n - val1;
    long long loo = val2 / d;
    for (long long i = (0); i < (loo); i++) {
      cout << d << " ";
    }
    for (long long i = (0); i < (r); i++) {
      cout << d + 1 << " ";
    }
  }
  return 0;
}
