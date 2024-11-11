#include <bits/stdc++.h>
using namespace std;
long long mod = 1e7 + 7;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
void fun() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, x, y;
    cin >> n >> m >> x >> y;
    string s[n];
    for (long long i = 0; i < n; i++) cin >> s[i];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == '*') continue;
        if (y < 2 * m && j + 1 < m && s[i][j + 1] == '.') {
          sum += y;
          j++;
        } else
          sum += x;
      }
    }
    cout << sum << endl;
  }
}
