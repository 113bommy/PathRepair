#include <bits/stdc++.h>
using namespace std;
vector<int> g[610];
const int inf = 1e9;
struct edge {
  int from;
  int to;
  int cap;
  int flow;
  edge(int from, int to, int cap, int flow)
      : from(from), to(to), cap(cap), flow(flow) {}
  edge() {}
};
int s, t;
vector<edge> e;
vector<int> gr[2000];
void add_edge(int from, int to, int cap) {
  gr[from].push_back(e.size());
  e.push_back(edge(from, to, cap, 0));
  gr[to].push_back(e.size());
  e.push_back(edge(to, from, 0, 0));
}
int lvl[2000];
bool bfs() {
  queue<int> q;
  for (int i = s; i <= t; i++) lvl[i] = inf;
  q.push(s);
  lvl[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < gr[x].size(); i++) {
      int id = gr[x][i];
      if (lvl[e[id].to] > lvl[x] + 1 && e[id].cap > e[id].flow) {
        lvl[e[id].to] = lvl[x] + 1;
        q.push(e[id].to);
      }
    }
  }
  return lvl[t] < inf;
}
int pr[2000];
int dfs(int v, int flow) {
  if (!flow || v == t) return flow;
  for (; pr[v] < gr[v].size(); pr[v]++) {
    int id = gr[v][pr[v]];
    if (lvl[e[id].to] != lvl[v] + 1) continue;
    int f = dfs(e[id].to, min(flow, e[id].cap - e[id].flow));
    if (f) {
      e[id].flow += f;
      e[id ^ 1].flow -= f;
      return f;
    }
  }
  return 0;
}
int dinic() {
  int flow = 0;
  while (bfs()) {
    for (int i = s; i <= t; i++) pr[i] = 0;
    while (int f = dfs(s, inf)) {
      flow += f;
    }
  }
  return flow;
}
vector<int> ans[2000];
int res[2000];
void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  s = 0;
  t = n + m + 1;
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= m; i++) ans[i].clear();
  e.clear();
  for (int i = s; i <= t; i++) gr[i].clear();
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    add_edge(s, i, 3);
    add_edge(i, m + x, 2);
    add_edge(i, m + y, 2);
  }
  for (int i = 1; i <= n; i++) add_edge(m + i, t, 2 * k);
  if (dinic() != 3 * m) {
    for (int i = 1; i <= m; i++) printf("0 ");
    printf("\n");
    return;
  }
  for (int i = 0; i < e.size(); i += 2) {
    if (e[i].from == s || e[i].to == t) continue;
    if (e[i].flow == 1) ans[e[i].to - m].push_back(e[i].from);
  }
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)ans[i].size() - 1; j += 2)
      res[ans[i][j]] = res[ans[i][j + 1]] = cnt++;
    if (ans[i].size() % 2 == 1) res[ans[i].back()] = cnt++;
  }
  for (int i = 1; i <= m; i++) printf("%d ", res[i]);
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
