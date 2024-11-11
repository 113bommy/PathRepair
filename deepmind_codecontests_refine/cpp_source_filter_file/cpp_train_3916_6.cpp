#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lint = long long;
const lint inf = 1e9 + 7;
const int MOD = 1000000007;
signed main() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) cin >> a[i];
  for (int i = 0; i < k; ++i) {
    cnt += a[i] / 4;
    a[i] %= 4;
  }
  if (cnt >= n) {
    cnt -= n;
    cnt *= 2;
    for (int i = 0; i < k; ++i) {
      if (a[i] & 1) ++a[i];
      cnt += a[i] / 2;
    }
    if (cnt <= 2 * n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (k <= n) {
      cout << "YES"
           << "\n";
    } else {
      int c = 0;
      int rem = 0;
      for (int i = 0; i < k; ++i) {
        if (a[i] == 3 && cnt < n) {
          a[i] = 0;
          ++cnt;
        } else {
          c += a[i] / 2;
          a[i] %= 2;
          rem += a[i];
        }
      }
      if (c >= 2 * n) {
        c -= 2 * n;
        c -= n - cnt;
        int v = n - cnt;
        if (c > 0) rem += c * 2;
        if (rem <= v) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else {
        if (rem <= (n - cnt) * 2 + (2 * n - c)) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      }
    }
  }
  return 0;
}
