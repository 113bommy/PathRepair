#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 4e5 + 10;
long long n, Rt, ans, inv[N];
int r[22], sz[N], lim, son[N], fa[N];
vector<int> g[N];
vector<long long> a[N], f[N];
void Add(long long &x, long long y) { x = (x + y) % mod; }
long long add(long long x, long long y) { return (x + y) % mod; }
void Mul(long long &x, long long y) { x = x * y % mod; }
long long mul(long long x, long long y) { return x * y % mod; }
void Sub(long long &x, long long y) { x = (x - y + mod) % mod; }
long long sub(long long x, long long y) { return (x - y + mod) % mod; }
long long qpow(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ret, a);
  return ret;
}
void TNT(vector<long long> &a, int op) {
  for (int i = 1; i <= lim - 1; i++)
    if (i < r[i]) swap(a[i], a[r[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    long long W = qpow(op == 1 ? 3 : (mod + 1) / 3, (mod - 1) / (mid << 1));
    for (int j = 0; j < lim; j += (mid << 1)) {
      long long w = 1;
      for (int k = 0; k < mid; ++k, Mul(w, W)) {
        long long x = a[j + k], y = mul(w, a[j + k + mid]);
        a[j + k] = add(x, y), a[j + k + mid] = sub(x, y);
      }
    }
  }
  if (op == -1) {
    long long Inv = qpow(lim, mod - 2);
    for (int i = 0; i <= lim - 1; i++) Mul(a[i], Inv);
  }
}
vector<long long> operator*(vector<long long> a, vector<long long> b) {
  int t = a.size() + b.size() - 1;
  lim = 1;
  while (lim <= t) lim <<= 1;
  for (int i = 0; i <= lim - 1; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  a.resize(lim), b.resize(lim);
  TNT(a, 1), TNT(b, 1);
  for (int i = 0; i <= lim - 1; i++) Mul(a[i], b[i]);
  TNT(a, -1);
  a.resize(t);
  return a;
}
vector<long long> operator+(vector<long long> a, vector<long long> b) {
  int t = max(a.size(), b.size());
  a.resize(t), b.resize(t);
  for (int i = 0; i <= t - 1; i++) Add(a[i], b[i]);
  return a;
}
void dfs(int x, int fat) {
  sz[x] = 1;
  fa[x] = fat;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (y == fat) continue;
    dfs(y, x);
    sz[x] += sz[y];
    if (sz[son[x]] < sz[y]) son[x] = y;
  }
}
void calc(int l, int r, vector<long long> &F, vector<long long> &G) {
  if (l == r) {
    F = G = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  vector<long long> Fl, Fr, Gl, Gr;
  calc(l, mid, Fl, Gl), calc(mid + 1, r, Fr, Gr);
  F = Fl * Fr;
  G = Gl + Fl * Gr;
}
vector<long long> solve(int u) {
  for (int x = u; x; x = son[x]) {
    for (int i = 0; i < g[x].size(); i++)
      if (g[x][i] != fa[x] && g[x][i] != son[x]) f[x] = solve(g[x][i]);
    if (!f[x].size()) f[x].push_back(0);
    ++f[x][0];
    f[x].insert(f[x].begin(), 0);
  }
  int top = 0;
  for (int x = u; x; x = son[x]) swap(a[++top], f[x]);
  vector<long long> F, G;
  calc(1, top, F, G);
  return G;
}
int main() {
  cin >> n >> Rt;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
  int x, y;
  for (int i = 1; i <= n - 1; i++)
    scanf("%d%d", &x, &y), g[x].push_back(y), g[y].push_back(x);
  dfs(1, 0);
  vector<long long> F = solve(1);
  long long c = 1;
  for (int i = 1; i < F.size(); i++) {
    Add(ans, mul(F[i], c));
    Mul(c, mul(add(Rt, i), inv[i]));
  }
  printf("%lld\n", ans);
  return 0;
}
