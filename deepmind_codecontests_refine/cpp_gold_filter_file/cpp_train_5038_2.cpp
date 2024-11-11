#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int mod = 1e9;
int f[maxn];
int n;
int pos;
struct segtree {
  int sum[maxn << 2][2];
  inline void pushUp(int l, int r, int rt) {
    int m = (l + r) >> 1;
    sum[rt][0] = (sum[rt << 1][0] + shift(m - l + 1, rt << 1 | 1)) % mod;
    sum[rt][1] = (sum[rt << 1][1] + shift(m - l + 2, rt << 1 | 1)) % mod;
  }
  void build(int l = 1, int r = n, int rt = 1) {
    if (l == r) {
      scanf("%d", &sum[rt][0]);
      sum[rt][1] = sum[rt][0];
      return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushUp(l, r, rt);
  }
  void insert(int p, int v, int l = 1, int r = n, int rt = 1) {
    if (l == r) {
      sum[rt][0] = sum[rt][1] = v;
      return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
      insert(p, v, l, m, rt << 1);
    else
      insert(p, v, m + 1, r, rt << 1 | 1);
    pushUp(l, r, rt);
  }
  inline int shift(int x, int rt) {
    if (x <= 1) return sum[rt][x];
    return ((long long)f[x - 1] * sum[rt][1] % mod +
            (long long)f[x - 2] * sum[rt][0] % mod) %
           mod;
  }
  int query(int L, int R, int l = 1, int r = n, int rt = 1) {
    if (L <= l && r <= R) {
      int len = r - l + 1;
      int ret = shift(pos, rt);
      pos += len;
      return ret;
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = query(L, R, l, m, rt << 1);
    if (R > m) ret = (ret + query(L, R, m + 1, r, rt << 1 | 1)) % mod;
    return ret;
  }
  void print(int l = 1, int r = n, int rt = 1) {
    printf("rt = %d~ ~~%d ", rt, sum[rt][0]);
    if (l == r) {
      return;
    }
    int m = (l + r) >> 1;
    print(l, m, rt << 1);
    print(m + 1, r, rt << 1 | 1);
  }
} T;
int main() {
  int i, j;
  f[0] = f[1] = 1;
  for (i = 2; i < maxn; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  int m;
  scanf("%d%d", &n, &m);
  T.build();
  while (m--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      T.insert(x, y);
    else if (op == 2) {
      pos = 0;
      printf("%d\n", T.query(x, y));
    }
  }
  return 0;
}
