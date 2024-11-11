#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, m, k;
    cin >> n;
    vector<long long> a(4 * n);
    map<long long, long long> mp;
    for (long long i = 0; i < 4 * n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool c = true;
    for (long long i = 0; i < 4 * n - 1; i += 2) {
      if (a[i] == a[i + 1])
        ;
      else {
        c = false;
      }
    }
    if (!c) {
      cout << "NO\n";
      continue;
    }
    long long l = 3, r = 4 * n - 4, area;
    area = a[1] * a[4 * n - 2];
    while (l < r) {
      if (area != a[l] * a[r]) c = false;
      l += 2;
      r -= 2;
    }
    if (c)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
