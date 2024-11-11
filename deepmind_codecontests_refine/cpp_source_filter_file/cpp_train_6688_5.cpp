#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const long long modd1 = 1e9 + 7, modd2 = 998244353, maxn = 10;
const double pi = acos(-1);
void solve() {
  long long n, i, j, k, l, r, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long a[n + 5];
    bool ok = 0;
    for (i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == k) {
        ok = 1;
      }
    }
    if (!ok) {
      cout << "no\n";
      continue;
    }
    bool sol = 0;
    for (i = 0; i < n - 1; ++i) {
      if (a[i] >= k && a[i + 1] >= k) {
        sol = 1;
      }
    }
    for (i = 0; i < n - 2; ++i) {
      if (a[i] >= k && a[i + 2] >= k) {
        sol = 1;
      }
    }
    if (n == 1) {
      cout << "yes\n";
    } else {
      if (sol)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
