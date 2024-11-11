#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, mod = 998244353;
inline int gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }
inline int fpow(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * x % mod;
    k >>= 1;
    x = (long long)x * x % mod;
  }
  return res;
}
int n, k, ans, s1, s2, fac[maxn], ifac[maxn];
struct edge {
  int to, next;
} e[maxn * 2];
int h[maxn], siz[maxn], tot;
int f[maxn], fs[maxn];
vector<pair<int, int> > vec;
vector<int> _F[maxn], _G[maxn];
int N, L, R[maxn << 2], w[maxn << 2], F[maxn << 2], Fl[maxn << 2],
    Fr[maxn << 2], G[maxn << 2], Gl[maxn << 2], Gr[maxn << 2];
inline void adde(int u, int v) {
  e[++tot] = (edge){v, h[u]};
  h[u] = tot;
  e[++tot] = (edge){u, h[v]};
  h[v] = tot;
}
void init(int n) {
  for (N = 1, L = -1; N <= n; N <<= 1) ++L;
  for (int i = 0; i < N; ++i) R[i] = (R[i >> 1] >> 1) | ((i & 1) << L);
  w[N >> 1] = 1;
  int wn = fpow(3, (mod - 1) / N);
  for (int i = (N >> 1) + 1; i < N; ++i) w[i] = (long long)w[i - 1] * wn % mod;
  for (int i = (N >> 1) - 1; i; --i) w[i] = w[i << 1];
}
void dft(int *a) {
  for (int i = 0; i < N; ++i)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int d = 1; d < N; d <<= 1)
    for (int i = 0; i < N; i += d << 1)
      for (int j = 0; j < d; ++j) {
        int t = (long long)w[d + j] * a[i + d + j] % mod;
        a[i + d + j] = sub(a[i + j], t);
        a[i + j] = add(a[i + j], t);
      }
}
void idft(int *a) {
  dft(a);
  reverse(a + 1, a + N);
  int inv = fpow(N, mod - 2);
  for (int i = 0; i < N; ++i) a[i] = (long long)a[i] * inv % mod;
}
void solve(int l, int r, int u) {
  if (l == r) {
    vector<int> &F = _F[l], &G = _G[l];
    F.resize(2);
    G.resize(2);
    F[0] = 1;
    F[1] = vec[l].second;
    G[0] = add(f[vec[l].first], fs[vec[l].first]);
    G[1] =
        (long long)add(f[vec[l].first], fs[vec[l].first]) * (n - siz[u]) % mod;
    return;
  }
  int mid = (l + r) >> 1, l1 = mid - l + 1, l2 = r - mid;
  solve(l, mid, u);
  solve(mid + 1, r, u);
  init(r - l + 1);
  for (int i = 0; i <= l1; ++i) Fl[i] = _F[l][i], Gl[i] = _G[l][i];
  memset(Fl + l1 + 1, 0, sizeof(int) * (N - l1));
  memset(Gl + l1 + 1, 0, sizeof(int) * (N - l1));
  for (int i = 0; i <= l2; ++i) Fr[i] = _F[mid + 1][i], Gr[i] = _G[mid + 1][i];
  memset(Fr + l2 + 1, 0, sizeof(int) * (N - l2));
  memset(Gr + l2 + 1, 0, sizeof(int) * (N - l2));
  dft(Fl);
  dft(Gl);
  dft(Fr);
  dft(Gr);
  for (int i = 0; i < N; ++i) F[i] = (long long)Fl[i] * Fr[i] % mod;
  for (int i = 0; i < N; ++i)
    G[i] = ((long long)Fl[i] * Gr[i] + (long long)Fr[i] * Gl[i]) % mod;
  idft(F);
  idft(G);
  _F[l].resize(r - l + 2);
  _G[l].resize(r - l + 2);
  for (int i = 0; i <= r - l + 1; ++i) _F[l][i] = F[i], _G[l][i] = G[i];
}
void dfs(int u, int fa) {
  siz[u] = 1;
  for (int i = h[u], v; v = e[i].to, i; i = e[i].next)
    if (v != fa) dfs(v, u);
  vec.clear();
  for (int i = h[u], v; v = e[i].to, i; i = e[i].next)
    if (v != fa) {
      fs[u] = add(fs[u], add(f[v], fs[v]));
      siz[u] += siz[v];
      vec.emplace_back(v, siz[v]);
    }
  if (vec.empty())
    return f[u] = 1, s1 = add(s1, f[u]), s2 = add(s2, f[u]), void();
  solve(0, vec.size() - 1, u);
  vector<int> &F = _F[0], &G = _G[0];
  int s = F.size() - 1;
  for (int i = 0; i <= s; ++i)
    f[u] = (f[u] + (long long)fac[k] * ifac[k - i] % mod * F[i]) % mod;
  s1 = add(s1, f[u]);
  s2 = (s2 + (long long)f[u] * f[u]) % mod;
  for (int i = 0; i <= s; ++i)
    ans = (ans + (long long)fac[k] * ifac[k - i] % mod * G[i]) % mod;
  ans = (ans + (long long)(mod - f[u]) * fs[u]) % mod;
}
int main() {
  n = gi();
  k = gi();
  if (k == 1) return printf("%lld\n", (long long)n * (n - 1) / 2 % mod), 0;
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  ifac[k] = fpow(fac[k], mod - 2);
  for (int i = k - 1; ~i; --i) ifac[i] = (long long)ifac[i + 1] * (i + 1) % mod;
  for (int i = 1; i < n; ++i) adde(gi(), gi());
  dfs(1, 0);
  printf("%d\n", add(ans, (long long)sub((long long)s1 * s1 % mod, s2) *
                              (mod + 1) / 2 % mod));
  return 0;
}
