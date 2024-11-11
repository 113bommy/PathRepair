#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
const double PI = acos(-1);
const long long N = 1e6 + 7;
long long mod = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, i, j, p, q, tests, t;
  string s;
  cin >> tests;
  long long l, r, k, x, y;
  while (tests--) {
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    map<long long, long long> m1, m2;
    long long l1, l2;
    for (i = 0; i < n; i++) {
      if (m1[a[i]]) {
        l1 = i;
        break;
      }
      ++m1[a[i]];
    }
    for (i = n - 1; i >= 0; i--) {
      if (m2[a[i]]) {
        l2 = n - i - 1;
        break;
      }
      ++m2[a[i]];
    }
    if (l1 < l2) {
      l1 = n - l2;
      sort(a, a + l1);
      for (i = 0; i < l1; i++) {
        if (a[i] != i + 1) break;
      }
      sort(a + l1, a + n);
      for (j = 0; j < l2; j++) {
        if (a[j + l1] != j + 1) break;
      }
      if (i != l1 || j != l2) {
        cout << "0\n";
        continue;
      }
      cout << 1 << "\n";
      cout << (n - l2) << " " << l2 << "\n";
    } else if (l1 > l2) {
      l2 = n - l1;
      sort(a, a + l1);
      for (i = 0; i < l1; i++) {
        if (a[i] != i + 1) break;
      }
      sort(a + l1, a + n);
      for (j = 0; j < l2; j++) {
        if (a[j + l1] != j + 1) break;
      }
      if (i != l1 || j != l2) {
        cout << "0\n";
        continue;
      }
      cout << 1 << "\n";
      cout << l1 << " " << (n - l1) << "\n";
    } else if (l1 == n / 2 && n % 2 == 0) {
      l1 = n - l2;
      sort(a, a + l1);
      for (i = 0; i < l1; i++) {
        if (a[i] != i + 1) break;
      }
      sort(a + l1, a + n);
      for (j = 0; j < l2; j++) {
        if (a[j + l1] != j + 1) break;
      }
      if (i != l1 || j != l2) {
        cout << "0\n";
        continue;
      }
      cout << 1 << "\n";
      cout << l1 << " " << l1 << "\n";
    } else {
      l1 = n - l2;
      sort(a, a + l1);
      for (i = 0; i < l1; i++) {
        if (a[i] != i + 1) break;
      }
      sort(a + l1, a + n);
      for (j = 0; j < l2; j++) {
        if (a[j + l1] != j + 1) break;
      }
      if (i != l1 || j != l2) {
        cout << "0\n";
        continue;
      }
      cout << 2 << "\n";
      cout << (n - l2) << " " << l2 << "\n";
      cout << (l1) << " " << n - l2 << "\n";
    }
  }
}
