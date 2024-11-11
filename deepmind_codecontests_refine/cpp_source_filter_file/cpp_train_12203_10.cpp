#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
int n, tot;
int x[N], v[N], p[N];
struct mtrx {
  int f[2][2];
  void clear() { memset(f, 0, sizeof(f)); }
  mtrx operator*(const mtrx a) const {
    mtrx c;
    c.clear();
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          c.f[i][j] = (c.f[i][j] + 1ll * f[i][k] * a.f[k][j]) % mod;
    return c;
  }
} t[N << 1];
void pushup(int k) { t[k] = t[k << 1] * t[k << 1 | 1]; }
void build(int l, int r, int k) {
  if (l == r) {
    t[k].f[0][0] = t[k].f[1][0] = p[l];
    t[k].f[0][1] = t[k].f[1][1] = (mod + 1 - p[l]) % mod;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, k << 1);
  build(mid + 1, r, k << 1 | 1);
  pushup(k);
}
int qp(int x, int k) {
  int res = 1;
  for (; k; k >>= 1, x = 1ll * x * x % mod)
    if (k & 1) res = 1ll * x * res % mod;
  return res;
}
struct data {
  int id, v, s, x, y;
} d[N << 2];
bool cmp(data a, data b) { return 1ll * b.v * a.s < 1ll * a.v * b.s; }
int getspeed(int k, int x, int y) {
  return (x == 0 ? -1 : 1) * v[k - 1] + (y == 1 ? -1 : 1) * v[k];
}
int ans;
mtrx tmp;
void query(int l, int r, int p, int x, int y, int k, int op) {
  if (l == r) {
    if (!op) {
      tmp = t[k];
      t[k].f[x ^ 1][y] = t[k].f[x ^ 1][y ^ 1] = t[k].f[x][y ^ 1] = 0;
    } else {
      t[k] = tmp;
      t[k].f[x][y] = 0;
    }
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid)
    query(l, mid, p, x, y, k << 1, op);
  else
    query(mid + 1, r, p, x, y, k << 1 | 1, op);
  pushup(k);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &x[i], &v[i], &p[i]),
        p[i] = (mod + 1 - 1ll * p[i] * qp(100, mod - 2) % mod) % mod;
  x[0] = -2e9;
  v[0] = 1e9;
  p[0] = 1;
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        if (getspeed(i, j, k) > 0)
          d[++tot] = (data){i, getspeed(i, j, k), x[i] - x[i - 1], j, k};
  build(1, n, 1);
  sort(d + 1, d + tot + 1, cmp);
  for (int i = 1; i <= tot; i++) {
    query(1, n, d[i].id, d[i].x, d[i].y, 1, 0);
    ans = (ans + 1ll * (t[1].f[0][0] + t[1].f[0][1]) * d[i].s % mod *
                     qp(d[i].v, mod - 2)) %
          mod;
    query(1, n, d[i].id, d[i].x, d[i].y, 1, 1);
  }
  printf("%d\n", ans);
  return 0;
}
