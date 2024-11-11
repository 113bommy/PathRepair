#include <bits/stdc++.h>
const int maxn = 100010, maxk = 100010, maxm = 100010, maxq = 100010,
          mod = 119 << 23 | 1;
int n, m, q, e[maxn], cnt[maxm], ans[maxq];
struct Query {
  int id, l, r, k;
  void rd(int i) {
    id = i;
    scanf("%d%d%d", &l, &r, &k);
    --l;
  }
  bool operator<(const Query& q) const { return k < q.k; }
} Q[maxq];
int B;
bool cmp(Query a, Query b) {
  int la = a.l / B, lb = b.l / B;
  if (la != lb) return la < lb;
  return la & 1 ? a.r > b.r : a.r < b.r;
}
int fac[maxn + maxk], iv[maxn + maxk];
long long inv(int a, int p = mod) {
  return a == 1 ? 1 : (1 + p * (a - inv(p % a, a))) / a % p;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%d", e + i), --e[i];
  for (int i = 0; i < q; i++) Q[i].rd(i);
  std::sort(Q, Q + q);
  int lim = n + Q[q - 1].k;
  for (int i = *fac = 1; i <= lim; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  iv[lim] = inv(fac[lim]);
  for (int i = lim; i; i--) {
    iv[i - 1] = 1ll * iv[i] * i % mod;
    iv[i] = 1ll * fac[i - 1] * iv[i] % mod;
  }
  for (int ql = 0, qr = 0; ql < q; ql = qr) {
    int k = Q[ql].k;
    while (qr < q && Q[qr].k == k) qr++;
    for (int j = *fac = 1; j <= n; j++)
      fac[j] = (1ll * k * m + j) % mod * fac[j - 1] % mod;
    B = n / sqrt(qr - ql) + 1;
    std::sort(Q + ql, Q + qr, cmp);
    int l = Q[ql].l, r = Q[ql].l, s = 1;
    for (int i = 0; i < m; i++) cnt[i] = k;
    for (int i = 0; i < n; i++) cnt[e[i]]++;
    for (int i = ql; i < qr; i++) {
      while (l > Q[i].l) s = 1ll * s * cnt[e[--l]]-- % mod;
      while (r < Q[i].r) s = 1ll * s * cnt[e[r++]]-- % mod;
      while (l < Q[i].l) s = 1ll * s * iv[++cnt[e[l++]]] % mod;
      while (r > Q[i].r) s = 1ll * s * iv[++cnt[e[--r]]] % mod;
      ans[Q[i].id] = 1ll * s * fac[n - r + l] % mod;
    }
  }
  for (int i = 0; i < 10; i++) printf("%d\n", ans[i]);
}
