#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long w[N];
long long get(long long n) {
  if (n & 1) {
    return n * (n - 1) / 2 + 1;
  } else {
    return n * (n - 1) / 2 + 2;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long tmp;
  for (long long i = 0; i < m; ++i) cin >> tmp >> w[i];
  sort(w, w + m);
  reverse(w, w + m);
  long long l = -1;
  long long r = m + 1;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    if (get(mid) <= n)
      l = mid;
    else
      r = mid;
  }
  long long ans = 0;
  for (long long i = 0; i < l; ++i) {
    ans += w[i];
  }
  cout << ans << '\n';
}
