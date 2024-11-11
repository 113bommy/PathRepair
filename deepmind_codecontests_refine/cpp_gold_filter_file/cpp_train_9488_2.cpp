#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long cnt[200005];
long long n, m;
long long fn(long long d) {
  long long r = cnt[d];
  for (long long i = d + 1; i <= n; i++) {
    r += max(0LL, (a[i] - ((i - 1) / d)));
  }
  return (r >= m) ? 1 : 0;
}
int32_t main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<long long>());
  for (long long i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1] + a[i];
  }
  if (cnt[n] < m) {
    cout << -1;
    return 0;
  }
  long long l = 1, r = n;
  while (l <= r) {
    long long md = (l + r) / 2;
    long long d = fn(md);
    if (d == 0) {
      l = md + 1;
    } else {
      r = md - 1;
    }
  }
  cout << l;
  return 0;
}
