#include <bits/stdc++.h>
using namespace std;
long long a[200005], md[200005];
long long n;
long long bs(long long p, long long &l, long long r) {
  if (r + l < a[p]) {
    l += r;
    return p;
  }
  long long start = p, end = n;
  long long ret;
  while (start <= end) {
    long long m = (start + end) >> 1;
    if (md[m] - md[p - 1] - l <= r)
      start = m + 1, ret = m;
    else
      end = m - 1;
  }
  if (ret == n) {
    l = 0;
    return 1;
  }
  ret++;
  long long tmp = md[ret] - md[p - 1] - l - r;
  l = a[ret] - tmp;
  return ret;
}
signed main() {
  long long q;
  cin >> n >> q;
  long long sm = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    md[i] = md[i - 1] + a[i];
  }
  long long cur = 1;
  long long l = 0;
  for (long long i = 0; i < q; ++i) {
    long long x;
    cin >> x;
    cur = bs(cur, l, x);
    cout << n - cur + 1;
  }
  return 0;
}
