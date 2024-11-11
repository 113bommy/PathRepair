#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 5;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int n, x[N], v[N], tot;
long long p[N], inv, ans;
long long qp(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * x % mod;
    k >>= 1, x = x * x % mod;
  }
  return res;
}
struct mat {
  long long m[2][2];
  void clear() { memset(m, 0, sizeof(m)); }
} t[N << 2], a[N];
mat operator*(mat a, mat b) {
  mat tmp;
  tmp.clear();
  for (register int i = 0; i <= 1; i++)
    for (register int j = 0; j <= 1; j++)
      for (register int k = 0; k <= 1; k++)
        (tmp.m[i][j] += a.m[i][k] * b.m[k][j] % mod) %= mod;
  return tmp;
}
struct opt {
  int u, v, pu, pv;
  long long dx, dv;
  opt() {}
  opt(int uu, int vv, int p_u, int p_v, int d_x, int d_v) {
    u = uu, v = vv, pu = p_u, pv = p_v, dx = d_x, dv = d_v;
  }
} P[N << 2];
bool operator<(opt x, opt y) { return x.dx * y.dv <= y.dx * x.dv; }
void ins(int o, int l, int r, int x) {
  if (l == r) {
    t[o] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    ins(o << 1, l, mid, x);
  else
    ins(o << 1 | 1, mid + 1, r, x);
  t[o] = t[o << 1] * t[o << 1 | 1];
}
mat query(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[o];
  int mid = (l + r) >> 1;
  if (x > mid) return query(o << 1 | 1, mid + 1, r, x, y);
  if (y <= mid) return query(o << 1, l, mid, x, y);
  return query(o << 1, l, mid, x, y) * query(o << 1 | 1, mid + 1, r, x, y);
}
int main() {
  inv = qp(100, mod - 2);
  n = read();
  for (register int i = 1; i <= n; i++) {
    x[i] = read(), v[i] = read(), p[i] = read();
    p[i] = p[i] * inv % mod;
    p[i] = (1 - p[i] + mod) % mod;
    if (i == 1) {
      a[i].m[0][0] = p[i];
      a[i].m[0][1] = (1 - p[i] + mod) % mod;
      ins(1, 1, n, i);
    } else {
      a[i].m[0][0] = a[i].m[1][0] = p[i];
      a[i].m[0][1] = a[i].m[1][1] = (1 - p[i] + mod) % mod;
      ins(1, 1, n, i);
      if (v[i] - v[i - 1] > 0)
        P[++tot] = opt(i - 1, i, 0, 0, x[i] - x[i - 1], v[i] - v[i - 1]);
      if (v[i - 1] - v[i] > 0)
        P[++tot] = opt(i - 1, i, 1, 1, x[i] - x[i - 1], v[i - 1] - v[i]);
      if (v[i - 1] + v[i] > 0)
        P[++tot] = opt(i - 1, i, 1, 0, x[i] - x[i - 1], v[i - 1] + v[i]);
    }
  }
  sort(P + 1, P + 1 + tot);
  for (register int i = 1; i <= tot; i++) {
    int l = P[i].u, r = P[i].v;
    long long ret = P[i].dx * qp(P[i].dv, mod - 2) % mod;
    mat tmp;
    tmp = query(1, 1, n, 1, l);
    ret = ret * (tmp.m[0][P[i].pu] + tmp.m[1][P[i].pu]) % mod;
    ret = ret * a[r].m[P[i].pu][P[i].pv] % mod;
    if (r != n) {
      tmp = query(1, 1, n, r + 1, n);
      ret = ret * (tmp.m[P[i].pv][0] + tmp.m[P[i].pv][1]) % mod;
    }
    (ans += ret) %= mod;
    a[r].m[P[i].pu][P[i].pv] = 0;
    ins(1, 1, n, r);
  }
  printf("%lld", ans);
}
