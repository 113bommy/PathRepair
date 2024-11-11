#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 35;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
using namespace std;
vector<int> adj[MAX];
int vis[MAX];
map<pair<int, int>, bool> mp;
int maap[MAX];
int c = 0;
int cc;
void dfs(int i) {
  maap[c] = i;
  c++;
  vis[i] = 1;
  bool ok = 1;
  for (int j = 0; j < adj[i].size(); j++) {
    int u = adj[i][j];
    if (!vis[u]) {
      ok = 0;
      dfs(u);
    }
  }
  if (ok && !cc) cc = c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    mp[{x, y}] = mp[{y, x}] = 1;
  }
  dfs(1);
  int x = maap[cc - 1];
  int in = -1;
  for (int i = 0; i < cc; i++) {
    int y = maap[i];
    if (mp[{x, y}]) {
      in = i;
      break;
    }
  }
  cout << cc - in << "\n";
  for (int i = in; i < cc; i++) {
    cout << maap[i] << " ";
  }
  return 0;
}
