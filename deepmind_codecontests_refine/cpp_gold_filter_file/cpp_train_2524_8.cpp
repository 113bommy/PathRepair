#include <bits/stdc++.h>
const long long INF = 1000000000000000001;
const long double E = 0.00000001;
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t1;
  cin >> t1;
  for (long long q11 = 0; q11 < t1; q11++) {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (long long q = 0; q < n; q++) {
      cin >> a[q];
    }
    bool flag = false;
    for (long long q = 0; q < n; q++) {
      if (a[q] % x != 0) {
        flag = true;
      }
    }
    if (!flag) {
      cout << -1 << '\n';
    } else {
      vector<long long> pref = {0};
      for (long long q = 0; q < n; q++) {
        pref.push_back(pref.back() + a[q]);
      }
      long long q1 = 0;
      while (pref[q1] % x == pref[0] % x) {
        q1++;
      }
      long long ans = 1;
      for (long long q = q1; q < n + 1; q++) {
        if (pref[0] % x == pref[q] % x) {
          ans = max(ans, q - q1);
        } else {
          ans = max(ans, q);
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
