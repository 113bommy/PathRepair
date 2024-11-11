#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long x, k, y;
  cin >> x >> k >> y;
  long long a[n], b[m];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < m; i++) cin >> b[i];
  long long p = 0;
  vector<long long> v;
  v.push_back(-1);
  for (long long i = 0; i < n; i++) {
    if (p < m && a[i] == b[p]) {
      v.push_back(i);
      p++;
    }
  }
  v.push_back(n);
  if (p != m) {
    cout << -1 << endl;
    return 0;
  }
  bool ok = 1;
  long long ans = 0;
  for (long long i = 1; i < v.size(); i++) {
    long long l = v[i - 1], r = v[i];
    long long len = r - l - 1;
    long long m = -5;
    for (long long i = l + 1; i < r; i++) {
      m = max(m, a[i]);
    }
    long long v1 = -50, v2 = -50;
    if (l != -1) v1 = a[l];
    if (r != n) v2 = a[r];
    long long curr = 0;
    if (len % k != 0) {
      if (len < k and v1 < m and v2 < m) {
        ok = 0;
        break;
      } else {
        curr += y * (len % k);
      }
    }
    len -= len % k;
    if (len == 0) {
      ans += curr;
      continue;
    }
    long long val = x * (len / k);
    if (v1 > m or v2 > m) {
      val = min(val, y * (len));
    } else {
      val = min(val, x + y * (len - k));
    }
    curr += val;
    ans += curr;
  }
  if (ok)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
