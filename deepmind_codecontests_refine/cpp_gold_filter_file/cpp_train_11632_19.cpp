#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int mod = 998244353, inv2 = (mod + 1) >> 1;
inline int fix(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return fix(x + y - mod); }
inline int dec(int x, int y) { return fix(x - y); }
inline int mul(int x, int y) { return int((long long)x * y % mod); }
inline void ADD(int &x, int y) { x = fix(x + y - mod); }
inline void DEC(int &x, int y) { x = fix(x - y); }
inline void MUL(int &x, int y) { x = int((long long)x * y % mod); }
inline int ksm(int x, int r) {
  int ret = 1;
  for (int i = 0; (1ll << i) <= r; i++) {
    if ((r >> i) & 1) MUL(ret, x);
    MUL(x, x);
  }
  return ret;
}
vector<int> rev;
inline void NTT(int *a, int len, int lim, int fl) {
  rev.resize(len);
  for (int i = 0; i < len; i++) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lim - 1));
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int mid = 1, tmp, x, u, v; mid < len; mid <<= 1) {
    tmp = ksm(3, (mod - 1) / (mid << 1));
    if (fl == -1) tmp = ksm(tmp, mod - 2);
    for (int i = 0; i < len; i += (mid << 1)) {
      x = 1;
      for (int j = 0; j < mid; j++, MUL(x, tmp)) {
        u = a[i + j];
        v = mul(x, a[i + j + mid]);
        a[i + j] = add(u, v);
        a[i + j + mid] = dec(u, v);
      }
    }
  }
  if (fl == -1)
    for (int i = 0, tmp = ksm(len, mod - 2); i < len; i++) MUL(a[i], tmp);
}
inline void getlen(int &len, int &lim, int n) {
  lim = 1;
  len = 2;
  while (len < n) {
    lim++;
    len <<= 1;
  }
}
inline void re(vector<int> &a, int n) { a.resize(n); }
inline void cre(vector<int> &a, int n) {
  a.clear();
  a.resize(n);
}
inline vector<int> operator+(vector<int> a, vector<int> b) {
  static vector<int> ret;
  int len = max((signed)a.size(), (signed)b.size());
  cre(ret, len);
  re(a, len);
  re(b, len);
  for (int i = 0; i < len; i++) ret[i] = add(a[i], b[i]);
  return ret;
}
inline vector<int> operator-(vector<int> a, vector<int> b) {
  static vector<int> ret;
  int len = max((signed)a.size(), (signed)b.size());
  cre(ret, len);
  re(a, len);
  re(b, len);
  for (int i = 0; i < len; i++) ret[i] = dec(a[i], b[i]);
  return ret;
}
inline void out(const vector<int> &a) {
  for (auto v : a) cout << v << " ";
  cout << "\n";
}
inline vector<int> mul(vector<int> a, vector<int> b) {
  int len, lim, la = (signed)a.size(), lb = (signed)b.size();
  getlen(len, lim, la + lb - 1);
  assert(lim);
  re(a, len);
  re(b, len);
  NTT(a.data(), len, lim, 1);
  NTT(b.data(), len, lim, 1);
  for (int i = 0; i < len; i++) MUL(a[i], b[i]);
  NTT(a.data(), len, lim, -1);
  re(a, la + lb - 1);
  return a;
}
void getinv(const vector<int> &a, vector<int> &b, int n) {
  if (n == 1) {
    re(b, 1);
    b[0] = ksm(a[0], mod - 2);
    return;
  }
  getinv(a, b, (n + 1) >> 1);
  static int len, lim;
  static vector<int> c;
  getlen(len, lim, n << 1);
  re(b, len);
  cre(c, len);
  for (int i = 0, mx = min(n, (signed)a.size()); i < mx; i++) c[i] = a[i];
  NTT(c.data(), len, lim, 1);
  NTT(b.data(), len, lim, 1);
  for (int i = 0; i < len; i++) MUL(b[i], dec(2, mul(b[i], c[i])));
  NTT(b.data(), len, lim, -1);
  re(b, n);
}
inline vector<int> getln(vector<int> a, int n) {
  static vector<int> I;
  getinv(a, I, n);
  for (int i = 1; i < n; i++) a[i - 1] = mul(i, a[i]);
  a[n - 1] = 0;
  a = mul(a, I);
  re(a, n);
  for (int i = n - 1; i; i--) a[i] = mul(a[i - 1], ksm(i, mod - 2));
  a[0] = 0;
  return a;
}
void getexp(const vector<int> &a, vector<int> &b, int n) {
  if (n == 1) {
    re(b, 1);
    b[0] = 1;
    return;
  }
  getexp(a, b, (n + 1) >> 1);
  static vector<int> c;
  re(b, n);
  c = getln(b, n);
  for (int i = 0; i < n; i++) c[i] = dec(a[i], c[i]);
  ADD(c[0], 1);
  b = mul(b, c);
  re(b, n);
}
inline vector<int> polyksm(vector<int> a, int k, int n) {
  static vector<int> b;
  a = getln(a, n);
  for (int i = 0; i < n; i++) MUL(a[i], k);
  getexp(a, b, n);
  return b;
}
int sq;
struct complx {
  int x, y;
  complx(int xx = 0, int yy = 0) : x(xx), y(yy) {}
  inline complx operator*(const complx &a) const {
    return complx(add(mul(x, a.x), mul(mul(y, a.y), sq)),
                  add(mul(x, a.y), mul(y, a.x)));
  }
};
inline complx ksm(complx x, int r) {
  complx ret(1, 0);
  for (int i = 0; (1ll << i) <= r; i++) {
    if ((r >> i) & 1) ret = ret * x;
    x = x * x;
  }
  return ret;
}
inline int rd(int n) { return (((long long)rand() << 15) | rand()) % n; }
inline int cipolla(int n) {
  if (n == 1) return 1;
  if (ksm(n, mod >> 1) == mod - 1) return -1;
  static int x;
  while (1) {
    x = rd(mod);
    sq = dec(mul(x, x), n);
    if (ksm(sq, mod >> 1) == mod - 1)
      return ksm(complx(x, 1), (mod + 1) >> 1).x;
  }
}
void getsqrt(const vector<int> &a, vector<int> &b, int n) {
  if (n == 1) {
    re(b, 1);
    b[0] = cipolla(a[0]);
    b[0] = min(b[0], mod - b[0]);
    return;
  }
  getsqrt(a, b, (n + 1) >> 1);
  static int len, lim;
  static vector<int> I, A;
  getlen(len, lim, n << 1);
  getinv(b, I, n);
  cre(A, len);
  re(I, len);
  re(b, len);
  for (int i = 0, mx = min(n, (signed)a.size()); i < mx; i++) A[i] = a[i];
  NTT(I.data(), len, lim, 1);
  NTT(A.data(), len, lim, 1);
  NTT(b.data(), len, lim, 1);
  for (int i = 0; i < len; i++) b[i] = mul(inv2, add(b[i], mul(A[i], I[i])));
  NTT(b.data(), len, lim, -1);
  re(b, n);
}
vector<int> fac, ifac, inv;
inline void prepare(int n) {
  re(ifac, n);
  re(fac, n);
  re(inv, n);
  ifac[0] = ifac[1] = fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i < n; i++) {
    fac[i] = mul(fac[i - 1], i);
    inv[i] = dec(0, mul(mod / i, inv[mod % i]));
  }
  ifac[n - 1] = ksm(fac[n - 1], mod - 2);
  for (int i = n - 2; i > 1; i--) ifac[i] = mul(ifac[i + 1], i + 1);
}
inline int C(int x, int y) {
  return (x < y || y < 0) ? 0 : mul(fac[x], mul(ifac[y], ifac[x - y]));
}
const int N = 1e5 + 4;
int n, k, ans1, ans2, siz[N], sum[N];
vector<int> e[N], gl[20], gr[20], fl[20], fr[20];
void solve(int p, int l, int r, int d, vector<int> &F, vector<int> &G) {
  if (l > r) {
    re(F, 1);
    F[0] = 1;
    return;
  }
  if (l == r) {
    re(F, 2);
    re(G, 1);
    G[0] = sum[e[p][r]];
    F[0] = 1;
    F[1] = siz[e[p][r]];
    return;
  }
  int mid = (l + r) >> 1;
  solve(p, l, mid, d + 1, fl[d], gl[d]);
  solve(p, mid + 1, r, d + 1, fr[d], gr[d]);
  F = mul(fl[d], fr[d]);
  G = mul(fl[d], gr[d]) + mul(fr[d], gl[d]);
}
void dfs(int x) {
  siz[x] = 1;
  for (auto v : e[x]) {
    e[v].erase(find(e[v].begin(), e[v].end(), x));
    dfs(v);
    siz[x] += siz[v];
    ADD(sum[x], sum[v]);
  }
  static vector<int> F, G;
  static int res;
  solve(x, 0, (signed)e[x].size() - 1, 0, F, G);
  res = 0;
  for (int i = 0; i <= (signed)e[x].size() && i <= k; i++)
    ADD(res, mul(F[i], ifac[k - i]));
  MUL(res, fac[k]);
  DEC(ans1, mul(res, res));
  DEC(ans1, mul(2, mul(sum[x], res)));
  ADD(sum[x], res);
  if (!((signed)e[x].size())) return;
  re(F, 2);
  F[0] = 1;
  F[1] = n - siz[x];
  F = mul(F, G);
  for (int i = 0; i <= (signed)e[x].size() && i <= k; i++)
    ADD(ans2, mul(F[i], ifac[k - i]));
}
int main() {
  n = read();
  k = read();
  if (k == 1) {
    cout << (long long)n * (n - 1) / 2 % mod << "\n";
    return (0 - 0);
  }
  prepare(k + 1);
  for (int i = 1, u, v; i < n; i++) {
    u = read();
    v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1);
  MUL(ans2, fac[k]);
  ADD(ans1, mul(sum[1], sum[1]));
  MUL(ans1, inv2);
  cout << add(ans1, ans2) << "\n";
  return (0 - 0);
}
