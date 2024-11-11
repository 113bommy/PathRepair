#include <bits/stdc++.h>
using namespace std;
struct ed {
  long long int x, y, ans, id;
} e[200001];
long long int n, m, val[200001], f[200001], par[200001];
vector<long long int> adj[200001];
bool vis[200001];
unordered_map<long long int, long long int> mp;
long long int dfs(long long int node) {
  long long int i, j, k;
  vis[node] = true;
  for (i = 0; i < adj[node].size(); i++) {
    long long int x = adj[node][i];
    if (!vis[x]) {
      dfs(x);
    }
  }
}
void dfs1(long long int node) {
  long long int i, j, k;
  vis[node] = true;
  for (i = 0; i < adj[node].size(); i++) {
    long long int x = adj[node][i];
    if (!vis[x]) {
      par[x] = node;
      dfs1(x);
    }
  }
  if (par[node] == node) return;
  val[par[node]] += val[node];
  mp[node] = val[node];
  val[node] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long int i, j, k, u, v;
  for (i = 1; i <= n; i++) {
    cin >> val[i];
  }
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y;
    e[i].id = i;
    adj[e[i].x].push_back(e[i].y);
    adj[e[i].y].push_back(e[i].x);
  }
  long long int rt;
  par[1] = 1;
  dfs1(1);
  long long int flag = 1;
  for (i = 1; i <= n; i++) {
    if (val[i] != 0) {
      flag = 0;
      break;
    }
  }
  if (flag == 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (i = 1; i <= m; i++) {
    if (par[e[i].y] == e[i].x)
      cout << mp[e[i].y] << endl;
    else if (par[e[i].x] == e[i].y)
      cout << -1 * mp[e[i].y] << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
