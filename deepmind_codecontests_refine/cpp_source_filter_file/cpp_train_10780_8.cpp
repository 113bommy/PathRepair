#include <bits/stdc++.h>
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
const int limit = 1048576;
using namespace std;
namespace mincost {
const int V = 510, E = 51000, inf = 0x20202020;
int dis[V], q[V * 300], vis[V], fst[V], pre[V], nxt[E], y[E], f[E], c[E], S, T,
    flow, cost, tot, tn;
void init(int s, int t, int Tn) {
  tot = 1;
  tn = Tn;
  for (long long i = (long long)0; i < (long long)tn; i++) fst[i] = 0;
  S = s;
  T = t;
}
void add(int u, int v, int ff, int cc) {
  tot++;
  y[tot] = v;
  nxt[tot] = fst[u];
  f[tot] = ff;
  c[tot] = cc;
  fst[u] = tot;
  tot++;
  y[tot] = u;
  nxt[tot] = fst[v];
  f[tot] = 0;
  c[tot] = -cc;
  fst[v] = tot;
}
bool spfa() {
  for (long long i = (long long)0; i < (long long)tn; i++)
    dis[i] = inf, vis[i] = 0, pre[i] = 0;
  dis[S] = 0;
  q[0] = S;
  vis[S] = 1;
  int t = 1;
  for (long long i = (long long)0; i < (long long)t; i++) {
    int u = q[i];
    for (int j = fst[u]; j; j = nxt[j]) {
      int v = y[j];
      if (f[j] && dis[v] > dis[u] + c[j]) {
        dis[v] = dis[u] + c[j];
        pre[v] = j;
        if (!vis[v]) vis[v] = 1, q[t++] = v;
      }
    }
    vis[u] = 0;
  }
  return dis[T] != inf;
}
void augment() {
  int p = T, _f = inf;
  while (pre[p]) _f = min(_f, f[pre[p]]), p = y[pre[p] ^ 1];
  flow += _f;
  cost += _f * dis[T];
  p = T;
  while (pre[p]) f[pre[p]] -= _f, f[pre[p] ^ 1] += _f, p = y[pre[p] ^ 1];
}
void solve() {
  flow = 0, cost = 0;
  while (spfa()) augment();
}
}  // namespace mincost
using namespace mincost;
int main() {
  int n;
  string s;
  cin >> n >> s;
  init(0, (int)((s).size()) + 1, 3 + (int)((s).size()));
  for (int i = 1; i <= (int)((s).size()); i++) add(i + 1, i + 2, inf, 0);
  int m;
  cin >> m;
  while (m--) {
    int p;
    string z;
    cin >> z >> p;
    for (int i = 0; i + (int)((z).size()) <= (int)((s).size()); i++) {
      bool ok = true;
      for (int j = i; j < i + (int)((z).size()); j++)
        if (z[j - i] != s[j]) ok = false;
      if (ok) add(i + 2, i + 2 + (int)((z).size()), 1, -p);
    }
  }
  int x;
  cin >> x;
  add(1, 2, x, 0);
  solve();
  int ans = cost;
  cout << -ans;
  return 0;
}
