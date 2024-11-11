#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
vector<int> cycle, cur, adj[100009];
int vis[100009], parent[100009], c, n;
int no, ata[100009], chain[100009], pos[100009], sub[100009], TIM;
int par[100009][19], lvl[100009], ps[100009], cep[100009], sag[100009];
void dfs(int nd, int pr) {
  if (!cycle.empty()) return;
  if (vis[nd]) {
    cycle.push_back(nd);
    c = 1;
    while (cur.back() != nd) cycle.push_back(cur.back()), cur.pop_back(), c++;
    return;
  }
  cur.push_back(nd);
  vis[nd] = true;
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr) continue;
    dfs(to, nd);
  }
  cur.pop_back();
}
void dfs2(int nd, int pr) {
  if (ata[no] == -1) ata[no] = nd;
  pos[nd] = ++TIM;
  chain[nd] = no;
  int mx = 0, who = -1;
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr or vis[to]) continue;
    if (umax(mx, sub[to])) who = to;
  }
  if (~who) dfs2(who, nd);
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr or vis[to] or to == who) continue;
    no++;
    dfs2(to, nd);
  }
}
void dfs1(int nd, int pr) {
  if (~pr) {
    parent[nd] = parent[pr];
    lvl[nd] = lvl[pr] + 1;
  }
  par[nd][0] = pr;
  sub[nd] = 1;
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr or vis[to]) continue;
    dfs1(to, nd);
    sub[nd] += sub[to];
  }
}
void create() {
  for (int j = 1; j <= 17; j++)
    for (int i = 1; i <= n; i++)
      if (~par[i][j - 1]) par[i][j] = par[par[i][j - 1]][j - 1];
}
int LCA(int x, int y) {
  if (lvl[x] < lvl[y]) swap(x, y);
  for (int i = 17; i >= 0; i--)
    if (~par[x][i] and lvl[x] - (1 << i) >= lvl[y]) x = par[x][i];
  if (x == y) return x;
  for (int i = 17; i >= 0; i--)
    if (~par[x][i] and par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
  return par[x][0];
}
struct tree {
  pair<int, int> s[100009 << 2];
  bool lazy[100009 << 2];
  void build(int nd, int x, int y) {
    lazy[nd] = 0;
    if (x == y) {
      s[nd].first = 1;
      s[nd].second = 0;
      return;
    }
    int mid = (x + y) >> 1;
    build(nd << 1, x, mid);
    build(nd << 1 | 1, mid + 1, y);
    s[nd].first = s[nd << 1].first + s[nd << 1 | 1].first;
    s[nd].second = s[nd << 1].second + s[nd << 1 | 1].second;
  }
  void shift(int nd) {
    if (lazy[nd]) {
      swap(s[nd << 1].first, s[nd << 1].second);
      swap(s[nd << 1 | 1].first, s[nd << 1 | 1].second);
      lazy[nd << 1] = lazy[nd << 1] xor 1;
      lazy[nd << 1 | 1] = lazy[nd << 1 | 1] xor 1;
      lazy[nd] = 0;
    }
  }
  void upd(int l, int r, int nd, int x, int y) {
    if (l > r or l > y or x > r) return;
    if (l <= x and y <= r) {
      swap(s[nd].first, s[nd].second);
      lazy[nd] = lazy[nd] xor 1;
      return;
    }
    shift(nd);
    int mid = (x + y) >> 1;
    upd(l, r, nd << 1, x, mid);
    upd(l, r, nd << 1 | 1, mid + 1, y);
    s[nd].first = s[nd << 1].first + s[nd << 1 | 1].first;
    s[nd].second = s[nd << 1].second + s[nd << 1 | 1].second;
  }
} C, P;
void change(int x, int y) {
  while (1) {
    if (chain[x] == chain[y]) {
      P.upd(pos[y] + 1, pos[x], 1, 1, TIM);
      return;
    }
    P.upd(pos[ata[chain[x]]], pos[x], 1, 1, TIM);
    x = par[ata[chain[x]]][0];
  }
}
void solve(int u, int v) {
  int k = LCA(u, v);
  if (u == k)
    change(v, k);
  else if (v == k)
    change(u, k);
  else {
    change(v, k);
    change(u, k);
  }
}
void solve1(int v, int u) {
  int vv = ps[v], uu = ps[u];
  if (vv < uu) {
    if (uu - vv < vv + c - uu)
      C.upd(vv, uu - 1, 1, 1, c);
    else if (uu - vv > vv + c - uu) {
      C.upd(1, vv - 1, 1, 1, c);
      C.upd(uu, c, 1, 1, c);
    } else {
      if (cep[v] < sag[v]) {
        C.upd(1, vv - 1, 1, 1, c);
        C.upd(uu, c, 1, 1, c);
      } else
        C.upd(vv, uu - 1, 1, 1, c);
    }
  } else {
    if (vv - uu < uu + c - vv)
      C.upd(uu, vv - 1, 1, 1, c);
    else if (vv - uu > uu + c - vv) {
      C.upd(1, uu - 1, 1, 1, c);
      C.upd(vv, c, 1, 1, c);
    } else {
      if (cep[v] < sag[v])
        C.upd(uu, vv - 1, 1, 1, c);
      else {
        C.upd(1, uu - 1, 1, 1, c);
        C.upd(vv, c, 1, 1, c);
      }
    }
  }
}
int main() {
  memset(ata, -1, sizeof ata);
  memset(par, -1, sizeof par);
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  assert(c >= 3);
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < int(cycle.size()); i++) {
    ps[cycle[i]] = i + 1;
    vis[cycle[i]] = 1;
    if (i)
      cep[cycle[i]] = cycle[i - 1];
    else
      cep[cycle[i]] = cycle.back();
    if (i + 1 < c)
      sag[cycle[i]] = cycle[i + 1];
    else
      sag[cycle[i]] = cycle[0];
  }
  for (__typeof((cycle).begin()) it = (cycle).begin(); it != (cycle).end();
       it++) {
    no++;
    parent[*it] = *it;
    lvl[*it] = 1;
    dfs1(*it, -1);
    dfs2(*it, -1);
  }
  create();
  P.build(1, 1, TIM);
  C.build(1, 1, c);
  while (q--) {
    int v, u;
    scanf("%d%d", &v, &u);
    if (u == v) {
      printf("%d\n",
             n - (P.s[1].second + C.s[1].second) + (C.s[1].second == c));
      continue;
    }
    if (parent[u] == parent[v])
      solve(u, v);
    else {
      if (vis[v]) {
        if (vis[u])
          solve1(v, u);
        else {
          solve1(v, parent[u]);
          solve(parent[u], u);
        }
      } else {
        if (vis[u]) {
          solve(v, parent[v]);
          solve1(parent[v], u);
        } else {
          solve(v, parent[v]);
          solve1(parent[v], parent[u]);
          solve(parent[u], u);
        }
      }
    }
    printf("%d\n", n - (P.s[1].second + C.s[1].second) + (C.s[1].second == c));
  }
  return 0;
}
