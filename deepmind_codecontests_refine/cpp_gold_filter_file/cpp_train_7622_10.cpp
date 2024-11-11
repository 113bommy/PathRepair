#include <bits/stdc++.h>
using namespace std;
const int N = 300100;
struct node {
  int pos, val;
} q[N];
struct Tree {
  int l, r, sz;
  long long sum, suml, sumr;
} t[N << 3];
int n, m, cnt, a[N], cp[N << 1], mp[N << 1], qpow[N], inv[N];
int read() {
  int aa = 0, bb = 1;
  char cc = getchar();
  while (cc > '9' || cc < '0') {
    if (cc == '-') bb = -1;
    cc = getchar();
  }
  while (cc >= '0' && cc <= '9') {
    aa = (aa << 3) + (aa << 1) + (cc ^ '0');
    cc = getchar();
  }
  return aa * bb;
}
int quick(int x, int p) {
  int as = 1;
  while (p) {
    if (p & 1) as = 1ll * as * x % 1000000007;
    x = 1ll * x * x % 1000000007;
    p >>= 1;
  }
  return as;
}
void update(int x) {
  t[x].sz = t[x << 1].sz + t[x << 1 | 1].sz;
  t[x].sum = (t[x << 1].sum + t[x << 1 | 1].sum +
              t[x << 1].suml * t[x << 1 | 1].sumr % 1000000007 *
                  inv[t[x << 1].sz] % 1000000007) %
             1000000007;
  t[x].suml =
      (t[x << 1].suml + t[x << 1 | 1].suml * qpow[t[x << 1].sz] % 1000000007) %
      1000000007;
  t[x].sumr =
      (t[x << 1].sumr + t[x << 1 | 1].sumr * inv[t[x << 1].sz] % 1000000007) %
      1000000007;
}
void build(int x, int l, int r) {
  t[x].l = l;
  t[x].r = r;
  if (l == r) return;
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
}
void insert(int x, int p, int val) {
  if (t[x].l == t[x].r) {
    t[x].sz += val;
    if (t[x].sz)
      t[x].sum = 0, t[x].suml = cp[p],
      t[x].sumr = 1ll * cp[p] * inv[1] % 1000000007;
    else
      t[x].sum = 0, t[x].suml = 0, t[x].sumr = 0;
    return;
  }
  int mid = t[x].l + t[x].r >> 1;
  if (p <= mid)
    insert(x << 1, p, val);
  else
    insert(x << 1 | 1, p, val);
  update(x);
}
int main() {
  n = read();
  qpow[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= n; i++)
    a[i] = read(), cp[++cnt] = a[i], qpow[i] = 2ll * qpow[i - 1] % 1000000007,
    inv[i] = quick(qpow[i], 1000000007 - 2);
  m = read();
  for (int i = 1; i <= m; i++) {
    q[i].pos = read();
    q[i].val = read();
    cp[++cnt] = q[i].val;
  }
  sort(cp + 1, cp + cnt + 1);
  build(1, 1, cnt);
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(cp + 1, cp + cnt + 1, a[i]) - cp, mp[a[i]]++,
    a[i] += mp[a[i]] - 1;
  for (int i = 1; i <= m; i++)
    q[i].val = lower_bound(cp + 1, cp + cnt + 1, q[i].val) - cp, mp[q[i].val]++,
    q[i].val += mp[q[i].val] - 1;
  for (int i = 1; i <= n; i++) insert(1, a[i], 1);
  printf("%lld\n", t[1].sum);
  for (int i = 1; i <= m; i++) {
    insert(1, a[q[i].pos], -1);
    a[q[i].pos] = q[i].val;
    insert(1, a[q[i].pos], 1);
    printf("%lld\n", t[1].sum);
  }
  return 0;
}
