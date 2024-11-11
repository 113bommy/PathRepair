#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
long long n, m, A, D, cf;
long long d[N], ans, pre, lc, len;
int main() {
  scanf("%lld%lld%lld%lld", &n, &m, &A, &D);
  cf = D / A + 1;
  for (int i = 1; i <= m; i++) scanf("%lld", &d[i]);
  for (int i = 1; i <= m; i++) {
    if (d[i] <= pre) break;
    lc = ((d[i] / A < n) ? (d[i] / A) : (n));
    len = lc - ((pre / A < n) ? (pre / A) : (n));
    ans += (len + cf - 1) / cf;
    long long ok;
    if (len % cf)
      ok = (len % cf);
    else
      ok = cf;
    if (len) pre = A * (lc - ok + 1) + D;
    if (d[i] > pre) pre = d[i] + D, ans++;
  }
  len = n - ((pre / A < n) ? (pre / A) : (n));
  ans += (len + cf - 1) / cf;
  printf("%lld\n", ans);
  return 0;
}
