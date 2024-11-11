#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 3e5;
long long int parent[MAX + 1];
long long int sz[MAX + 1];
pair<long long int, long long int> colcmp[MAX + 1];
long long int col[MAX + 1] = {0};
vector<pair<long long int, bool>> adj[MAX + 1];
bool vis[MAX + 1] = {false};
const long long int inf = 1e13;
long long int find_set(long long int v) {
  if (v == parent[v]) {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}
void make_set(long long int v) {
  parent[v] = v;
  sz[v] = 1;
}
void union_sets(long long int a, long long int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
  }
}
void DFS(long long int v, long long int c) {
  col[v] = c;
  vis[v] = true;
  for (auto u : adj[v]) {
    if (vis[u.first]) continue;
    if (u.second)
      DFS(u.first, c);
    else
      DFS(u.first, 3 - c);
  }
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<vector<long long int>> neigh(n + 1);
  string s;
  cin >> s;
  s = "." + s;
  for (long long int j = 1; j <= k; j++) {
    long long int c;
    cin >> c;
    for (long long int i = 0; i < c; i++) {
      long long int r;
      cin >> r;
      neigh[r].push_back(j);
    }
  }
  for (long long int j = 1; j <= n; j++) {
    if ((long long int)neigh[j].size() == 2) {
      adj[neigh[j][0]].push_back({neigh[j][1], ((s[j] - '0') ? true : false)});
      adj[neigh[j][1]].push_back({neigh[j][0], ((s[j] - '0') ? true : false)});
    }
  }
  for (long long int j = 1; j <= k; j++) {
    if (vis[j]) continue;
    DFS(j, 1);
  }
  for (long long int j = 1; j <= k; j++) {
    make_set(j);
    if (col[j] == 1) {
      colcmp[j] = {1, 0};
    } else
      colcmp[j] = {0, 1};
  }
  long long int res = 0;
  for (long long int j = 1; j <= n; j++) {
    if ((s[j] == '1') && (neigh[j].empty())) {
      cout << res << '\n';
      continue;
    }
    if ((long long int)neigh[j].size() == 1) {
      if (s[j] == '1') {
        long long int i = find_set(neigh[j][0]);
        res -= min(colcmp[i].first, colcmp[i].second);
        assert(res >= 0);
        if (col[neigh[j][0]] == 1) {
          colcmp[i].first = inf;
        } else
          colcmp[i].second = inf;
        res += min(colcmp[i].first, colcmp[i].second);
      } else {
        long long int i = find_set(neigh[j][0]);
        res -= min(colcmp[i].first, colcmp[i].second);
        assert(res >= 0);
        if (col[neigh[j][0]] == 1) {
          colcmp[i].second = inf;
        } else
          colcmp[i].first = inf;
        res += min(colcmp[i].first, colcmp[i].second);
      }
    } else {
      long long int i1 = find_set(neigh[j][0]), i2 = find_set(neigh[j][1]);
      if (find_set(i1) == find_set(i2)) {
        cout << res << '\n';
        continue;
      }
      res -= min(colcmp[i1].first, colcmp[i1].second);
      res -= min(colcmp[i2].first, colcmp[i2].second);
      assert(res >= 0);
      union_sets(i1, i2);
      long long int i = find_set(i1);
      colcmp[i] = {colcmp[i1].first + colcmp[i2].first,
                   colcmp[i1].second + colcmp[i2].second};
      res += min(colcmp[i].first, colcmp[i].second);
    }
    cout << res << '\n';
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
