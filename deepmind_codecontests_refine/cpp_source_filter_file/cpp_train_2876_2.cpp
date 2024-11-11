#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, mod = 1e9 + 7;
int n, q, pre[N], fa[N];
long long a[N], bw[N], sum[N], psu[N], po2[N], ans[N];
struct qr {
  int l, r, i;
  bool operator<(const qr &o) const { return r == o.r ? l > o.l : r < o.r; }
} b[N];
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
  fa[x] = y, pre[y] = pre[x];
  if (x - pre[x] > 30 || (psu[y] << (x - pre[x])) + psu[x] > mod) {
    psu[y] = mod;
  } else {
    psu[y] = (psu[y] << (x - pre[x])) + psu[x];
  }
}
long long querysum(int l, int r) {
  return (bw[l] - bw[r + 1] * po2[r - l + 1] % mod + mod) % mod;
}
void insert(int i) {
  for (; pre[i] && psu[i] >= 0; merge(pre[i], i))
    ;
  sum[i] = (sum[pre[i]] + (querysum(pre[i] + 1, i) << 1)) % mod;
}
long long query(int l, int r) {
  int x = get(l);
  return (sum[r] - sum[x] + querysum(l, x) + mod) % mod;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    psu[i] = a[i], pre[i] = i - 1, fa[i] = i;
  }
  po2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    po2[i] = po2[i - 1] * 2 % mod;
  }
  bw[n] = a[n];
  for (int i = n - 1; i; --i) {
    bw[i] = (bw[i + 1] * 2 + a[i] + mod) % mod;
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &b[i].l, &b[i].r);
    b[i].i = i;
  }
  sort(b + 1, b + q + 1);
  for (int i = 1, las = 0; i <= q; ++i) {
    for (int j = las + 1; j <= b[i].r; ++j) {
      insert(j);
    }
    las = b[i].r;
    ans[b[i].i] = query(b[i].l, b[i].r);
  }
  for (int i = 1; i <= q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
