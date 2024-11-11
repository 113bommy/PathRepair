#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 1e5 + 10, K = 1e5 + 10, Q = 1e5 + 10;
const long long MOD = 998244353;
struct Query {
  int id, l, r, k;
  void rd(int i) {
    id = i;
    scanf("%d%d%d", &l, &r, &k);
    --l;
  }
  bool operator<(const Query &rhs) const { return k < rhs.k; }
} q[Q];
long long fac[N], inv[N], ans[N];
int B, cnt[N], e[N], c[N], n, m, qn;
bool cmp(Query x, Query y) {
  int bx = x.l / B, by = y.l / B;
  if (bx != by) return bx < by;
  return bx & 1 ? x.r > x.r : x.r < y.r;
}
int main() {
  scanf("%d%d%d", &n, &m, &qn);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i) {
    scanf("%d", &e[i]);
    ++cnt[e[i]];
  }
  for (int i = 0; i < n; ++i) q[i].rd(i);
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= 200000; ++i) {
    inv[i] = -inv[MOD % i] * (MOD / i) % MOD;
    while (inv[i] < 0) inv[i] += MOD;
  }
  sort(q, q + qn);
  for (int ql = 0, qr = 0; ql < qn; ql = qr) {
    int k = q[ql].k, l = 0, r = 0;
    long long s = 1;
    for (qr = ql; qr < qn && q[qr].k == k; ++qr)
      ;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
      fac[i] = (1ll * k * m + i) % MOD * fac[i - 1] % MOD;
    for (int i = 1; i <= m; ++i) c[i] = cnt[i] + k;
    B = n / sqrt(qr - ql) + 1;
    sort(q + ql, q + qr, cmp);
    for (int i = ql; i < qr; ++i) {
      while (l > q[i].l) s = s * c[e[--l]]-- % MOD;
      while (r < q[i].r) s = s * c[e[r++]]-- % MOD;
      while (l < q[i].l) s = s * inv[++c[e[l++]]] % MOD;
      while (r > q[i].r) s = s * inv[++c[e[--r]]] % MOD;
      ans[q[i].id] = s * fac[n - r + l] % MOD;
    }
  }
  for (int i = 0; i < qn; ++i) cout << ans[i] << endl;
  return 0;
}
