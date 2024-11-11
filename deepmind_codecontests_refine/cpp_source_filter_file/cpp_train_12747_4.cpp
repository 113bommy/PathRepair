#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
const int MOD = 1000000007;
int s[N * 4], f[N], a[N], taga[N * 4], tagb[N * 4];
void update(int x) { s[x] = (s[x << 1] + s[x << 1 | 1]) % MOD; }
void push(int x, int a, int b, int n) {
  taga[x] = (taga[x] + a) % MOD;
  tagb[x] = (tagb[x] + b) % MOD;
  s[x] = ((long long)f[n] * a + (long long)(f[n + 1] - 1) * b + s[x]) % MOD;
}
void pushdown(int x, int l, int r) {
  if (taga[x] > 0 || tagb[x] > 0) {
    int mid = (l + r) >> 1, a = taga[x], b = tagb[x], C = mid - l,
        A = ((long long)f[C] * a + (long long)f[C + 1] * b) % MOD,
        B = ((long long)f[C + 1] * a + (long long)f[C + 2] * b) % MOD;
    push(x << 1, a, b, mid - l + 1), push(x << 1 | 1, A, B, r - mid);
    taga[x] = tagb[x] = 0;
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    s[x] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  update(x);
}
void change(int x, int l, int r, int p, int q) {
  if (l > q || r < p) return;
  if (l >= p && r <= q) {
    push(x, f[l - p + 1], f[l - p + 2], r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(x, l, r);
  change(x << 1, l, mid, p, q);
  change(x << 1 | 1, mid + 1, r, p, q);
  update(x);
}
int query(int x, int l, int r, int p, int q) {
  if (l > q || r < p) return 0;
  if (l >= p && r <= q) return s[x];
  int mid = (l + r) >> 1;
  pushdown(x, l, r);
  return (query(x << 1, l, mid, p, q) + query(x << 1 | 1, mid + 1, r, p, q)) %
         MOD;
}
void prints(int x, int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  pushdown(x, l, r);
  prints(x << 1, l, mid);
  prints(x << 1 | 1, mid + 1, r);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  f[0] = 0, f[1] = 1;
  for (int i = 2; i <= n + 2; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1)
      change(1, 1, n, l, r);
    else
      printf("%d\n", query(1, 1, n, l, r));
  }
}
