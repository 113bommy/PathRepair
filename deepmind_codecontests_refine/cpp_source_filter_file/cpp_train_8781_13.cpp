#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = inf + 7;
struct Edge {
  int to, cost, cap, id;
  Edge(int a1, int a2, int a3, int a4) {
    to = a1;
    cost = a2;
    cap = a3;
    id = a4;
  }
};
int A, B, n, b[300100], qe[300100], T, x, Ta, Res, S, m, d[300100], inq[300100],
    len, c[30];
vector<Edge> g[300100];
string second, t;
pair<int, int> p[300100];
void add(int u, int v, int cost, int cap) {
  Edge e1(v, cost, cap, (int)g[v].size());
  Edge e2(u, -cost, 0, (int)g[u].size());
  g[u].push_back(e1);
  g[v].push_back(e2);
}
bool djikstra() {
  for (int i = 0; i <= T; i++) d[i] = inf, inq[i] = 0;
  d[S] = 0;
  int l = 0, r = 0;
  qe[0] = S;
  while (l <= r) {
    int v = qe[l];
    l++;
    inq[v] = 0;
    for (int i = 0; i < (int)g[v].size(); i++) {
      int to = g[v][i].to;
      int cost = g[v][i].cost;
      int cap = g[v][i].cap;
      int id = g[v][i].id;
      if (cap > 0 && d[to] > d[v] + cost) {
        d[to] = d[v] + cost;
        p[to] = make_pair(v, i);
        if (!inq[to]) inq[to] = 1, qe[++r] = to;
      }
    }
  }
  return d[T] != inf;
}
int pref = 0;
void upd() {
  int v = T;
  int curf = inf;
  while (v != S) {
    int u = p[v].first;
    int id = p[v].second;
    curf = min(curf, g[u][id].cap);
    v = u;
  }
  v = T;
  while (v != S) {
    int u = p[v].first;
    int id = p[v].second;
    int rev = g[u][id].id;
    g[u][id].cap -= curf;
    Res += curf * g[u][id].cost;
    g[v][rev].cap += curf;
    v = u;
  }
  pref += curf;
}
int main() {
  cin >> second;
  cin >> m;
  int o = (m + 5) * 26;
  S = 0, T = o + 50;
  for (int z = 1; z <= m; z++) {
    cin >> t >> x;
    len = t.size();
    memset(c, 0, sizeof c);
    add(0, z, z, x);
    for (int i = 0; i < len; i++) c[t[i] - 'a' + 1]++;
    for (int i = 1; i <= 26; i++) {
      add(z, m + (z - 1) * 26 + i, 0, c[i]);
      add(m + (z - 1) * 26 + i, o + i, 0, inf);
    }
  }
  len = second.size();
  memset(c, 0, sizeof c);
  for (int i = 0; i < len; i++) c[second[i] - 'a' + 1]++;
  for (int i = 1; i <= 26; i++) add(o + i, T, 0, c[i]);
  while (djikstra()) {
    upd();
  }
  if (pref < m) {
    cout << -1;
    return 0;
  }
  printf("%d", Res);
  return 0;
}
