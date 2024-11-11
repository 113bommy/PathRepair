#include <bits/stdc++.h>
using namespace std;
long long a[20];
int main() {
  int t;
  long long n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long k, q, p;
    for (int i = 1; i < n; i++) {
      p = m - pow(10, a[i + 1] - a[i]) + 1;
      if (p < 0) {
        k = m;
        q = a[i];
        break;
      } else
        m = p;
    }
    if (p >= 0) {
      printf("%lld", (p + 1));
      for (int i = 1; i <= a[n]; i++) cout << "9";
      cout << endl;
    } else {
      cout << (long long)(k + 1);
      for (int i = 1; i <= q; i++) cout << "9";
      cout << endl;
    }
  }
  return 0;
}
