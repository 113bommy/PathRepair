#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " , ";
  __f(comma + 1, args...);
}
const int N = 2e5 + 10;
vector<int> g[N], par, height;
int n;
int bfs(int u) {
  int last = u;
  par[u] = -1;
  height[u] = 0;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    last = x;
    for (auto v : g[x])
      if (v != par[x]) {
        par[v] = x;
        height[v] = height[x] + 1;
        q.push(v);
      }
  }
  return last;
}
int main() {
  ios::sync_with_stdio(0);
  int i, j, k;
  cin >> n;
  par.resize(n);
  height.resize(n);
  for (i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int x = bfs(0);
  int y = bfs(x);
  int dia = height[y] - height[x] + 1;
  vector<int> path;
  int z = y;
  while (z != x) {
    path.push_back(z);
    z = par[z];
  }
  path.push_back(x);
  if ((int)path.size() == n) {
    cout << n - 1 << "\n";
    cout << path[0] + 1 << " " << path[1] + 1 << " " << path[2] + 1 << "\n";
    return 0;
  }
  queue<int> q;
  vector<int> vis(n);
  int last;
  for (i = 0; i < path.size(); ++i) {
    q.push(path[i]);
    vis[path[i]] = 1;
    height[path[i]] = 0;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    last = u;
    for (auto v : g[u])
      if (!vis[v]) {
        vis[v] = 1;
        height[v] = height[u] + 1;
        q.push(v);
      }
  }
  cout << dia + height[last] - 1 << "\n";
  cout << last + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
  return 0;
}
