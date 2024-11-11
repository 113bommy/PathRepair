#include <bits/stdc++.h>
using namespace std;
const int base = 13331;
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int mod = 65536;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 4e5 + 10, M = 20000010;
const int NN = 3e5 + 10;
inline long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
vector<int> g[N];
int n, m, DFN, dfn[N], rev[N], R[N], c[N];
long long tr[N << 2], lz[N << 2];
void dfs(int u, int f) {
  dfn[u] = ++DFN;
  rev[DFN] = u;
  for (auto v : g[u]) {
    if (v == f) continue;
    dfs(v, u);
  }
  R[u] = DFN;
}
void up(int o) { tr[o] = tr[(o << 1)] | tr[(o << 1 | 1)]; }
void build(int o, int l, int r) {
  if (l == r) {
    tr[o] = 1ll << c[rev[l]];
    return;
  }
  int mid = l + r >> 1;
  build((o << 1), l, mid);
  build((o << 1 | 1), mid + 1, r);
  up(o);
}
void pd(int o, int l, int r) {
  if (lz[o]) {
    tr[(o << 1)] = lz[o];
    tr[(o << 1 | 1)] = lz[o];
    lz[(o << 1)] = lz[o];
    lz[(o << 1 | 1)] = lz[o];
    lz[o] = 0;
  }
}
void upd(int o, int l, int r, int ql, int qr, int col) {
  if (ql <= l && r <= qr) {
    tr[o] = 1ll << col;
    lz[o] = 1ll << col;
    return;
  }
  int mid = l + r >> 1;
  pd(o, l, r);
  if (ql <= mid) upd((o << 1), l, mid, ql, qr, col);
  if (mid < qr) upd((o << 1 | 1), mid + 1, r, ql, qr, col);
  up(o);
}
long long qry(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tr[o];
  int mid = l + r >> 1;
  pd(o, l, r);
  long long res = 0;
  if (ql <= mid) res |= qry((o << 1), l, mid, ql, qr);
  if (mid < qr) res |= qry((o << 1 | 1), mid + 1, r, ql, qr);
  return res;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) c[i] = read() - 1;
  int u, v;
  for (int i = 1; i < n; i++) {
    u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  build(1, 1, n);
  int op, col;
  for (int i = 1; i <= m; i++) {
    op = read();
    if (op == 1) {
      u = read(), col = read() - 1;
      upd(1, 1, n, dfn[u], R[u], col);
    } else {
      u = read();
      long long t = qry(1, 1, n, dfn[u], R[u]);
      int cnt = 0;
      for (int i = 0; i < 61; i++)
        if ((t >> i) & 1ll) ++cnt;
      printf("%d\n", cnt);
    }
  }
  return 0;
}
