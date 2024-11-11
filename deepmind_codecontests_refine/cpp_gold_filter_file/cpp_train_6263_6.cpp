#include <bits/stdc++.h>
using namespace std;
const int N = 2200 * 8 + 5, M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n, a[N], b[N], p[N], c[N], S, T, t;
int fl[N], l[N], le[N], sw[N], in[N], minw;
struct Graph {
  int to[M], nxt[M], fl[M], w[M], hd[N], o;
  void add(int u, int v, int F, int W) {
    to[++o] = v, nxt[o] = hd[u], hd[u] = o, fl[o] = F, w[o] = W;
    to[++o] = u, nxt[o] = hd[v], hd[v] = o, fl[o] = 0, w[o] = -W;
  }
} G;
long long ft(int x) { return 1ll * a[x] * t + b[x]; }
bool cmp0(int x, int y) { return b[x] == b[y] ? x > y : b[x] < b[y]; }
bool cmpt(int x, int y) { return ft(x) == ft(y) ? x > y : ft(x) < ft(y); }
bool check() {
  for (int i = 1; i <= 2 * n; i++) {
    c[i] = 0, p[i] = i;
  }
  sort(p + 1, p + 2 * n + 1, cmp0);
  for (int i = 1, j = p[1]; i <= 2 * n; i++) {
    if (cmpt(j, p[i])) j = p[i];
    if (p[i] <= n) ++c[j];
  }
  sort(p + 1, p + 2 * n + 1, cmpt);
  for (int i = 2 * n, s = 0; i >= 1; i--) {
    s += c[p[i]] - (p[i] > n);
    if (s < 0) return false;
  }
  return true;
}
int spfa() {
  memset(fl, 0, sizeof(fl)), memset(l, 0, sizeof(l)), memset(le, 0, sizeof(le)),
      memset(in, 0, sizeof(in)), memset(sw, 0x3f, sizeof(sw));
  queue<int> q;
  q.push(S), fl[S] = INF, sw[S] = 0, in[S] = 1;
  while (!q.empty()) {
    int u = q.front();
    in[u] = 0, q.pop();
    for (int i = G.hd[u]; i; i = G.nxt[i]) {
      int v = G.to[i];
      if (!G.fl[i]) continue;
      if (sw[u] + G.w[i] < sw[v]) {
        sw[v] = sw[u] + G.w[i], l[v] = u, le[v] = i;
        ;
        fl[v] = min(fl[u], G.fl[i]);
        if (!in[v]) in[v] = 1, q.push(v);
      }
    }
  }
  return fl[T];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int L = 0, R = 1e9;
  while (L < R) {
    t = (L + R) >> 1, check() ? R = t : L = t + 1;
  }
  t = L;
  if (L == 1e9) {
    puts("-1");
    return 0;
  }
  printf("%d ", L);
  S = 8 * n + 1, T = S + 1, G.o = 1;
  for (int i = 1; i <= n; i++) {
    G.add(S, i, 1, 0);
    G.add(5 * n + i, T, 1, 0);
  }
  sort(p + 1, p + 2 * n + 1, cmp0);
  for (int i = 1; i <= 2 * n; i++) {
    G.add(p[i], 4 * n + p[i], INF, 0);
    G.add(2 * n + p[i], 4 * n + p[i], INF, 1);
    if (i > 1) {
      G.add(p[i], 2 * n + p[i - 1], INF, 0);
      G.add(2 * n + p[i], 2 * n + p[i - 1], INF, 0);
    }
  }
  sort(p + 1, p + 2 * n + 1, cmpt);
  for (int i = 1; i <= 2 * n; i++) {
    G.add(6 * n + p[i], 4 * n + p[i], INF, 1);
    if (i > 1) {
      G.add(4 * n + p[i], 6 * n + p[i - 1], INF, 0);
      G.add(6 * n + p[i], 6 * n + p[i - 1], INF, 0);
    }
  }
  while (int F = spfa()) {
    minw += F * sw[T];
    for (int p = T; p != S; p = l[p]) {
      G.fl[le[p]] -= F;
      G.fl[le[p] ^ 1] += F;
    }
  }
  printf("%d\n", minw);
  return 0;
}
