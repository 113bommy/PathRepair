#include <bits/stdc++.h>
using namespace std;
long long n;
class fenwicktree {
 public:
  long long n;
  long long b[100005];
  fenwicktree(long long N) {
    n = N;
    for (long long i = 0; i <= n; i++) b[i] = 0;
  }
  long long sum(long long idx) {
    long long ret = 0;
    for (idx; idx > 0; idx -= (idx & -idx)) ret += b[idx];
    return ret;
  }
  void add(long long idx, long long delta) {
    for (idx; idx <= n; idx += (idx & -idx)) b[idx] += delta;
  }
};
long long bin(long long l, long long r, long long x, fenwicktree &f) {
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    if (f.sum(mid) <= x)
      l = mid;
    else
      r = mid - 1;
  }
  return l + 1;
}
void solve() {
  cin >> n;
  fenwicktree f(n);
  for (long long i = 1; i <= n; i++) f.add(i, i);
  long long a[200005];
  long long res[200005];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = n - 1; i >= 0; i--) {
    long long x = bin(0, n - 1, a[i], f);
    res[i] = x;
    f.add(x, -x);
  }
  for (long long i = 0; i < n; i++) cout << res[i] << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
