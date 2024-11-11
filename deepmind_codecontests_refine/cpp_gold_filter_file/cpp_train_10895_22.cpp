#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const int sz = 100010;
int a[sz];
struct ele {
  int l, x, id;
} c[sz];
int ans[sz];
long long fast(long long x, long long a) {
  if (x == 0) return 1;
  long long y = fast(x / 2, a);
  y *= y;
  y %= mod;
  if (x & 1) return (a * y) % mod;
  return y;
}
bool cmp(ele p, ele q) { return p.l < q.l; }
int ins[(1 << 20)], S[(1 << 20)];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int k = 1; k <= n; k++) scanf("%d", &a[k]);
  for (int k = 1; k <= q; k++) {
    scanf("%d%d", &c[k].l, &c[k].x);
    c[k].id = k;
  }
  std::sort(c + 1, c + q + 1, cmp);
  int cnt = 0, in = 0;
  S[0] = 0;
  ins[0] = 1;
  for (int k = 1; k <= q; k++) {
    while (in < c[k].l) {
      in++;
      if (ins[a[in]]) continue;
      for (int i = 0; i < (1 << cnt); i++) {
        int x = S[i] ^ a[in];
        ins[x] = 1;
        S[(1 << cnt) + i] = x;
      }
      cnt++;
    }
    if (ins[c[k].x]) {
      ans[c[k].id] = fast((long long)c[k].l - cnt, 2);
    } else
      ans[c[k].id] = 0;
  }
  for (int k = 1; k <= q; k++) printf("%d\n", ans[k]);
}
