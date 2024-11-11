#include <bits/stdc++.h>
using namespace std;
int n, p;
bool visited[1002];
int par[1002];
vector<pair<int, int>> g[1002];
set<pair<int, pair<int, int>>> s;
int tmin = INT_MAX, t = 0;
void dfs(int x, int b) {
  visited[x] = 1;
  if (par[x] != 0 && g[x].size() == 0) {
    t++;
    s.insert(make_pair(b, make_pair(x, tmin)));
    return;
  }
  for (auto it : g[x]) {
    tmin = min(tmin, it.second);
    if (visited[it.first] == 0) dfs(it.first, b);
  }
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < p; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    par[v] = u;
  }
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0 && par[i] == 0) {
      tmin = INT_MAX;
      dfs(i, i);
    }
  }
  cout << t << endl;
  for (auto a : s) {
    cout << a.first << ' ' << a.second.first << ' ' << a.second.second << endl;
  }
}
