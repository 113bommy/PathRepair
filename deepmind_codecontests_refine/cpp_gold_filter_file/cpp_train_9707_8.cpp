#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long N = 100005;
long long a[N], b[N], n, k;
long long f(long long x, long long v) {
  return (x - (3 * v * v) + (3 * v) - 1);
}
long long bsearch2(long long x, long long v) {
  long long l = 0, r = x + 1;
  while ((r - l) > 1) {
    long long mid = (l + (r - l) / 2);
    if (f(x, mid) >= v)
      l = mid;
    else
      r = mid;
  }
  return l;
}
long long items(long long v) {
  long long tot = 0;
  for (long long i = 1; i <= n; i++) tot += bsearch2(a[i], v);
  return tot;
}
long long bsearch1() {
  long long l = -4e18, r = 4e18 + 1;
  while ((r - l) > 1) {
    long long mid = (l + (r - l) / 2);
    if (items(mid) < k)
      r = mid;
    else
      l = mid;
  }
  return l;
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long val = bsearch1();
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    b[i] = bsearch2(a[i], val);
    sum += b[i];
  }
  if (sum > k) {
    for (long long i = 1; i <= n; i++)
      if (f(a[i], b[i]) == val) {
        b[i]--;
        --sum;
        if (sum == k) break;
      }
  }
  for (long long i = 1; i <= n; i++) cout << b[i] << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
