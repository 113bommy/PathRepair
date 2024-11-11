#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5 + 7;
int n, m;
int par[maxx], edge[maxx], cnt[maxx], mol;
bool visit[maxx], mark[maxx], boreshi[maxx], leaf[maxx], Hambandi[maxx],
    hambandi[maxx];
vector<pair<int, int> > adj[maxx];
vector<int> nei[maxx];
vector<pair<int, int> > barg;
vector<int> ans[maxx];
void find_boreshi(int v) {
  mark[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i].first;
    int e = adj[v][i].second;
    if (!mark[u]) {
      par[u] = v;
      edge[u] = e;
      visit[e] = true;
      find_boreshi(u);
      cnt[v] += cnt[u];
    } else {
      if (u != par[v] && !visit[e]) {
        cnt[v]++;
        cnt[u]--;
        visit[e] = true;
      }
    }
  }
}
int comp[maxx];
void DFS_2hambandi(int v) {
  mark[v] = true;
  comp[v] = mol;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i].first;
    int e = adj[v][i].second;
    if (!mark[u] && !boreshi[e]) DFS_2hambandi(u);
  }
}
int timee;
int st[maxx];
void DFS(int v) {
  mark[v] = true;
  st[v] = timee++;
  for (int i = 0; i < nei[v].size(); i++)
    if (!mark[nei[v][i]]) DFS(nei[v][i]);
}
void DFS_ALL() {
  for (int i = 0; i < n; i++)
    if (!mark[i]) {
      DFS_2hambandi(i);
      mol++;
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  if (n == 2) {
    cout << "-1"
         << "\n";
    return 0;
  }
  find_boreshi(0);
  for (int i = 0; i < n; i++)
    if (cnt[i] == 0) boreshi[edge[i]] = true;
  memset(mark, 0, sizeof mark);
  DFS_ALL();
  if (mol == 1) {
    cout << "0"
         << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < adj[i].size(); j++)
      if (comp[i] != comp[adj[i][j].first])
        nei[comp[i]].push_back(comp[adj[i][j].first]);
  memset(mark, 0, sizeof mark);
  DFS(0);
  for (int i = 0; i < mol; i++)
    if (nei[i].size() == 1) barg.push_back({st[i], i});
  int SZ = (int)barg.size();
  cout << (SZ + 2 - 1) / 2 << "\n";
  sort(barg.begin(), barg.end());
  for (int i = 0; i < SZ; i++)
    for (int j = 0; j < n; j++)
      if (comp[j] == barg[i].second) {
        leaf[j] = true;
        ans[i].push_back(j);
      }
  for (int i = 0; i < adj[ans[SZ - 1][0]].size(); i++)
    Hambandi[adj[ans[SZ - 1][0]][i].first] = true;
  for (int i = 0; i < adj[ans[0][0]].size(); i++)
    hambandi[adj[ans[0][0]][i].first] = true;
  if (SZ == 2) {
    for (int i = 0; i < n; i++)
      if (ans[0][0] != i && leaf[i] && comp[i] != comp[ans[0][0]] &&
          !hambandi[i]) {
        cout << i + 1 << " " << ans[0][0] + 1;
        return 0;
      }
  }
  if (SZ % 2 == 0) {
    for (int i = 0; i < SZ / 2; i++)
      cout << ans[i][0] + 1 << " " << ans[i + (SZ / 2)][0] + 1 << "\n";
  } else {
    for (int i = 0; i < (SZ - 1) / 2; i++)
      cout << ans[i][0] + 1 << " " << ans[i + (SZ - 1) / 2][0] + 1 << "\n";
    for (int i = 0; i < n; i++)
      if (ans[SZ - 1][0] != i && !Hambandi[i] && !leaf[i] &&
          comp[i] != comp[ans[SZ - 1][0]]) {
        cout << i + 1 << " " << ans[SZ - 1][0] + 1 << "\n";
        break;
      }
  }
}
