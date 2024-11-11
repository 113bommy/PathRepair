#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int s, t, ds, dt, cc;
int comp[200200], val[200200];
bool visited[200200];
vector<vector<int> > adj(200200);
vector<pair<int, int> > tree;
void dfs(int u, int c) {
  if (u == s || u == t) return;
  visited[u] = true;
  comp[u] = c;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    if (!visited[cur]) {
      dfs(cur, c);
    }
  }
}
void dfs1(int u, int p) {
  tree.push_back(make_pair(p, u));
  visited[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    if (!visited[cur]) {
      dfs1(cur, u);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> s >> t >> ds >> dt;
  for (int i = 1; i <= n; i++) {
    if (!visited[i] && i != s && i != t) {
      dfs(i, ++cc);
    }
  }
  for (int i = 0; i < adj[s].size(); i++) {
    val[comp[adj[s][i]]] = 1;
  }
  for (int i = 0; i < adj[t].size(); i++) {
    if (val[comp[adj[t][i]]] == 1 || val[comp[adj[t][i]]] == 3) {
      val[comp[adj[t][i]]] = 3;
    } else {
      val[comp[adj[t][i]]] = 2;
    }
  }
  val[comp[s]] = val[comp[t]] = 0;
  memset(visited, false, sizeof(visited));
  visited[s] = true;
  for (int i = 0; i < adj[s].size(); i++) {
    int cur = adj[s][i];
    if (!visited[cur] && val[comp[cur]] == 1 && ds) {
      ds--;
      dfs1(cur, s);
    }
  }
  visited[t] = true;
  for (int i = 0; i < adj[t].size(); i++) {
    int cur = adj[t][i];
    if (!visited[cur] && val[comp[cur]] == 2 && dt) {
      dt--;
      dfs1(cur, t);
    }
  }
  if (!ds || !dt) {
    cout << "NO\n";
    return 0;
  }
  bool flag = false;
  for (int i = 0; i < adj[s].size(); i++) {
    int cur = adj[s][i];
    if (!visited[cur] && val[comp[cur]] == 3 && ds) {
      ds--;
      dfs1(cur, s);
      flag = true;
    }
  }
  for (int i = 0; i < adj[t].size(); i++) {
    int cur = adj[t][i];
    if (visited[cur] && val[comp[cur]] == 3) {
      dt--;
      tree.push_back(make_pair(t, cur));
      break;
    }
  }
  for (int i = 0; i < adj[t].size(); i++) {
    int cur = adj[t][i];
    if (!visited[cur] && val[comp[cur]] == 3 && dt) {
      dt--;
      dfs1(cur, t);
      flag = true;
    }
  }
  if (!flag) {
    if (ds && dt) {
      tree.push_back(make_pair(s, t));
    } else {
      cout << "NO\n";
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < tree.size(); i++) {
    cout << tree[i].first << " " << tree[i].second << "\n";
  }
  return 0;
}
