#include <bits/stdc++.h>
using namespace std;
const int maxn = 103;
int n, k;
struct card {
  int p, c, l;
  bool operator<(const card &o) const {
    if (c != o.c) return c > o.c;
    return p > o.p;
  }
};
;
vector<card> odd, even, v;
const int MAXN = 2005;
const int INF = 1000000000;
struct edge {
  int a, b, cap, flow;
};
int s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
void add_edge(int a, int b, int cap) {
  edge e1 = {a, b, cap, 0};
  edge e2 = {b, a, 0, 0};
  g[a].push_back((int)e.size());
  e.push_back(e1);
  g[b].push_back((int)e.size());
  e.push_back(e2);
}
bool bfs() {
  int qh = 0, qt = 0;
  q[qt++] = s;
  memset(d, -1, sizeof d);
  d[s] = 0;
  while (qh < qt && d[t] == -1) {
    int v = q[qh++];
    for (size_t i = 0; i < g[v].size(); ++i) {
      int id = g[v][i], to = e[id].b;
      if (d[to] == -1 && e[id].flow < e[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[t] != -1;
}
int dfs(int v, int flow) {
  if (!flow) return 0;
  if (v == t) return flow;
  for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
    int id = g[v][ptr[v]], to = e[id].b;
    if (d[to] != d[v] + 1) continue;
    int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
    if (pushed) {
      e[id].flow += pushed;
      e[id ^ 1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
int dinic() {
  int flow = 0;
  for (;;) {
    if (!bfs()) break;
    memset(ptr, 0, sizeof ptr);
    while (int pushed = dfs(s, INF)) flow += pushed;
  }
  return flow;
}
void clean() {
  for (int i = 0; i <= t; i++) g[i].clear();
  e.clear();
}
int markp[200015];
void criba() {
  long long n = 200005;
  for (long long i = 4; i <= n; i += 2) markp[i] = 1;
  for (long long i = 3; i <= n; i += 2) {
    if (markp[i]) continue;
    if (i * i > n) continue;
    for (long long j = i * i; j <= n; j += 2 * i) markp[j] = 1;
  }
}
bool can(int l) {
  vector<card> oddv, evenv;
  int sum = 0;
  for (auto i : odd)
    if (i.l <= l) oddv.push_back(i), sum += i.p;
  for (auto i : even)
    if (i.l <= l) evenv.push_back(i), sum += i.p;
  s = 0, t = oddv.size() + evenv.size() + 1;
  for (int i = 0; i < (int)oddv.size(); i++) add_edge(s, i + 1, oddv[i].p);
  for (int i = 0; i < (int)evenv.size(); i++)
    add_edge(oddv.size() + i + 1, t, evenv[i].p);
  for (int i = 0; i < (int)oddv.size(); i++) {
    for (int j = 0; j < (int)evenv.size(); j++) {
      int c = oddv[i].c + evenv[j].c;
      if (!markp[c]) add_edge(i + 1, oddv.size() + j + 1, INF);
    }
  }
  sum -= dinic();
  clean();
  return sum >= k;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  criba();
  cin >> n >> k;
  int p, c, l;
  for (int i = 1; i <= n; i++) {
    cin >> p >> c >> l;
    v.push_back(card{p, c, l});
  }
  sort(v.begin(), v.end());
  for (auto i : v) {
    if (i.c % 2 == 0)
      even.push_back(i);
    else
      odd.push_back(i);
    if (i.c == 1) break;
  }
  int ini = 1, fin = 1000;
  int sol = -1;
  while (ini <= fin) {
    int mit = (ini + fin) / 2;
    if (can(mit))
      sol = mit, fin = mit - 1;
    else
      ini = mit + 1;
  }
  cout << sol << "\n";
  return 0;
}
