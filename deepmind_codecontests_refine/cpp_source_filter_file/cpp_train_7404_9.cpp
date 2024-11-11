#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005], roots;
int M1[1005], M[1005], dep[1005];
bool vis[1005];
int par[1005];
vector<pair<int, int>> add;
set<pair<int, int>> s;
void dfs(int i, int p, int d) {
  par[i] = p;
  vis[i] = 1;
  dep[i] = d;
  M[i] = M1[i] = i;
  for (auto j : adj[i])
    if (j != p) {
      dfs(j, i, d + 1);
      if (dep[M[j]] > dep[M[i]])
        M1[i] = M[i], M[i] = M[j];
      else if (dep[M[j]] > dep[M1[i]])
        M1[i] = M[j];
    }
}
int get_center(int r) {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  dfs(r, r, 1);
  int diam = -1;
  int opti = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i]) {
      if (dep[M[i]] + dep[M1[i]] - 2 * dep[i] > diam)
        diam = dep[M[i]] + dep[M1[i]] - 2 * dep[i], opti = i;
    }
  int x = M[opti], y = M1[opti];
  vector<int> a, b;
  while (y != opti) {
    a.push_back(y);
    y = par[y];
  }
  a.push_back(opti);
  reverse(a.begin(), a.end());
  while (x != opti) {
    b.push_back(x);
    x = par[x];
  }
  for (auto j : a) b.push_back(j);
  return b[b.size() / 2];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      dfs(i, i, 1);
      int diam = -1;
      for (int ii = 1; ii <= n; ii++)
        if (dep[M[ii]] + dep[M1[ii]] - 2 * dep[ii] > diam)
          diam = dep[M[ii]] + dep[M1[ii]] - 2 * dep[ii];
      s.insert({diam, i});
    }
  for (int i = m + 1; i < n; i++) {
    int x = s.begin()->second;
    int dx = s.begin()->first;
    s.erase(s.begin());
    int y = s.begin()->second;
    int dy = s.begin()->first;
    s.erase(s.begin());
    int c1 = get_center(x);
    int c2 = get_center(y);
    add.push_back({c1, c2});
    adj[c1].push_back(c2);
    adj[c2].push_back(c1);
    s.insert({max({dx, dy, (dx + 1) / 2 + (dy + 1) / 2}), y});
  }
  get_center(1);
  int diam = -1;
  for (int i = 1; i <= n; i++)
    if (dep[M[i]] + dep[M1[i]] - 2 * dep[i] > diam)
      diam = dep[M[i]] + dep[M1[i]] - 2 * dep[i];
  cout << diam << '\n';
  for (auto j : add) cout << j.first << " " << j.second << '\n';
  return 0;
}
