#include <bits/stdc++.h>
using namespace std;
ostream cnull(NULL);
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cnull << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cnull << *sdbg++;
  cnull << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
const int MX = 1e5 + 7, BLEP = 1 << 17;
vector<int> G[MX];
bool odw[MX];
int gora[MX], dol[MX], cykl[MX];
int up, down;
int t = -1, in[MX], out[MX], rev[MX], rep[MX], par[MX], rp[MX], depth[MX];
void findcykl(int u, int p) {
  par[u] = p;
  if (up != 0) return;
  odw[u] = 1;
  for (int v : G[u]) {
    if (v != p) {
      if (up != 0) return;
      if (odw[v] == 1) {
        up = v;
        down = u;
        return;
      } else
        findcykl(v, u);
    }
  }
}
struct segtree {
  int sum[BLEP << 1], bit[BLEP << 1], lazy[BLEP << 1];
  void removeLazy(int v, int l, int r) {
    int bylo = bit[v];
    bit[v] ^= lazy[v];
    if (bit[v] != bylo) sum[v] = (r - l + 1) - sum[v];
    if (v < BLEP) {
      lazy[2 * v] ^= lazy[v];
      lazy[2 * v + 1] ^= lazy[v];
    }
    lazy[v] = 0;
  }
  inline void insert(int a, int b, int v = 1, int l = 0, int r = BLEP - 1) {
    removeLazy(v, l, r);
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      lazy[v] ^= 1;
      removeLazy(v, l, r);
      return;
    }
    int sr = (l + r) / 2;
    insert(a, b, 2 * v, l, sr);
    insert(a, b, 2 * v + 1, sr + 1, r);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
  }
  inline int query(int a, int b, int v = 1, int l = 0, int r = BLEP - 1) {
    removeLazy(v, l, r);
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) {
      return sum[v];
    }
    int sr = (l + r) / 2;
    return query(a, b, 2 * v, l, sr) + query(a, b, 2 * v + 1, sr + 1, r);
  }
} drzewo;
void predfs(int u) {
  rp[u] = 1;
  for (int i = (0); i <= ((int)(((int)(G[u]).size())) - 1); ++i) {
    int v = G[u][i];
    if (v != par[u]) {
      par[v] = u;
      depth[v] = depth[u] + 1;
      if (cykl[v] == 0) cykl[v] = cykl[u];
      predfs(v);
      rp[u] += rp[v];
      if (rp[G[u][0]] < rp[v]) swap(G[u][0], G[u][i]);
    } else {
      G[u].erase(G[u].begin() + i);
      --i;
    }
  }
}
void hld(int u) {
  in[u] = ++t;
  rev[in[u]] = u;
  if (((int)(G[u]).size())) {
    rep[G[u][0]] = rep[u];
    hld(G[u][0]);
    for (int i = 1; i < ((int)(G[u]).size()); ++i) {
      int v = G[u][i];
      rep[v] = v;
      hld(v);
    }
  }
  out[u] = t;
}
int lca(int a, int b) {
  while (rep[a] != rep[b]) {
    if (depth[rep[a]] < depth[rep[b]]) swap(a, b);
    a = par[rep[a]];
  }
  if (depth[a] > depth[b]) swap(a, b);
  return a;
}
int dis(int a, int b) {
  int l = lca(a, b);
  return depth[a] + depth[b] - 2 * depth[l];
}
void sciezka(int v, int u) {
  while (rep[v] != rep[u]) {
    drzewo.insert(in[rep[v]], in[v]);
    v = par[rep[v]];
  }
  if (in[u] + 1 <= in[v]) drzewo.insert(in[u] + 1, in[v]);
}
void zamien(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  int l = lca(a, b);
  if (a == l)
    sciezka(b, a);
  else
    sciezka(a, l), sciezka(b, l);
}
int ile_cykl() {
  int v = down, u = up;
  int cnt = 0;
  while (rep[v] != rep[u]) {
    cnt += drzewo.query(in[rep[v]], in[v]);
    v = par[rep[v]];
  }
  if (in[u] + 1 <= in[v]) cnt += drzewo.query(in[u] + 1, in[v]);
  return cnt;
}
int32_t main() {
  int n, q;
  cin >> n >> q;
  for (int i = (0); i <= ((int)(n)-1); ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  findcykl(1, 0);
  int e = down, roz_cyklu = 1;
  while (e != up) {
    cykl[e] = e;
    dol[par[e]] = e;
    e = par[e];
    ++roz_cyklu;
  }
  cykl[up] = up;
  G[up].erase(find((G[up]).begin(), (G[up]).end(), down));
  G[down].erase(find((G[down]).begin(), (G[down]).end(), up));
  memset(par, 0, sizeof par);
  predfs(up);
  rep[up] = up;
  hld(up);
  bool powrotna = 0;
  while (q--) {
    int a, b;
    cin >> a >> b;
    int cA = a, cB = b;
    if (depth[cykl[a]] > depth[cykl[b]]) swap(a, b);
    int l = dis(a, b), l1 = dis(a, up) + dis(down, b) + 1;
    if (l < l1 || cykl[a] == cykl[b]) {
      zamien(a, b);
    } else if (l1 < l) {
      powrotna ^= 1;
      zamien(a, up);
      zamien(b, down);
    } else {
      int x = cykl[cA], y = cykl[cB];
      int n1 = (x == up ? down : par[x]), n2 = (x == down ? up : dol[x]);
      if (depth[y] < depth[x]) swap(n1, n2);
      if (n1 < n2) {
        powrotna ^= 1;
        zamien(a, up), zamien(b, down);
      } else
        zamien(a, b);
    }
    int kraw = drzewo.query(in[up], out[up]) + powrotna;
    if (powrotna && ile_cykl() == roz_cyklu - 1) --kraw;
    cout << n - kraw << '\n';
  }
}
