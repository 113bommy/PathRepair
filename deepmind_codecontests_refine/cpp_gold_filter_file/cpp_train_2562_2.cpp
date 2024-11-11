#include <bits/stdc++.h>
struct heap {
  int d, f, t, v;
  bool operator<(const heap m) const {
    if (d != m.d) return d < m.d;
    if (v != m.v) return v < m.v;
    return t < m.t;
  }
} a[101000], b[101000];
int as = 0, bs = 1, n, m, k;
const int N = 1010000;
const long long inf = 1e13 + 7;
long long dp1[N], dp2[N], now;
long long v1[N], v2[N], sum;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    heap c;
    scanf("%d %d %d %d", &c.d, &c.f, &c.t, &c.v);
    if (c.f)
      a[++as] = c;
    else
      b[++bs] = c;
  }
  std::sort(a + 1, a + 1 + as);
  std::sort(b + 1, b + 1 + bs);
  memset(v1, 0x3f, sizeof(v1));
  memset(v2, 0x3f, sizeof(v2));
  memset(dp1, 0x3f, sizeof(dp1));
  memset(dp2, 0x3f, sizeof(dp2));
  for (int i = 1; i <= as; ++i) {
    if (v1[a[i].f] > inf) {
      now++;
      v1[a[i].f] = a[i].v;
      sum += a[i].v;
    } else if (v1[a[i].f] > a[i].v) {
      sum -= v1[a[i].f] - a[i].v;
      v1[a[i].f] = a[i].v;
    }
    if (now == n) {
      dp1[a[i].d] = std::min(dp1[a[i].d], sum);
    }
  }
  sum = now = 0;
  int Mx = b[bs].d;
  for (int i = bs; i >= 1; --i) {
    if (v2[b[i].t] > inf) {
      now++;
      v2[b[i].t] = b[i].v;
      sum += b[i].v;
    } else if (v2[b[i].t] > b[i].v) {
      sum -= v2[b[i].t] - b[i].v;
      v2[b[i].t] = b[i].v;
    }
    if (now == n) {
      dp2[b[i].d] = std::min(dp2[b[i].d], sum);
    }
  }
  for (int i = 2; i <= Mx; ++i) dp1[i] = std::min(dp1[i], dp1[i - 1]);
  for (int i = Mx; i; --i) dp2[i] = std::min(dp2[i], dp2[i + 1]);
  long long ans = 1e18;
  for (int i = 1; i + 1 + k <= Mx; ++i) {
    ans = std::min(ans, dp1[i] + dp2[i + 1 + k]);
  }
  if (ans >= 1e14) ans = -1;
  printf("%lld", ans);
}
