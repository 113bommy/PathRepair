#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int vis[100005];
void dfs(int u, map<int, int> &mp) {
  vis[u] = 1;
  cout << mp[u] << " ";
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v, mp);
  }
}
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  map<int, int> mp1;
  set<int> s;
  int j = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (s.find(x) == s.end()) {
      mp[j] = x;
      mp1[x] = j;
      j++;
      s.insert(x);
    }
    if (s.find(y) == s.end()) {
      mp[j] = y;
      mp1[y] = j;
      j++;
      s.insert(y);
    }
    g[mp1[x]].push_back(mp1[y]);
    g[mp1[y]].push_back(mp1[x]);
  }
  int srs = -1;
  for (int i = 0; i <= n; i++)
    if (g[i].size() == 1) srs = i;
  dfs(srs, mp);
  return 0;
}
