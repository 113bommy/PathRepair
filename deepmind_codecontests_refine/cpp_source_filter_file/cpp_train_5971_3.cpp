#include <bits/stdc++.h>
using namespace std;
long long C(long long n, long long r) {
  long long ret = 1;
  long long b = min(r, n - r);
  long long i = max(r, n - r) + 1;
  long long j = 2;
  while (i <= n) {
    ret *= i;
    while (j <= b && ret & j == 0) {
      ret /= j;
      j++;
    }
    i++;
  }
  return ret < 0 ? 10000000000LL : ret;
}
bool F(long long n, long long m, long long k) {
  long long t = m * k;
  long long cnt = 0;
  for (int i = 1; t / i > 0 && t > 0 && i <= k && cnt < n; i++) {
    long long z = C(k, i);
    cnt += min(t / i, z);
    t -= min(t / i, z) * i;
  }
  return cnt >= n - 1;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long s = 1, e = n;
  long long ans = e;
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  while (s <= e) {
    if (F(n, m, (s + e) / 2)) {
      ans = (s + e) / 2;
      e = (s + e) / 2 - 1;
    } else {
      s = (s + e) / 2 + 1;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
