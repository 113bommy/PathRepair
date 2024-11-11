#include <bits/stdc++.h>
using namespace std;
long long c, j, d, t, k, i, x, n, m, u;
signed main() {
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> n;
    vector<long long> v;
    for (j = 1; j <= n; j++) {
      cin >> x;
      if (x % 2 == 0) {
        v.push_back(j);
      }
    }
    if (n % 2 == 0) {
      k = n / 2;
      m = 0;
      u = 0;
      if (v.size() != k) {
        cout << -1 << "\n";
      } else {
        for (j = 1; j <= k; j++) {
          m = m + abs(v[j - 1] - 2 * j + 1);
          u = u + abs(v[j - 1] - 2 * j);
        }
        if (m < u) {
          cout << m << "\n";
        } else {
          cout << u << "\n";
        }
      }
    } else {
      k = n / 2;
      m = 0;
      u = 0;
      if (v.size() == k) {
        for (j = 1; j <= k; j++) {
          m = m + abs(v[j - 1] - 2 * j);
        }
        cout << n << "\n";
      } else if (v.size() == k + 1) {
        for (j = 1; j <= k + 1; j++) {
          u = u + abs(v[j - 1] - 2 * j + 1);
        }
        cout << u << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }
}
