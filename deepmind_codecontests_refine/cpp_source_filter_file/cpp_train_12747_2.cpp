#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const long long mod = 1e9 + 9;
long long f[N], a[N], sum[N * 4], f1[N * 4], f2[N * 4];
long long val(long long a, long long b, int pos) {
  return pos == 1 ? 1ll * a : 1ll * (b * f[pos - 1] + a * f[pos - 2]) % mod;
}
long long pre(long long a, long long b, int pos) {
  return (val(a, b, pos + 2) - b + mod) % mod;
}
void build(int l, int r, int root) {
  if (l == r) {
    sum[root] = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, root << 1);
  build(mid + 1, r, root << 1 | 1);
  sum[root] = (sum[root << 1] + sum[root << 1 | 1]) % mod;
}
void push_down(int l, int r, int root) {
  int mid = l + r >> 1;
  if (!f1[root] || !f2[root]) return;
  sum[root << 1] =
      (sum[root << 1] + pre(f1[root], f2[root], mid - l + 1)) % mod;
  sum[root << 1 | 1] =
      (sum[root << 1 | 1] + pre(f1[root], f2[root], r - l + 1) -
       pre(f1[root], f2[root], mid - l + 1) + mod) %
      mod;
  f1[root << 1] = (f1[root << 1] + f1[root]) % mod;
  f1[root << 1 | 1] =
      (f1[root << 1 | 1] + val(f1[root], f2[root], mid - l + 2)) % mod;
  f2[root << 1] = (f2[root << 1] + f2[root]) % mod;
  f2[root << 1 | 1] =
      (f2[root << 1 | 1] + val(f1[root], f2[root], mid - l + 3)) % mod;
  f1[root] = f2[root] = 0;
}
void update(int l, int r, int root, int ql, int qr) {
  if (l >= ql && r <= qr) {
    f1[root] = (f1[root] + f[l - ql + 1]) % mod;
    f2[root] = (f2[root] + f[l - ql + 2]) % mod;
    sum[root] =
        (sum[root] + pre(f[l - ql + 1], f[l - ql + 2], r - l + 1)) % mod;
    return;
  }
  int mid = l + r >> 1;
  push_down(l, r, root);
  if (mid >= ql) update(l, mid, root << 1, ql, qr);
  if (mid < qr) update(mid + 1, r, root << 1 | 1, ql, qr);
  sum[root] = (sum[root << 1] + sum[root << 1 | 1]);
}
long long query(int l, int r, int root, int ql, int qr) {
  if (l >= ql && r <= qr) return sum[root];
  int mid = l + r >> 1;
  long long ans = 0;
  push_down(l, r, root);
  if (mid >= ql) ans = query(l, mid, root << 1, ql, qr);
  if (mid < qr) ans = (ans + query(mid + 1, r, root << 1 | 1, ql, qr)) % mod;
  return ans;
}
int main() {
  f[1] = f[2] = 1;
  for (int i = 3; i < N; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, n, 1);
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1)
      update(1, n, 1, l, r);
    else
      printf("%lld\n", query(1, n, 1, l, r));
  }
  return 0;
}
