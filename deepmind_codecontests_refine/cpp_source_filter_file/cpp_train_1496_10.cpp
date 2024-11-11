#include <bits/stdc++.h>
using namespace std;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int n, m, id;
vector<int> G[205], RG[205], assignment;
stack<int> st;
int vis[205];
void dfs1(int s) {
  vis[s] = 1;
  for (int i = 0; i < G[s].size(); i++) {
    int u = G[s][i];
    if (!vis[u]) dfs1(u);
  }
  st.push(s);
}
void dfs2(int s) {
  vis[s] = id;
  for (int i = 0; i < RG[s].size(); i++) {
    int u = RG[s][i];
    if (!vis[u]) dfs2(u);
  }
}
bool solve_2SAT() {
  for (int i = 1; i <= 2 * n; i++)
    if (!vis[i]) dfs1(i);
  memset(vis, 0, sizeof(vis));
  id = 1;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (!vis[u]) dfs2(u), id++;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == vis[i + n]) return false;
    if (vis[i] > vis[i + n]) assignment.push_back(i);
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (w) {
      G[u].push_back(v);
      G[u + n].push_back(v + n);
      G[v].push_back(u);
      G[v + n].push_back(u + n);
      RG[u].push_back(v);
      RG[u + n].push_back(v + n);
      RG[v].push_back(u);
      RG[v + n].push_back(u + n);
    } else {
      G[u].push_back(v + n);
      G[u + n].push_back(v);
      G[v].push_back(u + n);
      G[v + n].push_back(u);
      RG[u].push_back(v + n);
      RG[u + n].push_back(v);
      RG[v].push_back(u + n);
      RG[v + n].push_back(u);
    }
  }
  bool f = solve_2SAT();
  if (f) {
    cout << assignment.size() << '\n';
    for (int i = 0; i < assignment.size(); i++) cout << assignment[i] << ' ';
  } else {
    cout << "Impossible\n";
  }
}
