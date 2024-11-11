#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long mod = 95542721;
const double eps = 1e-9;
const double pi = 3.1415926535897932384626;
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
namespace flow {
const int M = 300000, N = 30000;
int y[M], nxt[M], gap[N], fst[N], c[N], pre[N], q[N], dis[N];
int f[M];
int S, T, tot, Tn;
void init(int s, int t, int tn) {
  tot = 1;
  memset(fst, 0, sizeof(fst));
  S = s;
  T = t;
  Tn = tn;
}
void add(int u, int v, int c1, int c2 = 0) {
  tot++;
  y[tot] = v;
  f[tot] = c1;
  nxt[tot] = fst[u];
  fst[u] = tot;
  tot++;
  y[tot] = u;
  f[tot] = c2;
  nxt[tot] = fst[v];
  fst[v] = tot;
}
int sap() {
  int u = S, t = 1;
  int flow = 0;
  for (int i = 0; i < (int)Tn; i++) c[i] = fst[i], dis[i] = Tn, gap[i] = 0;
  q[0] = T;
  dis[T] = 0;
  pre[S] = 0;
  for (int i = 0; i < (int)t; i++) {
    int u = q[i];
    for (int j = fst[u]; j; j = nxt[j])
      if (dis[y[j]] > dis[u] + 1 && f[j ^ 1])
        q[t++] = y[j], dis[y[j]] = dis[u] + 1;
  }
  for (int i = 0; i < (int)Tn; i++) gap[dis[i]]++;
  while (dis[S] <= Tn) {
    while (c[u] && (!f[c[u]] || dis[y[c[u]]] + 1 != dis[u])) c[u] = nxt[c[u]];
    if (c[u]) {
      pre[y[c[u]]] = c[u] ^ 1;
      u = y[c[u]];
      if (u == T) {
        int minf = inf;
        for (int p = pre[T]; p; p = pre[y[p]]) minf = min(minf, f[p ^ 1]);
        for (int p = pre[T]; p; p = pre[y[p]]) f[p ^ 1] -= minf, f[p] += minf;
        flow += minf;
        u = S;
      }
    } else {
      if (!(--gap[dis[u]])) break;
      int mind = Tn;
      c[u] = fst[u];
      for (int j = fst[u]; j; j = nxt[j])
        if (f[j] && dis[y[j]] < mind) mind = dis[y[j]], c[u] = j;
      dis[u] = mind + 1;
      gap[dis[u]]++;
      if (u != S) u = y[pre[u]];
    }
  }
  return flow;
}
};  // namespace flow
int n, m, g, w, k, Sx, fg, ans;
int sx[10100], c[20];
int main() {
  scanf("%d%d%d", &n, &m, &g);
  flow::init(0, n + m + 1, n + m + 2);
  for (int i = 0; i < (int)n; i++) scanf("%d", sx + i);
  for (int i = 0; i < (int)n; i++) {
    scanf("%d", &w);
    if (sx[i] == 0)
      flow::add(0, i + 1, w);
    else
      flow::add(i + 1, n + m + 1, w);
  }
  for (int i = 0; i < (int)n; i++) {
    scanf("%d%d%d", &Sx, &w, &k);
    for (int j = 0; j < (int)k; j++) scanf("%d", c + j);
    scanf("%d", &fg);
    ans += w;
    if (fg) w += g;
    if (Sx == 0) {
      flow::add(0, i + n + 1, w);
      for (int j = 0; j < (int)k; j++) flow::add(i + n + 1, c[j], inf);
    } else {
      flow::add(i + n + 1, n + m + 1, w);
      for (int j = 0; j < (int)k; j++) flow::add(c[j], i + n + 1, inf);
    }
  }
  printf("%d\n", ans - flow::sap());
}
