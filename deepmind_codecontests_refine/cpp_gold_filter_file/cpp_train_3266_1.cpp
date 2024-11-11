#include <bits/stdc++.h>
using namespace std;
const int NR = 1e5 + 10;
const int mod = 1e9 + 7;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m;
int a[NR];
int C[10][10], power[NR][10];
int sum[NR][10];
struct Segment {
  int tr[NR * 4][6], lz[NR * 4];
  void init() { memset(lz, -1, sizeof(lz)); }
  void update(int rt) {
    for (int i = 0; i <= 5; i++)
      tr[rt][i] = (tr[(rt << 1)][i] + tr[(rt << 1 | 1)][i]) % mod;
  }
  void build(int rt, int l, int r) {
    if (l == r) {
      for (int i = 0; i <= 5; i++) tr[rt][i] = 1ll * power[l][i] * a[l] % mod;
      return;
    }
    int mid = (l + r) >> 1;
    build((rt << 1), l, mid), build((rt << 1 | 1), mid + 1, r);
    update(rt);
  }
  void doit(int rt, int l, int r, int v) {
    for (int i = 0; i <= 5; i++) {
      tr[rt][i] = 1ll * (sum[r][i] - sum[l - 1][i]) * v % mod;
    }
    lz[rt] = v;
  }
  void push_down(int rt, int l, int r) {
    if (lz[rt] != -1) {
      int mid = (l + r) >> 1;
      doit((rt << 1), l, mid, lz[rt]), doit((rt << 1 | 1), mid + 1, r, lz[rt]);
      lz[rt] = -1;
    }
  }
  void change(int rt, int l, int r, int L, int R, int v) {
    if (l == L && r == R) {
      doit(rt, l, r, v);
      return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r);
    if (R <= mid)
      change((rt << 1), l, mid, L, R, v);
    else if (L > mid)
      change((rt << 1 | 1), mid + 1, r, L, R, v);
    else
      change((rt << 1), l, mid, L, mid, v),
          change((rt << 1 | 1), mid + 1, r, mid + 1, R, v);
    update(rt);
  }
  int query(int rt, int l, int r, int L, int R, int v) {
    if (l == L && r == R) return tr[rt][v];
    int mid = (l + r) >> 1;
    push_down(rt, l, r);
    if (R <= mid)
      return query((rt << 1), l, mid, L, R, v);
    else if (L > mid)
      return query((rt << 1 | 1), mid + 1, r, L, R, v);
    else
      return (query((rt << 1), l, mid, L, mid, v) +
              query((rt << 1 | 1), mid + 1, r, mid + 1, R, v)) %
             mod;
  }
} T;
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 0; i <= n; i++) {
    power[i][0] = 1;
    for (int j = 1; j <= 5; j++) power[i][j] = 1ll * power[i][j - 1] * i % mod;
    if (!i) {
      for (int j = 0; j <= 5; j++) sum[i][j] = power[i][j];
      continue;
    }
    for (int j = 0; j <= 5; j++)
      sum[i][j] = (sum[i - 1][j] + power[i][j]) % mod;
  }
  C[0][0] = 1;
  for (int i = 1; i <= 5; i++) C[i][0] = C[i][i] = 1;
  for (int i = 2; i <= 5; i++)
    for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  T.init();
  T.build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    char op;
    scanf(" %c", &op);
    if (op == '=') {
      int l = read(), r = read(), x = read();
      T.change(1, 1, n, l, r, x);
    } else {
      int l = read(), r = read(), x = read();
      int ans = 0;
      for (int j = 0; j <= x; j++)
        ans = (ans + 1ll * C[x][j] * T.query(1, 1, n, l, r, j) % mod *
                         power[l - 1][x - j] % mod * ((x - j & 1) ? -1 : 1)) %
              mod;
      printf("%d\n", (ans + mod) % mod);
    }
  }
  return 0;
}
