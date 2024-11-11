#include <bits/stdc++.h>
using namespace std;
const int N_ = 50005;
const int E_ = 200005;
const int C = 600;
int n, M, Q, o, st[N_], online_adj_light[N_];
vector<int> G[N_];
vector<int> adj_heavy[N_];
map<int, int> E[N_];
void add_edge(int u, int v) {
  G[u].push_back(v);
  E[u].insert(pair<int, int>(v, (int)(G[(u)].size()) - 1));
  if ((int)(G[(u)].size()) <= C)
    if (st[u]) online_adj_light[v]++;
  if ((int)(G[(u)].size()) == C)
    for (int i = 0; i < (int)(G[(u)].size()); i++) {
      int w = G[u][i];
      if (w > 0) {
        online_adj_light[w] -= st[u];
        adj_heavy[w].push_back(u);
      } else
        adj_heavy[-w].push_back(-u);
    }
  if ((int)(G[(u)].size()) > C) adj_heavy[v].push_back(u);
}
void modify_edge(int u, int v) {
  int e = E[u][v];
  G[u][e] *= -1;
  if ((int)(G[(u)].size()) < C)
    if (st[u]) online_adj_light[v] += (G[u][e] > 0 ? +1 : -1);
  if ((int)(G[(u)].size()) >= C)
    for (int i = 0; i < (int)adj_heavy[v].size(); i++) {
      int &w = adj_heavy[v][i];
      if (w == -u) {
        w = u;
        return;
      }
      if (w == u) {
        w = -u;
        return;
      }
    }
}
int main() {
  cin >> n >> M >> Q >> o;
  for (int i = 1; i <= n; i++) st[i] = 0;
  for (int i = 1; i <= o; i++) {
    int u;
    scanf("%d", &u);
    st[u] = 1;
  }
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v), add_edge(v, u);
  }
  while (Q--) {
    char q;
    scanf(" %c", &q);
    if ((q == 'O') || (q == 'F')) {
      int u;
      scanf("%d", &u);
      st[u] = (q == 'O');
      if ((int)(G[(u)].size()) < C)
        for (int i = 0; i < (int)(G[(u)].size()); i++) {
          int w = G[u][i];
          if (w > 0) online_adj_light[w] += (st[u] ? +1 : -1);
        }
    }
    if (q == 'A') {
      int u, v;
      scanf("%d%d", &u, &v);
      if (E[u].count(v) == 0)
        add_edge(u, v), add_edge(v, u);
      else
        modify_edge(u, v), modify_edge(v, u);
    }
    if (q == 'D') {
      int u, v;
      scanf("%d%d", &u, &v);
      modify_edge(u, v), modify_edge(v, u);
    }
    if (q == 'C') {
      int u;
      scanf("%d", &u);
      int ans = online_adj_light[u];
      for (int i = 0; i < (int)adj_heavy[u].size(); i++) {
        int w = adj_heavy[u][i];
        if (w > 0) ans += st[w];
      }
      printf("%d\n", ans);
    }
  }
}
