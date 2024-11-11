#include <bits/stdc++.h>
using namespace std;
const int MAX = 500010;
int n, m;
int seg[MAX];
int vis[MAX];
int p[MAX];
int in[MAX], out[MAX];
int aux = 0;
vector<int> adj[MAX];
set<int> s;
void dfs(int x) {
  in[x] = ++aux;
  for (int i = 0; i < adj[x].size(); i++) {
    int u = adj[x][i];
    if (!p[u]) {
      p[u] = x;
      dfs(u);
    }
  }
  out[x] = ++aux;
  if (adj[x].size() <= 1) s.insert(in[x]);
  return;
}
bool check(int x) {
  auto it = s.lower_bound(in[x]);
  if (it == s.end()) return 0;
  if (*it <= out[x]) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  p[1] = -1;
  dfs(1);
  cin >> m;
  int c, x;
  for (int i = 0; i < m; i++) {
    cin >> c >> x;
    if (c == 1) {
      if (check(p[x]) && p[x]) s.insert(in[p[x]]);
      auto iti = s.lower_bound(in[x]);
      auto ito = s.upper_bound(out[x]);
      s.erase(iti, ito);
    } else if (c == 2)
      s.insert(in[x]);
    else if (check(x))
      cout << "0\n";
    else
      cout << "1\n";
  }
}
