#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const long long di = 1e9 + 7;
int num[maxn];
long long quick(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) {
      c *= a;
      c %= di;
    }
    b >>= 1;
    a *= a;
    a %= di;
  }
  return c;
}
int main() {
  int n, m, k;
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  int e, f;
  long long cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> e >> f;
    if (f - e != 1 && f - e != k + 1) {
      cout << 0 << endl;
      return 0;
    }
    if (f - e == k + 1) {
      num[f]++;
      cnt++;
    }
  }
  if (!cnt) {
    long long ans = 1;
    for (int i = k + 2; i <= n; i++) {
      long long e = min(k, i - k - 2);
      ans += quick(2, e);
      ans %= di;
    }
    cout << ans << endl;
    return 0;
  }
  int mi = 1e7, ma = -1;
  for (int i = 1; i <= n; i++) {
    if (num[i]) {
      mi = min(mi, i), ma = max(ma, i);
    }
  }
  if (ma - mi > k + 1) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = ma; i <= n && i - mi < k + 1; i++) {
    long long e = min(k + 1, i - k - 1);
    e -= cnt + 1;
    if (i == ma) e++;
    ans += quick(2, e);
    ans %= di;
  }
  cout << ans << endl;
}
