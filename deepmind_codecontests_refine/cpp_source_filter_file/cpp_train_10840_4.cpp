#include <bits/stdc++.h>
using namespace std;
int d, m, n;
int gen[20];
int b[30000];
long long l, r;
struct Info {
  long long len, ans;
  bitset<30000 + 1> p, s;
} dp[15][60];
long long pw[15];
void merge(Info &c, Info &a, Info &b) {
  if (a.len == 0) {
    c = b;
    return;
  }
  c.ans = a.ans + b.ans;
  for (int i = max(n - a.len, 1ll); i <= b.len && i < n; ++i)
    c.ans += (a.s[i] & b.p[i]);
  for (int i = 1; i < n; ++i)
    c.p[i] = a.p[i] & (i - a.len > 0 ? b.p[i - a.len] : 1);
  for (int i = 1; i < n; ++i)
    c.s[i] = b.s[i] & (i + b.len < n ? a.s[i + b.len] : 1);
  c.len = a.len + b.len;
}
long long calc(long long r) {
  if (r <= 0) return 0;
  static Info res;
  res.len = 0;
  res.ans = 0;
  long long p = 1, w = 0;
  for (; p <= r; p *= d, ++w)
    ;
  --w;
  int v = 0;
  for (; w >= 0; --w) {
    for (int i = 0; i < r / pw[w]; ++i)
      merge(res, res, dp[w][(v + gen[i]) % m]);
    v = (v + gen[r / pw[w]]) % m;
    r %= pw[w];
  }
  return res.ans;
}
int main() {
  scanf("%d%d", &d, &m);
  for (int i = 0; i < d; ++i) scanf("%d", &gen[i]);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  scanf("%lld%lld", &l, &r);
  if (r - l + 1 < n) {
    printf("0\n");
    return 0;
  }
  for (int v = 0; v < m; ++v) {
    dp[0][v].len = 1;
    if (n == 1) dp[0][v].ans = (b[0] >= v);
    for (int i = 1; i < n; ++i)
      if (b[n - i] >= v) dp[0][v].p[i] = 1;
    for (int i = 1; i < n; ++i)
      if (b[i - 1] >= v) dp[0][v].s[n - i] = 1;
  }
  pw[0] = 1;
  long long p = d;
  for (int i = 1; p <= r; ++i, p *= d) {
    pw[i] = p;
    for (int v = 0; v < m; ++v) {
      dp[i][v] = dp[i - 1][v];
      for (int j = 1; j < d; ++j)
        merge(dp[i][v], dp[i][v], dp[i - 1][(v + gen[j]) % m]);
    }
  }
  printf("%lld\n", calc(r) - calc(l + n - 2));
  return 0;
}
