#include <bits/stdc++.h>
using namespace std;
int n;
int m;
const int MAXN = 100000 + 10;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
int mark[MAXN];
set<pair<int, int> > Set;
vector<int> Comp[MAXN];
void IS_BRIDGE(int v1, int v2) {
  Set.insert(make_pair(v1, v2));
  Set.insert(make_pair(v2, v1));
}
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) IS_BRIDGE(v, to);
    }
  }
}
void find_bridges() {
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i);
}
int color = 0;
void dfsComp(int v) {
  mark[v] = color;
  for (int i = 0; i < g[v].size(); i++) {
    int v2 = g[v][i];
    if (mark[v2] == 0 && Set.find(make_pair(v, v2)) == Set.end()) {
      dfsComp(v2);
    }
  }
}
void make_comp() {
  for (int i = 0; i < n; i++) {
    if (mark[i] == 0) {
      ++color;
      mark[i] = color;
      dfsComp(i);
    }
  }
}
vector<int> V[MAXN];
void make_new_graph() {
  set<pair<int, int> >::iterator it = Set.begin();
  while (it != Set.end()) {
    int f = it->first;
    int s = it->second;
    V[mark[f]].push_back(mark[s]);
    it++;
  }
}
int kolMost[MAXN];
int markFin[MAXN];
void dfsFinish(int v, int kol, int st) {
  markFin[v] = 1;
  kolMost[v] = kol;
  if (kolMost[st] > -1) return;
  for (int i = 0; i < V[v].size(); i++) {
    if (markFin[V[v][i]] == 0) {
      dfsFinish(V[v][i], kol + 1, st);
    }
  }
}
int Finish(int v, int v2) {
  for (int i = 0; i <= n; i++) {
    markFin[i] = 0;
    kolMost[i] = -1;
  }
  dfsFinish(v, 0, v2);
  return kolMost[v2];
}
int main() {
  cin >> n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  find_bridges();
  make_comp();
  make_new_graph();
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << Finish(mark[x], mark[y]) << endl;
  }
  return 0;
}
