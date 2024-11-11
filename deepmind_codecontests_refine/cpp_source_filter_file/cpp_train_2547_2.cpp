#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10, MAXLG = 19;
const int BASE = 1e5 + 3, MOD = 1e9 + 7, INV = 480314964;
inline int add(int x, int y) { return (x + y) % MOD; }
inline void addeq(int &x, int y) { x = add(x, y); }
inline int subtr(int x, int y) {
  x -= y;
  return x < 0 ? x + MOD : x;
}
inline void subtreq(int &x, int y) { x = subtr(x, y); }
inline int mult(int x, int y) { return 1ll * x * y % MOD; }
inline void multeq(int &x, int y) { x = mult(x, y); }
int N;
char S[MAXN];
int pwr[MAXN], ipwr[MAXN];
vector<int> adj[MAXN];
int par[MAXN][MAXLG], depth[MAXN];
int up[MAXN], dn[MAXN];
int lc[MAXN], far[MAXN];
bool isch[MAXN];
int clz[MAXN], *id[MAXN];
int path[2 * MAXN], *ptr = path;
void dfs(int x, int p, int d) {
  par[x][0] = p;
  depth[x] = d;
  up[x] = dn[x] = S[x];
  if (p) {
    addeq(dn[x], mult(dn[p], BASE));
    up[x] = add(up[p], mult(pwr[d], S[x]));
  }
  for (int i = 1; i < MAXLG; i++) {
    int pi = par[x][i - 1];
    par[x][i] = par[pi][i - 1];
  }
  for (int t : adj[x]) {
    if (t == p) {
      continue;
    }
    dfs(t, x, d + 1);
    if (far[x] < far[t] + 1) {
      far[x] = far[t] + 1;
      lc[x] = t;
    }
  }
  isch[lc[x]] = true;
}
int getpar(int x, int d) {
  if (d == 0) {
    return x;
  }
  int k = clz[d];
  d ^= (1 << k);
  return id[par[x][k]][-d];
}
int lca(int x, int y) {
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  y = getpar(y, depth[y] - depth[x]);
  if (x == y) {
    return x;
  }
  for (int k = MAXLG - 1; k >= 0; k--) {
    if (par[x][k] != par[y][k]) {
      x = par[x][k];
      y = par[y][k];
    }
  }
  return par[x][0];
}
int dist(int x, int y) { return depth[x] + depth[y] - 2 * depth[lca(x, y)]; }
int getup(int x, int c) {
  return c == 1 ? up[x] : mult(subtr(up[x], up[par[c][0]]), ipwr[depth[c]]);
}
int getdn(int x, int y) {
  return x == 1
             ? dn[y]
             : subtr(dn[y], mult(dn[par[x][0]], pwr[depth[y] - depth[x] + 1]));
}
int gethsh(int u, int v, int c, int len) {
  int ans;
  int uc = depth[u] - depth[c] + 1;
  if (len <= uc) {
    ans = getup(u, getpar(u, len - 1));
  } else {
    int dup = getup(u, c);
    len -= uc;
    v = getpar(v, depth[v] - depth[c] - len);
    int ddn = subtr(dn[v], mult(dn[c], pwr[depth[v] - depth[c]]));
    ans = add(mult(pwr[len], dup), ddn);
  }
  return ans;
}
int main() {
  pwr[0] = ipwr[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    pwr[i] = mult(pwr[i - 1], BASE);
    ipwr[i] = mult(ipwr[i - 1], INV);
    clz[i] = 31 - __builtin_clz(i);
  }
  scanf("%d %s", &N, S + 1);
  for (int i = 1; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0, 0);
  for (int i = 1; i <= N; i++) {
    if (isch[i]) {
      continue;
    }
    int u = par[i][0], v = i, k = min(depth[i], far[i]);
    for (int j = 1; j <= k; j++) {
      ptr[k - j] = u;
      u = par[u][0];
    }
    ptr += k;
    while (v > 0) {
      id[v] = ptr;
      *(ptr++) = v;
      v = lc[v];
    }
  }
  int nq, u1, v1, u2, v2;
  for (scanf("%d", &nq); nq--;) {
    scanf("%d %d %d %d", &u1, &v1, &u2, &v2);
    int lo = 0, hi = min(dist(u1, v1), dist(u2, v2)) + 2;
    int c1 = lca(u1, v1), c2 = lca(u2, v2);
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (gethsh(u1, v1, c1, mid) == gethsh(u2, v2, c2, mid)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    printf("%d\n", lo);
  }
}
