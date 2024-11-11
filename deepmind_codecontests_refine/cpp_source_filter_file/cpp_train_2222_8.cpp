#include <bits/stdc++.h>
using namespace std;
const long long N = 2500002;
vector<long long> adj[100002];
long long vis[100002], insert[100002], low[100002], timer;
bool flag, art[100002];
long long ans;
vector<pair<long long, long long> > v;
void dfs(long long node, long long par) {
  vis[node] = 1;
  insert[node] = low[node] = timer;
  timer++;
  long long children = 0;
  for (auto it : adj[node]) {
    if (it == par) continue;
    if (vis[it]) {
      low[node] = min(insert[it], low[node]);
    } else {
      dfs(it, node);
      low[node] = min(low[it], low[node]);
      if (insert[node] <= low[it] && par != -1 && art[node] == false) {
        art[node] = true;
        ans++;
      }
      children++;
    }
  }
  if (par == -1 && children > 1 && art[node] == false) {
    art[node] = true;
    ans++;
  }
}
void clear() {
  for (long long i = 0; i < 100002; i++) {
    adj[i].clear();
    vis[i] = 0;
    art[i] = false;
    low[i] = 0;
    insert[i] = 0;
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string s[n];
  long long a[n][m];
  long long x = 1;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (s[i][j] == '#') {
        a[i][j] = x;
        x++;
      }
    }
  }
  if (x <= 2) {
    cout << -1;
    return;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (s[i][j] == '#') {
        if (i + 1 < n && s[i + 1][j] == '#')
          adj[a[i][j]].push_back(a[i + 1][j]);
        if (j + 1 < m && s[i][j + 1] == '#')
          adj[a[i][j]].push_back(a[i][j + 1]);
        if (i - 1 >= 0 && s[i - 1][j] == '#')
          adj[a[i][j]].push_back(a[i - 1][j]);
        if (j - 1 >= 0 && s[i][j - 1] == '#')
          adj[a[i][j]].push_back(a[i][j - 1]);
      }
    }
  }
  ans = 0, timer = 0;
  dfs(1, -1);
  cout << ((ans == 0) ? 2 : 1) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
