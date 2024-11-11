#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
using namespace std;
struct edge {
  int from, to, cap, flow;
  edge() {}
  edge(int from, int to, int cap, int flow)
      : from(from), to(to), cap(cap), flow(flow) {}
};
vector<int> g[100000];
vector<edge> e;
const int inf = 1e9;
int d[100000], s, t, last[100000];
int N;
void add_edge(int from, int to, int cap) {
  g[from].push_back(e.size());
  e.push_back(edge(from, to, cap, 0));
  g[to].push_back(e.size());
  e.push_back(edge(to, from, 0, 0));
}
bool bfs() {
  memset(d, -1, sizeof d[0] * N);
  queue<int> q;
  d[s] = 0;
  q.push(s);
  while (!q.empty() && d[t] == -1) {
    int v = q.front();
    q.pop();
    for (auto it = g[v].begin(); it != g[v].end(); it++) {
      if (e[*it].flow >= e[*it].cap || d[e[*it].to] != -1) continue;
      d[e[*it].to] = d[v] + 1;
      q.push(e[*it].to);
    }
  }
  return (d[t] != -1);
}
int dfs(int v, int flow) {
  if (v == t || flow == 0) return flow;
  for (last[v]; last[v] < g[v].size(); last[v]++) {
    int cur = g[v][last[v]];
    if (e[cur].flow >= e[cur].cap || d[e[cur].to] != d[v] + 1) continue;
    int cur_flow = min(flow, e[cur].cap - e[cur].flow);
    int pushed = dfs(e[cur].to, cur_flow);
    if (pushed != 0) {
      e[cur].flow += pushed;
      e[cur ^ 1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
int dinic() {
  int max_flow = 0;
  while (bfs()) {
    memset(last, 0, sizeof last[0] * N);
    while (int pushed = dfs(s, inf)) max_flow += pushed;
  }
  return max_flow;
}
int n, a[200];
void bad() {
  puts("Impossible");
  exit(0);
}
bool vis[200];
vector<vector<int>> ans;
int main() {
  scanf("%d", &n);
  int cnt = 0;
  s = 0;
  t = n + 1;
  N = t + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] & 1)
      add_edge(s, i, 2);
    else
      add_edge(i, t, 2), cnt++;
  }
  if (cnt * 2 != n) bad();
  for (int i = 1; i <= n; i++) {
    if (a[i] & 1)
      for (int j = 1; j <= n; j++) {
        if (i == j || a[j] & 1) continue;
        int sum = a[i] + a[j];
        bool prime = true;
        for (int x = 2; x * x <= sum; x++)
          if (sum % x == 0) {
            prime = false;
            break;
          }
        if (prime) add_edge(i, j, 1);
      }
  }
  if (dinic() != n) bad();
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    ans.push_back(vector<int>());
    int cur = i, prev = -1;
    while (!vis[cur]) {
      ans.back().push_back(cur);
      vis[cur] = true;
      for (auto it = g[cur].begin(); it != g[cur].end(); it++) {
        if (e[*it].flow == 0) continue;
        int to = e[*it].to;
        if (to == prev || to == s || to == t) continue;
        prev = cur;
        cur = to;
        break;
      }
    }
  }
  printf("%d\n", ans.size());
  for (auto it = ans.begin(); it != ans.end(); it++) {
    printf("%d ", it->size());
    for (auto cur_it = it->begin(); cur_it != it->end(); cur_it++)
      printf("%d ", *cur_it);
    printf("\n");
  }
  return 0;
}
