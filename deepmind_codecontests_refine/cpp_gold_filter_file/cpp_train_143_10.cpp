#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e8 + 1e5;
int main() {
  long long t, i, j, k, ans, n;
  t = 1;
  while (t--) {
    cin >> n >> k;
    vector<long long> v(n + 1, inf), ty(k), l(k), r(k), b(k), c(n + 1);
    for (long long p = 0; p < k; p++) {
      cin >> ty[p] >> l[p] >> r[p] >> b[p];
    }
    for (long long p = k - 1; p >= 0; p--) {
      if (ty[p] == 1) {
        for (long long q = l[p]; q < r[p] + 1; q++) v[q] -= b[p];
      } else {
        for (long long q = l[p]; q < r[p] + 1; q++) v[q] = min(v[q], b[p]);
      }
    }
    for (long long p = 0; p < n + 1; p++) c[p] = v[p];
    for (long long p = 0; p < k; p++) {
      if (ty[p] == 1) {
        for (long long q = l[p]; q < r[p] + 1; q++) v[q] += b[p];
      } else {
        long long ma = -inf;
        for (long long q = l[p]; q < r[p] + 1; q++) ma = max(ma, v[q]);
        if (ma != b[p]) {
          cout << "NO\n";
          return 0;
        }
      }
    }
    cout << "YES\n";
    for (long long p = 1; p < n + 1; p++) cout << c[p] << " ";
  }
  return 0;
}
