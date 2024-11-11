#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const long long N = 200005;
long long t[2 * N];
void build() {
  for (long long i = N - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
}
long long query(long long l, long long r) {
  long long res = 1e10;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, t[l++]);
    if (r & 1) res = min(res, t[--r]);
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  for (long long ti = 1; ti <= tc; ti++) {
    long long n, m;
    cin >> n >> m;
    long long a[n], b[m];
    map<long long, long long> first;
    for (long long i = 0; i < n; i++) cin >> a[i], t[N + i] = a[i];
    build();
    for (long long i = 0; i < m; i++) cin >> b[i], first[b[i]] = 0;
    for (long long i = 0; i < n; i++) {
      if (first.find(a[i]) != first.end()) first[a[i]] = max(first[a[i]], i);
    }
    long long id = 0, ok = 1, j = 0, mi = 1e10;
    while (j < n && b[id] != a[j]) mi = min(mi, a[j++]);
    ok &= (mi >= b[id]);
    for (; ok && j < n; j++) {
      if (id < m && a[j] == b[id]) mi = b[id], id++;
      mi = min(mi, a[j]);
      ok &= (mi >= b[id - 1]);
    }
    ok &= (id == m);
    if (!ok) return cout << 0, 0;
    long long ans = 1;
    for (long long i = 1; i < m; i++) {
      id = first[b[i]];
      long long l = 0, r = id, x = id;
      while (l <= r) {
        long long mid = (l + r) >> 1LL;
        long long chk = query(mid, id + 1);
        if (chk >= b[i])
          r = mid - 1, x = mid;
        else
          l = mid + 1;
      }
      ans *= (id - x + 1);
      ans += M;
      ans %= M;
    }
    cout << ans << endl;
  }
  return 0;
}
