#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, mod = 1e9 + 7;
int n, q, x, a[N], b[N], f[N], d[N], g[N], dp[N], t[N], ans;
multiset<int> s;
void M(int x, int y) {
  for (; x <= 2 * n; x += x & -x) (t[x] += y) %= mod;
}
int Q(int x) {
  int ret = 0;
  for (; x; x -= x & -x) (ret += t[x]) %= mod;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]), f[i] = i;
  sort(f + 1, f + n + 1, [&](int x, int y) { return a[x] < a[y]; });
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d", &x), d[x] = 1, s.insert(b[x]);
  for (int i = 1; i <= n; i++) {
    x = f[i];
    g[x] = s.size() && b[x] <= *s.rbegin();
    if (d[x]) s.erase(s.find(b[x]));
  }
  for (int i = 1; i <= n; i++)
    x = f[i], M(b[x], dp[x] = (mod + g[x] + Q(2 * n) - Q(b[x])) % mod),
    (ans += dp[x]) %= mod;
  printf("%d\n", ans);
  return 0;
}
