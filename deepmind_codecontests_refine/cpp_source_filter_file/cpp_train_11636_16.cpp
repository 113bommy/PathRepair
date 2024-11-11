#include <bits/stdc++.h>
namespace IO {
char ibuf[(1 << 21) + 1], *iS, *iT;
char Get() {
  return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, (1 << 21) + 1, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
}
int read() {
  int x = 0, c = Get();
  while (!isdigit(c)) c = Get();
  while (isdigit(c)) x = x * 10 + c - 48, c = Get();
  return x;
}
}  // namespace IO
using IO::read;
const int N = 100007, P = 998244353;
int inc(int a, int b) { return a += b - P, a + (a >> 31 & P); }
int dec(int a, int b) { return a -= b, a + (a >> 31 & P); }
int mul(int a, int b) { return 1ll * a * b % P; }
int pow(int a, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, a = mul(a, a))
    if (k & 1) r = mul(a, r);
  return r;
}
int n, k, m, ans, lim, fac[N], ifac[N], fa[N], f[N], size[N], rev[524289],
    w[524289], a[524289];
std::vector<int> e[N];
void init(int n) {
  lim = n, w[lim >> 1] = 1;
  int g = pow(3, P / lim);
  for (int i = 1; i < lim; ++i)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? lim >> 1 : 0);
  w[lim >> 1] = 1;
  for (int i = (lim >> 1) + 1; i < lim; ++i) w[i] = mul(w[i - 1], g);
  for (int i = (lim >> 1) - 1; i; --i) w[i] = w[i << 1];
}
void NTT(int *a, int f) {
  if (!~f) std::reverse(a + 1, a + lim);
  for (int i = 0; i < lim; ++i)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0, l = i << 1; j < lim; j += l)
      for (int k = 0, x; k < i; ++k)
        x = mul(a[i + j + k], w[i + k]), a[i + j + k] = dec(a[j + k], x),
        a[j + k] = inc(a[j + k], x);
  if (!~f)
    for (int i = 0, x = P - P / lim; i < lim; ++i) a[i] = mul(a[i], x);
}
void solve(int u) {
  int n = e[u].size() << 2;
  for (int i = 0; i < n; i += 4) a[i] = 1, a[i + 1] = size[e[u][i >> 2]];
  for (int i = 4; i < n; i <<= 1) {
    init(i);
    for (int j = 0; j + i < n; j += i << 1) {
      int *p = a + j, *q = p + i;
      NTT(p, 1), NTT(q, 1);
      for (int k = 0; k < i; ++k) p[k] = mul(p[k], q[k]);
      NTT(p, -1), memset(q, 0, i << 2);
    }
  }
}
void Mul(int x) {
  for (int i = m + 1; i; --i) a[i] = inc(a[i], mul(x, a[i - 1]));
}
void Div(int x) {
  for (int i = 1; i <= m + 1; ++i) a[i] = dec(a[i], mul(x, a[i - 1]));
}
int cal() {
  int n = std::min(m, k), r = 1;
  for (int i = 1; i <= n; ++i) r = inc(r, mul(mul(a[i], fac[k]), ifac[k - i]));
  return r;
}
void dfs(int u) {
  size[u] = 1;
  for (int v : e[u])
    e[v].erase(find(e[v].begin(), e[v].end(), u)), dfs(v), size[u] += size[v],
        ans = inc(ans, mul(f[u], f[v])), f[u] = inc(f[u], f[v]);
  std::sort(e[u].begin(), e[u].end(),
            [](int i, int j) { return size[i] < size[j]; });
  solve(u), m = e[u].size(), Mul(n - size[u]);
  for (int l = 0, r, s, t; l < m; l = r) {
    Div(t = size[e[u][l]]), s = 0;
    for (r = l + 1; r < m && size[e[u][r]] == t; ++r)
      ;
    for (; l < r; ++l) s = inc(s, f[e[u][l]]);
    ans = inc(ans, mul(s, cal())), Mul(t);
  }
  Div(n - size[u]), f[u] = inc(f[u], cal()), memset(a, 0, (m + 1) << 2);
}
int main() {
  n = read(), k = read(), m = std::max(n, k), fac[0] = 1;
  if (k == 1) return !printf("%d", 1ll * n * (n - 1) / 2);
  for (int i = 1; i <= m; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[m] = pow(fac[m]);
  for (int i = m; i; --i) ifac[i - 1] = mul(ifac[i], i);
  for (int i = 1, u, v; i < n; ++i)
    u = read(), v = read(), e[u].push_back(v), e[v].push_back(u);
  return dfs(1), !printf("%d", ans);
}
