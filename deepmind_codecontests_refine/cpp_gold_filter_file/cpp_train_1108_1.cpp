#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 123;
const int K = (int)500;
const int maxn = (int)2e9;
const int mod = (int)1e9 + 7;
const long long inf = 1ll * 1e18 + 1e9;
int n, m;
long long k, a[N], b[N], sum[N];
bool check(long long x, long long kk) {
  for (int i = 0; i <= n; ++i) {
    sum[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] += sum[i - 1];
    if (a[i] + sum[i] >= x) continue;
    long long len = x - (a[i] + sum[i]);
    kk -= len;
    if (kk < 0) return false;
    sum[i] += len;
    sum[min(n + 1, i + m + m + 1)] -= len;
  }
  return true;
}
inline void solve() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    b[i] = b[i - 1] + a[i];
  }
  long long ok = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = b[min(n, i + m)] - b[max(0, i - m - 1)];
    ok = min(ok, a[i]);
  }
  long long l = ok, r = 1ll * 2e18;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid, k)) {
      ok = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("%lld", ok);
}
int main() {
  int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
