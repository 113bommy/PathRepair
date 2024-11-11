#include <bits/stdc++.h>
using std ::lower_bound;
using std ::reverse;
using std ::sort;
using std ::swap;
using std ::unique;
template <typename T>
T max(T x, T y) {
  return (x > y) ? x : y;
}
template <typename T>
T min(T x, T y) {
  return (x < y) ? x : y;
}
template <typename T>
bool chkmax(T &x, T y) {
  return (x >= y) ? 0 : (x = y, 1);
}
template <typename T>
bool chkmin(T &x, T y) {
  return (x <= y) ? 0 : (x = y, 1);
}
template <typename T>
T read(T &in) {
  in = 0;
  char ch;
  T f = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) in = in * 10 + ch - '0', ch = getchar();
  return in *= f;
}
static const int MOD = 998244353;
static const int MAX1 = 100000 + 11;
static const int MAX2 = 200000 + 11;
static const int MAX_LOG = 18;
int add(int x) { return (x >= MOD) ? (x - MOD) : x; }
int reduce(int x) { return (x < 0) ? (x + MOD) : x; }
void Add(int &x) {
  if (x >= MOD) x -= MOD;
}
void Reduce(int &x) {
  if (x < 0) x += MOD;
}
int qpow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1ll * x * x % MOD)
    if (y & 1) res = 1ll * res * x % MOD;
  return res;
}
int Ct, Ht[MAX1], Nt[MAX2], to[MAX2];
void ins(int x, int y) {
  Nt[++Ct] = Ht[x], Ht[x] = Ct, to[Ct] = y;
  Nt[++Ct] = Ht[y], Ht[y] = Ct, to[Ct] = x;
}
int N, M, L, R[1 << MAX_LOG | 1];
int PolyA[1 << MAX_LOG | 1], PolyB[1 << MAX_LOG | 1];
void NTT(int *x) {
  for (int i = (0), ir = (N - 1); i <= (ir); ++i)
    if (i < R[i]) swap(x[i], x[R[i]]);
  for (int i = 1; i < N; i <<= 1) {
    int gn = qpow(3, (MOD - 1) / (i << 1));
    for (int j = 0, t = i << 1; j < N; j += t) {
      int g = 1;
      for (int k = 0; k < i; ++k, g = 1ll * g * gn % MOD) {
        int oA = x[j + k], oB = 1ll * g * x[i + j + k] % MOD;
        x[j + k] = add(oA + oB), x[i + j + k] = reduce(oA - oB);
      }
    }
  }
}
struct polynomial {
  int *x, n;
  int &operator[](int n) { return x[n]; }
  const int &operator[](int n) const { return x[n]; }
  polynomial() { x = NULL, n = 0; }
  void newlife(int N) {
    n = N, delete[] x, x = new int[N], memset(x, 0, sizeof(int) * N);
  }
  void give1(polynomial a) {
    newlife(a.n);
    memcpy(x, a.x, sizeof(int) * n);
  }
  void give2(polynomial a) { delete[] x, x = a.x, n = a.n; }
};
polynomial operator*(polynomial a, polynomial b) {
  polynomial c;
  c.newlife(a.n + b.n - 1);
  for (N = 1, L = 0; N < c.n; N <<= 1) ++L;
  for (int i = (0), ir = (N - 1); i <= (ir); ++i)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
  for (int i = (0), ir = (a.n - 1); i <= (ir); ++i) PolyA[i] = a[i];
  for (int i = (a.n), ir = (N - 1); i <= (ir); ++i) PolyA[i] = 0;
  for (int i = (0), ir = (b.n - 1); i <= (ir); ++i) PolyB[i] = b[i];
  for (int i = (b.n), ir = (N - 1); i <= (ir); ++i) PolyB[i] = 0;
  NTT(PolyA), NTT(PolyB);
  for (int i = (0), ir = (N - 1); i <= (ir); ++i)
    PolyA[i] = 1ll * PolyA[i] * PolyB[i] % MOD;
  NTT(PolyA);
  int iv = qpow(N, MOD - 2);
  reverse(1 + PolyA, N + PolyA);
  for (int i = (0), ir = (c.n - 1); i <= (ir); ++i)
    c[i] = 1ll * PolyA[i] * iv % MOD;
  return c;
}
polynomial operator*(polynomial a, int b) {
  polynomial c;
  c.newlife(a.n + 1);
  memcpy(c.x, a.x, sizeof(int) * a.n);
  for (int i = (c.n - 1), ir = (1); i >= (ir); --i)
    c[i] = (c[i] + 1ll * b * c[i - 1]) % MOD;
  return c;
}
polynomial operator/(polynomial a, int b) {
  polynomial c;
  c.newlife(a.n - 1);
  c[0] = a[0];
  for (int i = (1), ir = (c.n - 1); i <= (ir); ++i)
    c[i] = reduce(a[i] - 1ll * c[i - 1] * b % MOD);
  return c;
}
int n, k, Ans, sum;
int fa[MAX1], size[MAX1], deg[MAX1];
int fac[MAX1], inv[MAX1];
int S[MAX1], *son[MAX1];
int f[MAX1], *g[MAX1], sf[MAX1], tf[MAX1];
polynomial o[MAX_LOG + 1], P[MAX1], *Q[MAX1], o_o;
void solve(int l, int r, int d = 0) {
  if (l == r) return o[d].newlife(2), o[d][0] = 1, o[d][1] = S[l], void();
  int mid = (l + r) >> 1;
  solve(l, mid, d + 1);
  o[d].give1(o[d + 1]);
  solve(mid + 1, r, d + 1);
  o[d].give2(o[d] * o[d + 1]);
}
void DFS(int x) {
  int &len = deg[x];
  for (int i = (Ht[x]); i; i = (Nt[i]))
    if (to[i] != fa[x]) ++len;
  son[x] = new int[len];
  int ori_len = len;
  len = 0;
  size[x] = 1;
  for (int i = (Ht[x]); i; i = (Nt[i]))
    if (to[i] != fa[x]) {
      fa[to[i]] = x, DFS(to[i]), size[x] += size[to[i]];
      son[x][len++] = size[to[i]];
    }
  if (!len) return f[x] = 1, void();
  memcpy(S, son[x], sizeof(int) * len);
  solve(0, len - 1);
  P[x].give1(o[0]);
  sort(S, S + len);
  len = unique(S, len + S) - S;
  Q[x] = new polynomial[len];
  o_o.give2(P[x] * (n - size[x]));
  memcpy(son[x], S, sizeof(int) * len);
  for (int i = (0), ir = (len - 1); i <= (ir); ++i)
    Q[x][i].give2(o_o / son[x][i]);
  for (int i = (0), ir = (min(k, ori_len)); i <= (ir); ++i)
    f[x] = (f[x] + 1ll * P[x][i] * fac[k] % MOD * inv[k - i]) % MOD;
  g[x] = new int[len];
  memset(g[x], 0, sizeof(int) * len);
  for (int i = (0), ir = (len - 1); i <= (ir); ++i)
    for (int j = (0), jr = (min(k, ori_len)); j <= (jr); ++j)
      g[x][i] = (g[x][i] + 1ll * Q[x][i][j] * fac[k] % MOD * inv[k - j]) % MOD;
}
void DFS1(int x) {
  tf[x] = add(f[x] + tf[fa[x]]);
  for (int i = (Ht[x]); i; i = (Nt[i]))
    if (to[i] != fa[x]) {
      DFS1(to[i]), Add(sf[x] += sf[to[i]]);
    }
  Ans = (Ans + 1ll * f[x] * (sum - sf[x] - tf[x])) % MOD;
  Add(sf[x] += f[x]);
}
void DFS2(int x, int F = 0) {
  Ans = (Ans + 1ll * f[x] * F) % MOD;
  for (int i = (Ht[x]); i; i = (Nt[i]))
    if (to[i] != fa[x]) {
      DFS2(to[i],
           add(F + g[x][lower_bound(son[x], son[x] + deg[x], size[to[i]]) -
                        son[x]]));
    }
}
int main() {
  read(n), read(k);
  for (int i = (1), ir = (n - 1); i <= (ir); ++i) {
    int x, y;
    read(x), read(y);
    ins(x, y);
  }
  if (k == 1) {
    printf("%lld\n", 1ll * n * (n - 1) / 2 % MOD);
    return 0;
  }
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = (2), ir = (max(n, k)); i <= (ir); ++i)
    fac[i] = 1ll * i * fac[i - 1] % MOD,
    inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
  for (int i = (2), ir = (max(n, k)); i <= (ir); ++i)
    inv[i] = 1ll * inv[i - 1] * inv[i] % MOD;
  DFS(1);
  for (int i = (1), ir = (n); i <= (ir); ++i) Add(sum += f[i]);
  DFS1(1);
  Ans = (Ans + MOD) % MOD * 499122177ll % MOD;
  DFS2(1);
  printf("%d\n", Ans);
  return 0;
}
