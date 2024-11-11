#include <bits/stdc++.h>
using namespace std;
const int N = 107, M = 1e5 + 7, K = (1 << 20), p = 1e9 + 7;
map<int, int> qx, qy;
vector<int> vt[N], vq[N];
int n, k, fx, fy, op, q[N], fa[N], len[N];
bool fl[N], ft[N], fc[N];
long long fac[M], fg[N][N][2], dp[N][N][2], va[2][K];
struct node {
  int x, y, w;
} e[N], f[N], s[N];
struct poly {
  int s[N], len;
} ans, sum, opt;
inline int read() {
  int num = 0;
  char t = '+', g = getchar();
  while (g < 48 || 57 < g) t = g, g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  if (t == '-') return 0 - num;
  return num;
}
inline void find(int u) {
  fl[u] = 1, q[++q[0]] = u;
  for (int i = 1; i <= n; i++)
    if (!fl[i] && e[i].x == e[u].x) find(i);
  for (int i = 1; i <= n; i++)
    if (!fl[i] && e[i].y == e[u].y) find(i);
}
inline poly mul(poly a, poly b) {
  poly c = sum;
  c.len = a.len + b.len;
  for (int i = 0; i <= a.len; i++)
    for (int j = 0; j <= b.len; j++)
      c.s[i + j] = (c.s[i + j] + 1ll * a.s[i] * b.s[j]) % p;
  return c;
}
inline int getfa(int u) {
  if (fa[u] == u) return u;
  return fa[u] = getfa(fa[u]);
}
inline void findit(int u) {
  dp[u][0][ft[u]] = 1, fc[u] = 1;
  for (int i = 0; i < len[u]; i++) {
    int x = vt[u][i];
    if (fc[x]) continue;
    findit(x);
    memset(fg[u], 0, sizeof(fg[u]));
    for (int s = 0; s <= n; s++) {
      if (!dp[u][s][0] && !dp[u][s][1]) continue;
      for (int t = 0; t <= n; t++) {
        if (!dp[x][t][0] && !dp[x][t][1]) continue;
        fg[u][s + t][0] =
            (fg[u][s + t][0] + dp[u][s][0] * (dp[x][t][0] + dp[x][t][1])) % p;
        fg[u][s + t][1] =
            (fg[u][s + t][1] + dp[u][s][1] * (dp[x][t][0] + dp[x][t][1])) % p;
        fg[u][s + t + 1][1] = (fg[u][s + t + 1][1] +
                               dp[u][s][0] * dp[x][t][0] % p * (vq[u][i] - 1)) %
                              p;
      }
    }
    for (int s = 0; s <= n; s++)
      dp[u][s][0] = fg[u][s][0], dp[u][s][1] = fg[u][s][1];
  }
  fc[u] = 0;
}
inline void dfsit(int u, int x, long long c) {
  if (u == op + 1) {
    memset(dp, 0, sizeof(dp)), findit(1);
    for (int i = 0; i + x <= n; i++)
      opt.s[i + x] = (opt.s[i + x] + (dp[1][i][0] + dp[1][i][1]) * c) % p;
    return;
  }
  if (!ft[s[u].x] && !ft[s[u].y + fx])
    ft[s[u].x] = ft[s[u].y + fx] = 1, dfsit(u + 1, x + 1, c * (s[u].w - 1) % p),
    ft[s[u].x] = ft[s[u].y + fx] = 0;
  dfsit(u + 1, x, c);
}
inline void getans_tree() {
  for (int i = 1; i <= fx + fy; i++)
    fa[i] = i, vt[i].resize(0), vq[i].resize(0), len[i] = 0;
  op = 0, opt = sum;
  for (int i = 1; i <= q[0]; i++) {
    if (getfa(f[i].x) == getfa(f[i].y + fx)) {
      s[++op] = f[i];
      continue;
    }
    fa[getfa(f[i].x)] = f[i].y + fx, vt[f[i].x].push_back(f[i].y + fx),
    vt[f[i].y + fx].push_back(f[i].x), len[f[i].x]++, len[f[i].y + fx]++;
    vq[f[i].x].push_back(f[i].w), vq[f[i].y + fx].push_back(f[i].w);
  }
  dfsit(1, 0, 1);
  for (int i = 1; i <= n; i++)
    if (opt.s[i]) opt.len = i;
  ans = mul(ans, opt);
}
inline int count(int u) {
  int cnt = 0;
  while (u > 0) {
    if (u & 1) cnt++;
    u = u >> 1;
  }
  return cnt;
}
inline void getans_process() {
  bool oq = 0;
  memset(va, 0, sizeof(va));
  va[oq][0] = 1, opt = sum;
  for (int i = 1; i <= q[0]; i++) {
    oq ^= 1;
    int tq = i;
    for (int x = 0; x < (1 << fy); x++) va[oq][x] = va[oq ^ 1][x];
    while (f[tq].x == f[i].x && tq <= q[0]) {
      f[tq].y--;
      for (int x = 0; x < (1 << (fy)); x++)
        if (!(x & (1 << f[tq].y)))
          va[oq][x + (1 << f[tq].y)] =
              (va[oq][x + (1 << f[tq].y)] + va[oq ^ 1][x] * (f[tq].w - 1)) % p;
      tq++;
    }
    i = tq - 1;
  }
  for (int i = 0; i < (1 << fy); i++)
    opt.s[count(i)] = (opt.s[count(i)] + va[oq][i]) % p;
  for (int i = 1; i <= n; i++)
    if (opt.s[i]) opt.len = i;
  ans = mul(ans, opt);
}
inline bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  k = read(), n = read(), fac[0] = 1, ans.len = 1, ans.s[0] = 1;
  for (int i = 1; i <= k; i++) fac[i] = fac[i - 1] * i % p;
  for (int i = 1; i <= n; i++)
    e[i].x = read(), e[i].y = read(), e[i].w = read();
  for (int i = 1; i <= n; i++) {
    if (fl[i]) continue;
    fx = 0, fy = 0, q[0] = 0, find(i);
    for (int i = 1; i <= q[0]; i++) {
      if (!qx[e[q[i]].x]) qx[e[q[i]].x] = ++fx;
      if (!qy[e[q[i]].y]) qy[e[q[i]].y] = ++fy;
      f[i].x = qx[e[q[i]].x], f[i].y = qy[e[q[i]].y], f[i].w = e[q[i]].w;
    }
    if (fx < fy) {
      for (int i = 1; i <= q[0]; i++) swap(f[i].x, f[i].y);
      swap(fx, fy);
    }
    sort(f + 1, f + q[0] + 1, cmp);
    if (q[0] - (fx + fy - 1) <= fy)
      getans_tree();
    else
      getans_process();
  }
  long long res = 0;
  for (int i = 0; i <= k; i++) res = (res + fac[k - i] * ans.s[i]) % p;
  cout << res << endl;
  return 0;
}
