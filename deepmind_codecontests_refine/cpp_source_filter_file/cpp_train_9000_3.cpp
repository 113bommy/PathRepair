#include <bits/stdc++.h>
using namespace std;
const int N = 200005, L = 18;
const long long INF = 9e18;
int n, q, dep[N], fa[N][L];
int head[N], numE = 0;
struct E {
  int next, v;
} e[N << 1];
void inline add(int u, int v) {
  e[++numE] = (E){head[u], v};
  head[u] = numE;
}
void dfs(int u) {
  for (int i = 1; i < L && fa[u][i - 1]; i++)
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa[u][0]) continue;
    fa[v][0] = u, dep[v] = dep[u] + 1;
    dfs(v);
  }
}
int inline lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = L - 1; ~i; i--)
    if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = L - 1; ~i; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int inline d(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
long long inline work1(long long a, long long b, long long T1, long long T2) {
  long long x, y, c = T2 - T1, D1 = a;
  long long d = exgcd(a, b, x, y);
  if (c % d) return INF;
  x *= c / d, y *= -c / d;
  a /= d, b /= d;
  if (x < 0 || y < 0) {
    long long k = max((-x - 1) / b + 1, (-y - 1) / a + 1);
    x += k * b, y += k * a;
  }
  long long k = min(x / b, y / a);
  x -= k * b;
  return x * D1 + T1;
}
long long G(long long L, long long R, long long D, long long P) {
  if (!D || L > R) return INF;
  if (R / D * D >= L) return (L + D - 1) / D;
  long long x = G(((-R) % D + D) % D, ((-L) % D + D) % D, P % D, D);
  if (x == INF) return INF;
  return (x * P + L + D - 1) / D;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long work2(long long D1, long long D2, long long T1, long long T2,
                long long D) {
  if ((D + T1 + T2) & 1) return INF;
  long long L = ((T2 - T1 - D) % D2 + D2) % D2,
            R = ((T2 - T1 + D) % D2 + D2) % D2;
  long long x1 = 0;
  if (2 * D < D2 && L <= R) x1 = G(L, R, D1 % D2, D1);
  if (x1 == INF) return INF;
  long long x2 = (x1 * D1 + T1 - T2 + D) / D2;
  return (x1 * D1 + x2 * D2 + T1 + T2 + D) / 2;
}
long long inline query(int u, int v, int x, int y) {
  int p[4] = {lca(u, x), lca(u, y), lca(v, x), lca(v, y)};
  int w = lca(u, v), z = lca(x, y);
  int p1 = 0, p2 = 0;
  for (int i = 0; i < 4; i++)
    if (dep[p[i]] > dep[p1])
      p2 = p1, p1 = p[i];
    else if (dep[p[i]] > dep[p2])
      p2 = p[i];
  if (p1 == p2 && (dep[p1] < dep[w] || dep[p1] < dep[z])) return -1;
  int D1 = d(u, v) * 2, D2 = d(x, y) * 2, D = d(p1, p2);
  int U1 = d(u, p1), U2 = d(u, p2);
  if (U1 < U2)
    U2 = D1 - U2;
  else
    U1 = D1 - U1;
  int X1 = d(x, p1), X2 = d(x, p2);
  if (X1 < X2)
    X2 = D2 - X2;
  else
    X1 = D2 - X1;
  long long res = min(work1(D1, D2, U1, X1), work1(D1, D2, U2, X2));
  res = min(res, min(work2(D1, D2, U1, X2, D), work2(D1, D2, U2, X1, D)));
  return res == INF ? -1 : res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
  dep[1] = 1, dfs(1);
  scanf("%d", &q);
  while (q--) {
    int u, v, x, y;
    scanf("%d%d%d%d", &u, &v, &x, &y);
    printf("%lld\n", query(u, v, x, y));
  }
  return 0;
}
