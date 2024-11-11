#include <bits/stdc++.h>
using namespace std;
namespace flyinthesky {
const long long MAXN = 200000 + 5;
long long n, k, a[MAXN], b[MAXN], cnt[MAXN];
bool chk(long long x) {
  memset(cnt, 0, sizeof cnt);
  long long tot = k - 1;
  for (long long i = 1; i <= n; ++i) {
    if (!b[i]) continue;
    long long sum = a[i];
    while (sum <= (k - 1) * b[i]) {
      if (sum / b[i] + 1 <= k) ++cnt[sum / b[i] + 1];
      if (tot < 0) return false;
      --tot;
      sum += x;
    }
  }
  for (long long i = 1; i <= k; ++i) {
    cnt[i] += cnt[i - 1];
    if (cnt[i] > i) return false;
  }
  return true;
}
void clean() {}
int solve() {
  clean();
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &b[i]);
  long long l = 0, r = 1e13, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (chk(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}
}  // namespace flyinthesky
int main() {
  flyinthesky::solve();
  return 0;
}
