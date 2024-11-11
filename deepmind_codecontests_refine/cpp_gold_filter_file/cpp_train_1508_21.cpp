#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, next, cap;
  edge(int u = 0, int v = 0, int next = 0, int cap = 0)
      : u(u), v(v), next(next), cap(cap) {}
};
int S, T, n, table, ages[201], layer[201];
bool mk[100050], used[10050];
vector<int> ctr[2], gr[300], tables[201];
vector<int> last;
vector<edge> g;
void criba() {
  mk[0] = mk[1] = true;
  for (int i = 4; i <= 100001; i += 2) mk[i] = true;
  for (int i = 3; i * i <= 100001; i += 2) {
    if (!mk[i]) {
      for (int j = i * i; j <= 100001; j += (i << 1)) {
        mk[j] = true;
      }
    }
  }
}
bool is_prime(int num) { return !mk[num]; }
void create_edge(int u, int v, int cap) {
  g.push_back(edge(u, v, last[u], cap));
  last[u] = g.size() - 1;
  g.push_back(edge(v, u, last[v]));
  last[v] = g.size() - 1;
}
bool bfs() {
  fill(layer, layer + T + 1, -1);
  layer[T] = 0;
  queue<int> q;
  q.push(T);
  while (!q.empty()) {
    int nod = q.front();
    q.pop();
    for (int e = last[nod]; e != -1; e = g[e].next) {
      edge &back_w = g[e ^ 1];
      if (back_w.cap > 0 && layer[back_w.u] == -1) {
        layer[back_w.u] = layer[back_w.v] + 1;
        q.push(back_w.u);
      }
    }
  }
  return layer[S] > -1;
}
int dfs(int nod, int flow) {
  if (nod == T) return flow;
  for (int e = last[nod]; e != -1; e = g[e].next) {
    edge &fore_w = g[e];
    edge &back_w = g[e ^ 1];
    if (fore_w.cap > 0 && layer[fore_w.u] == layer[fore_w.v] + 1) {
      int f = dfs(fore_w.v, min(flow, fore_w.cap));
      if (f > 0) {
        fore_w.cap -= f;
        back_w.cap += f;
        return f;
      }
    }
  }
  return 0;
}
int dinic() {
  int flow = 0, f = 0;
  while (bfs())
    while ((f = dfs(S, INT_MAX)) > 0) flow += f;
  return flow;
}
void fill_table(int t_id, int st) {
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int nod = q.front();
    q.pop();
    if (used[nod]) continue;
    used[nod] = true;
    tables[t_id].push_back(nod);
    for (int i = 0; i < gr[nod].size(); i++) {
      int newn = gr[nod][i];
      if (used[newn]) continue;
      q.push(newn);
      break;
    }
  }
}
int main() {
  criba();
  scanf("%d", &n);
  S = 0, T = n + 1;
  if (n & 1) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ages[i]);
    ctr[ages[i] & 1].push_back(i);
  }
  if (ctr[0].size() != ctr[1].size()) {
    printf("Impossible\n");
    return 0;
  }
  last.resize(T + 1, -1);
  for (int i = 0; i < ctr[0].size(); i++) {
    create_edge(S, ctr[0][i], 2);
    for (int j = 0; j < ctr[1].size(); j++) {
      if (is_prime(ages[ctr[0][i]] + ages[ctr[1][j]])) {
        create_edge(ctr[0][i], ctr[1][j], 1);
      }
    }
  }
  for (int j = 0; j < ctr[1].size(); j++) {
    create_edge(ctr[1][j], T, 2);
  }
  int flw = dinic();
  if (flw != n) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = 0; i < g.size(); i++) {
    if ((g[i].u == S && g[i].cap != 0) || (g[i].v == T && g[i].cap != 0)) {
      printf("Impossible\n");
      return 0;
    }
    if (g[i].u == S && g[i].u == T && g[i].v == S && g[i].v == T) continue;
    if (!(ages[g[i].u] & 1) && (ages[g[i].v] & 1) && g[i].cap == 0) {
      gr[g[i].u].push_back(g[i].v);
      gr[g[i].v].push_back(g[i].u);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    fill_table(table++, i);
  }
  printf("%d", table);
  for (int i = 0; i < table; i++) {
    printf("\n%d", tables[i].size());
    for (int j = 0; j < tables[i].size(); j++) {
      printf(" %d", tables[i][j]);
    }
  }
  return 0;
}
