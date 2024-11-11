#include <bits/stdc++.h>
using namespace std;
const int inf = 100000002;
struct ver {
  int p = 0;
  int h = 0;
  bool v = false;
};
void dfs(vector<vector<int> > &graph, vector<ver> &sol, int st, int &v) {
  int mi = graph.size(), ma = 0;
  sol[st].v = true;
  for (int j = 0; j < graph[st].size(); ++j) {
    int i = graph[st][j];
    if (sol[i].v) continue;
    sol[i].p = st;
    dfs(graph, sol, i, v);
    mi = min(mi, sol[i].h);
    ma = max(ma, sol[i].h);
  }
  if (ma != mi && mi < graph.size() && (v == -1)) v = st;
  sol[st].h = ma + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, q;
  cin >> n;
  vector<vector<int> > gr(n);
  vector<ver> sol(n), ssol(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  int v = -1, u = -1;
  dfs(gr, sol, 0, v);
  if (v == -1) v = 0;
  dfs(gr, ssol, v, u);
  if (u == -1) u = v;
  int mi = n, ma = 0;
  for (int j = 0; j < gr[v].size(); ++j) {
    int x = ssol[gr[v][j]].h;
    mi = min(mi, x);
    ma = max(ma, x);
  }
  bool ans = 1;
  for (int j = 0; j < gr[v].size(); ++j) {
    if ((ssol[gr[v][j]].h < ma) && (ssol[gr[v][j]].h > mi)) ans = 0;
  }
  ans = (v == u) && ans;
  int l = ma;
  if (ma != mi) l += mi;
  while (l % 2 == 0) l = l / 2 + 1;
  cout << (ans ? l : -1) << "\n";
  return 0;
}
