#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j, k, d, s;
  long double p, q = 0.000000000;
  cin >> n >> d;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 2; i++) {
    if (a[i + 2] - a[i] <= d) break;
  }
  if (i == n - 2) {
    cout << "-1";
  } else {
    for (i = 0; i < n - 2; i++) {
      if (a[i + 2] - a[i] <= d) {
        long long e = a[i] + d;
        s = lower_bound(a + 2, a + n, e) - a;
        if (a[s] > e) s--;
        if (s < n && a[s] != a[i] && a[s] != a[i + 1] && (a[s] - a[i]) <= d) {
          p = (long double)(a[s] - a[i + 1]) / (long double)(a[s] - a[i]);
          if (p > q) q = p;
        }
      }
    }
    printf("%.15Lf", q);
  }
  return 0;
}
