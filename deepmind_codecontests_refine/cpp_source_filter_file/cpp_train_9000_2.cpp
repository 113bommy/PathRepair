#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct edge {
  int to, next;
} e[N * 2];
int head[N], tot;
void add(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
}
int fa[N][20], dep[N];
void dfs(int x) {
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa[x][0]) {
      fa[e[i].to][0] = x;
      dep[e[i].to] = dep[x] + 1;
      dfs(e[i].to);
    }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int tmp = dep[x] - dep[y];
  for (int i = (int)(17); i >= (int)(0); i--)
    if (tmp & (1 << i)) x = fa[x][i];
  for (int i = (int)(17); i >= (int)(0); i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return x == y ? x : fa[x][0];
}
int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)]; }
int Mx(int x, int y) { return dep[x] > dep[y] ? x : y; }
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void exgcd(int x, int y, long long &a, long long &b) {
  if (!y) {
    a = 1, b = 0;
    return;
  }
  exgcd(y, x % y, b, a);
  b -= x / y * a;
}
long long SAME(int a, int b, int c, int d) {
  c -= a;
  long long k, p;
  int G = gcd(b, d);
  exgcd(b, d, k, p);
  if (c % G) return (1ll << 59);
  k *= c / G, p *= -(c / G);
  long long ad = d / G, ab = b / G;
  if (k < 0) {
    long long ti = max((-k - 1) / ad + 1, (-p - 1) / ab + 1);
    k += ad * ti;
    p += ab * ti;
  }
  long long ti = min(k / ad, p / ab);
  k -= ad * ti, p -= ab * ti;
  return b * k + a;
}
long long leiGCD(long long L, long long D, long long R, long long P) {
  if (!L) return 0;
  if (!D) return (1ll << 59);
  if (2 * D > P) return leiGCD(P - R, P - D, P - L, P);
  if ((L - 1) / D < R / D) return (L + D - 1) / D;
  long long tmp = leiGCD(L % D, D - P % D, R % D, D);
  return tmp == (1ll << 59) ? (1ll << 59) : (tmp * P + L + D - 1) / D;
}
long long DIFF(long long t1, long long f1, long long t4, long long f2,
               long long d) {
  if ((d + t1 + t4) & 1) return (1ll << 59);
  int l = ((t4 - t1 - d) % f2 + f2) % f2;
  int r = ((t4 - t1 + d) % f2 + f2) % f2;
  long long tmp = 0;
  if (f2 != 2 * d && l <= r && l)
    if ((l - 1) / gcd(f1, f2) >= r / gcd(f1, f2))
      tmp = (1ll << 59);
    else
      tmp = leiGCD(l, f1 % f2, r, f2);
  long long q = (tmp * f1 + t1 + d - t4) / f2;
  return (d + tmp * f1 + q * f2 + t1 + t4) / 2;
}
void solve() {
  int u, v, x, y;
  scanf("%d%d%d%d", &u, &v, &x, &y);
  int L1 = Mx(LCA(u, x), LCA(u, y));
  int L2 = Mx(LCA(v, x), LCA(v, y));
  int p = Mx(LCA(u, v), LCA(x, y));
  if (dep[L1] < dep[p] && dep[L2] < dep[p]) {
    puts("-1");
    return;
  }
  L1 = Mx(L1, p);
  L2 = Mx(L2, p);
  int t1 = dis(L1, u), t2 = dis(L2, u);
  int t3 = dis(L1, x), t4 = dis(L2, x);
  int f1 = dis(u, v) * 2, f2 = dis(x, y) * 2;
  int d = dis(L1, L2);
  if (t1 > t2)
    t1 = f1 - t1;
  else
    t2 = f1 - t2;
  if (t3 > t4)
    t3 = f2 - t3;
  else
    t4 = f2 - t4;
  long long ans = (1ll << 59);
  ans = min(ans, SAME(t1, f1, t3, f2));
  ans = min(ans, SAME(t2, f1, t4, f2));
  ans = min(ans, DIFF(t1, f1, t4, f2, d));
  ans = min(ans, DIFF(t2, f1, t3, f2, d));
  printf("%lld\n", ans == (1ll << 59) ? -1 : ans);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1);
  for (int i = (int)(1); i <= (int)(17); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      fa[j][i] = fa[fa[j][i - 1]][i - 1];
  int Q;
  scanf("%d", &Q);
  while (Q--) solve();
}
