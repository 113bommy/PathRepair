#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 3e3 + 7, p = 998244353;
int n, f[N], t[N], w[N], inv[N], len[N], fac[N], ifac[N], l[N][M], r[N][M];
struct poly {
  int f[N];
} h, g[N][M];
inline int read() {
  int num = 0, tot = 6;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  if (g == '.') {
    g = getchar();
    while (47 < g && g < 58)
      num = (num << 1) + (num << 3) + g - 48, g = getchar(), tot--;
  }
  while (tot) num = num * 10, tot--;
  return num;
}
inline long long pows(long long u, int v) {
  long long ans = 1;
  while (v > 0) {
    if (v & 1) ans = ans * u % p;
    u = u * u % p, v = v >> 1;
  }
  return ans;
}
inline int mul(int a, int b) { return 1ll * a * b % p; }
inline int inc(int a, int b) {
  if (a + b >= p) return a + b - p;
  return a + b;
}
inline int sub(int a, int b) {
  if (a - b < 0) return a - b + p;
  return a - b;
}
inline poly diff(poly u) {
  for (int i = 1; i <= n; i++) u.f[i - 1] = mul(u.f[i], i);
  u.f[n] = 0;
  return u;
}
inline poly integ(poly u) {
  for (int i = n; i >= 1; i--) u.f[i] = mul(u.f[i - 1], inv[i]);
  u.f[0] = 0;
  return u;
}
inline poly inc(poly a, poly b) {
  for (int i = 0; i <= n; i++) a.f[i] = inc(a.f[i], b.f[i]);
  return a;
}
inline int getans(int a, int b) {
  return mul(mul(fac[a], ifac[b]), ifac[a - b]);
}
inline poly vari(poly u) {
  poly r = h;
  for (int i = 0; i <= n; i++)
    for (int x = 0; x <= i; x++)
      r.f[x] = inc(r.f[x], mul(mul(u.f[i], getans(i, x)), w[i - x]));
  for (int i = 0; i <= n; i++) r.f[i] = p - r.f[i];
  return r;
}
inline int getsum(poly u, int k) {
  k = pows(1e6, p - 2) * k % p;
  int ans = 0;
  for (int i = 0; i <= n; i++) ans = inc(ans, mul(pows(k, i), u.f[i]));
  return ans;
}
inline void delit(int u) {
  while (r[u][len[u]] > f[u]) {
    if (l[u][len[u]] < f[u]) {
      r[u][len[u]] = f[u];
      break;
    }
    len[u]--;
  }
  len[u]++, l[u][len[u]] = r[u][len[u] - 1], r[u][len[u]] = 1e8,
            g[u][len[u]] = h;
}
int main() {
  cin >> n, inv[0] = 1, fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++)
    f[i] = read(), f[i] = min(f[i], f[i - 1] + 1000000),
    inv[i] = pows(i, p - 2), fac[i] = mul(fac[i - 1], i),
    ifac[i] = mul(ifac[i - 1], inv[i]);
  l[1][1] = -1e8, r[1][1] = 0, len[1]++;
  l[1][2] = 0, r[1][2] = 1000000, len[1]++, g[1][2].f[0] = 1;
  delit(1);
  for (int i = 0; i <= n; i++) w[i] = pows(p - 1, i);
  for (int i = 2; i <= n; i++) {
    int sum = 0;
    t[0] = 0;
    for (int x = 1; x <= len[i - 1]; x++) {
      g[i - 1][x] = integ(g[i - 1][x]);
      g[i - 1][x].f[0] =
          sub(inc(g[i - 1][x].f[0], sum), getsum(g[i - 1][x], l[i - 1][x]));
      sum = getsum(g[i - 1][x], r[i - 1][x]);
    }
    for (int x = 1; x <= len[i - 1]; x++)
      t[++t[0]] = l[i - 1][x] + 1e6, t[++t[0]] = r[i - 1][x];
    sort(t + 1, t + t[0] + 1);
    for (int x = 2; x <= t[0]; x++) {
      if (t[x] == t[x - 1]) continue;
      len[i]++, l[i][len[i]] = t[x - 1], r[i][len[i]] = t[x];
      for (int c = 1; c <= len[i - 1]; c++) {
        if (l[i - 1][c] <= l[i][len[i]] - 1e6 &&
            l[i][len[i]] - 1e6 < r[i - 1][c]) {
          g[i][len[i]] = vari(g[i - 1][c]);
        }
        if (l[i - 1][c] <= l[i][len[i]] && l[i][len[i]] < r[i - 1][c]) {
          g[i][len[i]] = inc(g[i][len[i]], g[i - 1][c]);
        }
      }
    }
    delit(i);
  }
  int sum = 0;
  for (int x = 1; x <= len[n]; x++) {
    g[n][x] = integ(g[n][x]);
    g[n][x].f[0] = sub(inc(g[n][x].f[0], sum), getsum(g[n][x], l[n][x]));
    sum = getsum(g[n][x], r[n][x]);
  }
  cout << sum << endl;
}
