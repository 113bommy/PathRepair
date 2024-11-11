#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000000;
const int MAXN = 200110;
int n, m;
int a[MAXN];
int fib[MAXN];
int rfib[MAXN];
int lazy[2][MAXN * 4];
int tree[2][MAXN * 4];
void pushdown(int id, int pos) {}
void update(int id, int l, int r, int x, int v, int pos) {
  pushdown(id, pos);
  if (l == r)
    tree[id][pos] = (tree[id][pos] + v) % MOD;
  else {
    int mid = (l + r) >> 1;
    if (x <= mid)
      update(id, l, mid, x, v, pos * 2);
    else
      update(id, mid + 1, r, x, v, pos * 2 + 1);
    tree[id][pos] = (tree[id][pos * 2] + tree[id][pos * 2 + 1]) % MOD;
  }
}
void update(int id, int x, int v) { update(id, 1, n, x, v, 1); }
int read(int id, int l, int r, int ql, int qr, int pos) {
  pushdown(id, pos);
  if (ql <= l && r <= qr)
    return tree[id][pos];
  else {
    int mid = (l + r) >> 1;
    int ret = 0;
    if (ql <= mid) ret = read(id, l, mid, ql, qr, pos * 2);
    if (qr > mid) ret = (ret + read(id, mid + 1, r, ql, qr, pos * 2 + 1));
    return ret;
  }
}
int read(int id, int l, int r) { return read(id, 1, n, l, r, 1); }
int main() {
  fib[0] = fib[1] = 1;
  for (int i = 2; i < MAXN; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  rfib[0] = 1;
  rfib[1] = MOD - 1;
  for (int i = 2; i < MAXN; i++)
    rfib[i] = (rfib[i - 2] - rfib[i - 1] + MOD) % MOD;
  memset(lazy, 0, sizeof(lazy));
  memset(tree, 0, sizeof(tree));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(0, i, (long long)a[i] * fib[i - 1] % MOD);
    update(1, i, (long long)a[i] * fib[i] % MOD);
  }
  for (int q = 0; q < m; q++) {
    int typ;
    scanf("%d", &typ);
    if (typ == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      update(0, x, MOD - read(0, x, x));
      update(0, x, (long long)v * fib[x - 1] % MOD);
      update(1, x, MOD - read(1, x, x));
      update(1, x, (long long)v * fib[x] % MOD);
    } else if (typ == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      int sum0 = read(0, l, r);
      int sum1 = read(1, l, r);
      if (l == 1)
        printf("%d\n", sum0);
      else if (l == 2)
        printf("%d\n", (sum1 - sum0 + MOD) % MOD);
      else {
        int ans = (long long)sum1 * rfib[l - 2] % MOD +
                  (long long)sum0 * rfib[l - 1] % MOD;
        ans = ans % MOD;
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
