#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 3;
const int maxn = 1e6 + 5;
long long a[maxn];
long long qpow(long long x, long long y, long long mod) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    long long ans, ans1, cnt, cnt1;
    ans = ans1 = 0;
    for (int i = 1; i <= n; i++) {
      cnt = qpow(k, a[i], mod);
      cnt1 = qpow(k, a[i], mod1);
      if (ans == 0 && ans1 == 0) {
        ans = (ans + cnt) % mod;
        ans1 = (ans1 + cnt1) % mod1;
      } else {
        ans = (ans - cnt + mod) % mod;
        ans1 = (ans1 - cnt1 + mod1) % mod1;
      }
    }
    cout << ans << endl;
  }
}
