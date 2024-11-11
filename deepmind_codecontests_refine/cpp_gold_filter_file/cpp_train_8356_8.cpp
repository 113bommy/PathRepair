#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long maxn = (long long)3e5 + 5;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
long long T = 1;
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i <= 1000; ++i) {
    if (i * 3 > n) {
      cout << -1 << '\n';
      return;
    }
    for (long long j = 0; j <= 1000; ++j) {
      if (i * 3 + j * 5 > n) break;
      long long k = n - 3 * i - 5 * j;
      if (k % 7 == 0) {
        cout << i << ' ' << j << ' ' << k / 7 << '\n';
        return;
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> T;
  while (T--) solve();
  return 0;
}
