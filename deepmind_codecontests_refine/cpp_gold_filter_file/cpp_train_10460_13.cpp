#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int child[100010], n, m, a, b, level[100010], par[100010][18];
vector<long long> graph[100010];
void dfs(int node, int p) {
  int chd = 0;
  par[node][0] = p;
  level[node] = level[p] + 1;
  for (int i = 0; i < graph[node].size(); i++) {
    if (graph[node][i] != p) {
      dfs(graph[node][i], node);
      child[node] += child[graph[node][i]] + 1;
    }
  }
}
void bs() {
  if (level[a] > level[b]) swap(a, b);
  int diff = level[b] - level[a];
  int x = a;
  int y = b;
  if (diff % 2 == 1) {
    cout << "0\n";
    return;
  }
  for (int i = 0; diff >= (1 << i); i++) {
    if (diff & (1 << i)) b = par[b][i];
  }
  if (diff == 0) {
    if (x == y) {
      cout << n << '\n';
      return;
    }
    for (int i = 17; i >= 0; i--) {
      if (par[a][i] != par[b][i]) {
        a = par[a][i];
        b = par[b][i];
      }
    }
    cout << n - child[a] - child[b] - 2 << '\n';
  } else {
    if (a == b) {
      int u, v = y;
      for (int i = 0; (diff / 2 - 1) >= (1 << i); i++) {
        if ((diff / 2 - 1) & (1 << i)) v = par[v][i];
      }
      u = par[v][0];
      cout << child[u] - child[v] << '\n';
    } else {
      for (int i = 17; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
          a = par[a][i];
          b = par[b][i];
        }
      }
      int lvl = level[x] - level[par[a][0]] + diff / 2;
      int u, v = y;
      for (int i = 0; (lvl - 1) >= (1 << i); i++) {
        if ((lvl - 1) & (1 << i)) v = par[v][i];
      }
      u = par[v][0];
      cout << child[u] - child[v] << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(1, 0);
  for (int j = 1; j < 18; j++) {
    for (int i = 1; i <= n; i++) par[i][j] = par[par[i][j - 1]][j - 1];
  }
  cin >> m;
  while (m--) {
    cin >> a >> b;
    bs();
  }
}
