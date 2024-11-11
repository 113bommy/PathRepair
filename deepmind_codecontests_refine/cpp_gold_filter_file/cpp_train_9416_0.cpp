#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500000 + 111;
const long long ef = (long long)1 << 45;
long long n, m, w, minn;
long long a[maxn], b[maxn];
int solve(long long k) {
  memset(b, 0, sizeof(b));
  long long temp = 0, cost = 0;
  for (long long i = 1; i <= n; i += 1) {
    temp += b[i];
    long long tmp = k - (a[i] + temp);
    if (tmp > 0) {
      b[i + 1] += tmp;
      b[i + w] -= tmp;
      cost += tmp;
    }
  }
  return cost <= m;
}
void solve() {
  long long l = 0, r = ef, ans = minn;
  while (l <= r) {
    long long m = (l + r) >> 1;
    if (solve(m)) {
      ans = max(ans, m);
      l = m + 1;
    } else
      r = m - 1;
  }
  cout << ans << endl;
}
int main() {
  while (~scanf("%I64d%I64d%I64d", &n, &m, &w)) {
    minn = ef;
    for (long long i = 1; i <= n; i += 1) {
      scanf("%I64d", &a[i]);
      minn = min(minn, a[i]);
    }
    solve();
  }
  return 0;
}
