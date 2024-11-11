#include <bits/stdc++.h>
using namespace std;
long long n, m, l, r, mid, ans;
bool ok(long long k) {
  long long t = k * m, maxn = 1, C = 1;
  for (long long i = 1; i <= k; ++i) {
    C = C * (k - i + 1) / i;
    if (i <= t / C) {
      t -= C * i;
      maxn += C;
    } else {
      maxn += t / i;
      break;
    }
  }
  return maxn >= n;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    if (m * 2 > n) m = n / 2;
    l = 0, r = n;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (ok(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
