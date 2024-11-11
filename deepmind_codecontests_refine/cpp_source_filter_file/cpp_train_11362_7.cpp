#include <bits/stdc++.h>
using namespace std;
const int nsz = 5e5;
const string win = "White", draw = "Draw", lose = "Black";
bool vis[nsz + 5];
char s[nsz + 5];
int ts, n, m, pw3[nsz + 5], d[nsz + 5], pr[nsz + 5];
vector<int> g[nsz + 5];
int inline at(int S, int id) { return S / pw3[id] % 3; }
int inline chg(int S, int id, int w) { return S += (w - at(S, id)) * pw3[id]; }
string inline tri(int S) {
  string s;
  for (int i = 0; i < n; ++i) s += at(S, i) ^ 48;
  return s;
}
bool inline chk_win(int S, int d) {
  for (int u = 0; u < n; ++u)
    if (at(S, u) == d) {
      vector<int> &nei = ::g[u + 1];
      for (int i = 0; i < nei.size(); ++i)
        for (int j = 0; j <= i - 1; ++j) {
          int v = nei[i] - 1, w = nei[j] - 1;
          if (at(S, v) == d && at(S, w) == d) return 1;
        }
    }
  return 0;
}
int inline nxt(int d) { return d == 2 ? 1 : 2; }
int go(int S, int d) {
  bool can_draw = 0, can_place = 0;
  for (int u = 0; u < n; ++u)
    if (at(S, u) == 0) {
      int nS = chg(S, u, d);
      if (chk_win(nS, d)) return 1;
      int f = go(nS, nxt(d));
      if (f == -1) return 1;
      can_draw |= f == 0;
      can_place = 1;
    }
  can_draw |= !can_place;
  return can_draw ? 0 : -1;
}
void inline solve_trivial() {
  pw3[0] = 1;
  for (int i = 1; i <= n; ++i) pw3[i] = pw3[i - 1] * 3;
  int S = 0;
  for (int i = 1; i <= n; ++i)
    if (vis[i]) S = chg(S, i - 1, 1);
  int res = chk_win(S, 1) ? 1 : go(S, 1);
  if (res == -1)
    return (void)printf("%s\n", lose.c_str());
  else if (res == 0)
    return (void)printf("%s\n", draw.c_str());
  else if (res == 1)
    return (void)printf("%s\n", win.c_str());
}
void inline bfs(int s, int *d) {
  static int q[nsz + 5];
  int ql = 0, qr = 0;
  for (int u = 1; u <= n; ++u) d[u] = -1;
  for (q[qr++] = s, d[s] = 0; ql != qr;) {
    int u = q[ql++];
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i];
      if (d[v] == -1) d[v] = d[u] + 1, q[qr++] = v;
    }
  }
}
void dfs(int u) {
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == pr[u]) continue;
    pr[v] = u;
    dfs(v);
  }
}
void inline solve_I(int u1, int u2) {
  for (int u = 1; u <= n; ++u)
    if (u != u1 && u != u2 && vis[u])
      return (void)(printf("%s\n", win.c_str()));
  if (vis[u1] && vis[u2] && (n & 1)) return (void)(printf("%s\n", win.c_str()));
  return (void)(printf("%s\n", draw.c_str()));
}
void inline solve_Y(int u1) {
  for (int u = 1; u <= n; ++u)
    if (u != u1 && vis[u]) return (void)(printf("%s\n", win.c_str()));
  if (vis[u1] && (n % 2 == 0)) return (void)(printf("%s\n", win.c_str()));
  return (void)(printf("%s\n", draw.c_str()));
}
void inline solve_X() {
  if (m >= 1) return (void)(printf("%s\n", win.c_str()));
  if (n & 1) return (void)(printf("%s\n", win.c_str()));
  return (void)(printf("%s\n", draw.c_str()));
}
void inline solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i)
    if (s[i] == 'W') vis[i] = 1, ++m;
  if (n <= 2) return (void)(printf("%s\n", draw.c_str()));
  for (int u = 1; u <= n; ++u)
    if (g[u].size() > 3) return (void)(printf("%s\n", win.c_str()));
  if (n <= 5) return (void)(solve_trivial());
  int p1 = 1, p2 = 1;
  bfs(p1, d);
  for (int u = 1; u <= n; ++u)
    if (d[u] > d[p2]) p2 = u;
  bfs(p2, d);
  for (int u = 1; u <= n; ++u)
    if (d[u] > d[p1]) p1 = u;
  dfs(p1);
  vector<int> nd;
  for (int u = p2; u != p1; u = pr[u]) nd.push_back(u);
  nd.push_back(p1);
  for (int i = 0; i < nd.size(); ++i) {
    int u = nd[i];
    if (i != 0 && i + 1 != nd.size() && i != 1 && i + 2 != nd.size()) {
      if (g[u].size() > 2) return (void)(printf("%s\n", win.c_str()));
    }
  }
  int u1 = nd[1], u2 = nd[nd.size() - 2];
  int v1 = nd[0], v2 = nd[nd.size() - 1];
  int k1 = g[u1].size(), k2 = g[u2].size();
  if (k1 > k2) swap(k1, k2), swap(u1, u2), swap(v1, v2);
  if (k1 == 2 && k2 == 2) return (void)(solve_I(v1, v2));
  if (k1 == 2 && k2 == 3) return (void)(solve_Y(v1));
  if (k1 == 3 && k2 == 3) return (void)(solve_X());
}
void inline clear() {
  for (int u = 1; u <= n; ++u) g[u].clear(), pr[u] = -1, vis[u] = 0;
}
int main() {
  scanf("%d", &ts);
  for (int cs = 1; cs <= ts; ++cs) {
    solve();
    clear();
  }
  return 0;
}
