#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > v[400100];
pair<int, int> Ans[400100];
set<pair<int, int> > Bridges;
vector<pair<int, int> > All;
bool vis[400100];
int cnt = 0, num[400100], low[400100], Size[400100], par[400100], Answer = 1,
    Node = 1;
void init() {
  for (int i = 1; i <= n; i++) par[i] = i, Size[i] = 1;
}
int getparent(int x) {
  if (x == par[x]) return x;
  return par[x] = getparent(par[x]);
}
void Merge(int x, int y) {
  x = getparent(x);
  y = getparent(y);
  if (x == y) return;
  if (Size[x] < Size[y]) swap(x, y);
  Size[x] += Size[y];
  if (Size[x] > Answer) {
    Answer = Size[x];
    Node = x;
  }
  par[y] = x;
}
void BridgeDFS(int u) {
  num[u] = low[u] = cnt++;
  for (int i = 0; i < v[u].size(); i++) {
    int nxt = v[u][i].first;
    if (num[nxt] == -1) {
      par[nxt] = u;
      BridgeDFS(nxt);
      if (num[u] < low[nxt]) Bridges.insert({u, nxt}), Bridges.insert({nxt, u});
      low[u] = min(low[u], low[nxt]);
    } else if (par[u] != nxt)
      low[u] = min(low[u], num[nxt]);
  }
}
void DFS(int x) {
  vis[x] = true;
  for (int i = 0; i < v[x].size(); i++) {
    int nxt = v[x][i].first;
    if (getparent(x) == getparent(nxt))
      Ans[v[x][i].second] = {nxt, x};
    else
      Ans[v[x][i].second] = {x, nxt};
    if (!vis[nxt]) DFS(v[x][i].first);
  }
}
int main() {
  memset(num, -1, sizeof(num));
  memset(par, -1, sizeof(par));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back({y, i});
    v[y].push_back({x, i});
    All.push_back({x, y});
  }
  BridgeDFS(1);
  init();
  for (auto x : All) {
    if (Bridges.find(x) == Bridges.end()) Merge(x.first, x.second);
  }
  DFS(Node);
  printf("%d\n", Answer);
  for (int i = 0; i < m; i++) printf("%d %d\n", Ans[i].first, Ans[i].second);
  return 0;
}
