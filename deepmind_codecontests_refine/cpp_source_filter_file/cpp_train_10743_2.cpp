#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, tc;
  cin >> t;
  for (tc = 0; tc < t; tc++) {
    long long n, m, i, ans = 0;
    cin >> n >> m;
    vector<pair<long long, long long> > a(n);
    for (i = 0; i < n; i++) {
      long long p;
      cin >> p;
      a[i] = {p, i + 1};
      ans = ans + 2 * p;
    }
    if (n == 2) {
      cout << '-' << '1' << '\n';
    }
    if (m < n) {
      cout << '-' << '1' << '\n';
    } else {
      sort(a.begin(), a.end());
      ans = ans + (m - n) * (a[0].first + a[1].first);
      cout << ans << '\n';
      for (i = 0; i < n - 1; i++) {
        cout << i + 1 << ' ' << i + 2 << '\n';
      }
      cout << n << ' ' << '1' << '\n';
      for (i = 0; i < m - n; i++) {
        cout << a[0].second << ' ' << a[1].second << '\n';
      }
    }
  }
  return 0;
}
