#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
const long long MOD = 1e9 + 7;
int vp(int tv) {
  int qan = 0;
  if (tv == 0) return 20;
  while (tv % 2 == 0) {
    tv /= 2;
    qan++;
  }
  return qan;
}
int a[N], b[N];
int d[N];
int n, qan;
bool bl, col[N];
vector<int> g[N];
void dfsc(int v) {
  qan -= g[v].size();
  if (g[v].size() % 2) {
    bl = false;
    return;
  }
  col[v] = true;
  for (auto to : g[v]) {
    if (!col[to]) {
      dfsc(to);
      if (!bl) return;
    }
  }
}
bool check(int bruh) {
  int tv = (1 << bruh);
  qan = 2 * n;
  int root;
  for (int i = 0; i < (n); ++i) {
    int v = a[i] % tv, u = b[i] % tv;
    root = v;
    g[v].push_back(u);
    g[u].push_back(v);
    col[a[i] % tv] = col[b[i] % tv] = false;
  }
  bl = true;
  dfsc(root);
  if (qan) bl = false;
  for (int i = 0; i < (n); ++i) {
    g[a[i] % tv].clear();
    g[b[i] % tv].clear();
  }
  return bl;
}
int ind[N];
bool vis[N];
vector<int> pat;
int tv;
vector<pair<int, int> > adj[N];
void dfs(int v, int verj = -1) {
  for (; ind[v] < adj[v].size(); ind[v]++) {
    if (vis[adj[v][ind[v]].second]) continue;
    vis[adj[v][ind[v]].second] = true;
    dfs(adj[v][ind[v]].first, adj[v][ind[v]].second);
  }
  if (verj != -1) {
    if (a[verj] % tv == v) {
      pat.push_back(verj * 2);
      pat.push_back(verj * 2 + 1);
    } else {
      pat.push_back(verj * 2 + 1);
      pat.push_back(verj * 2);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n;
  if (n == 1) {
    int v, u;
    cin >> v >> u;
    cout << vp(v ^ u) << "\n1 2" << endl;
    return 0;
  }
  for (int i = 0; i < (n); ++i) {
    cin >> a[i] >> b[i];
  }
  int l = 0, r = 21;
  while (l < r) {
    int md = (l + r) / 2;
    if (check(md)) {
      l = md + 1;
    } else {
      r = md;
    }
  }
  cout << l - 1 << endl;
  tv = (1 << (l - 1));
  int root;
  for (int i = (0); i <= (n - 1); ++i) {
    int v = a[i] % tv, u = b[i] % tv;
    adj[v].push_back(make_pair(u, i));
    adj[u].push_back(make_pair(v, i));
    root = v;
  }
  dfs(root);
  for (int i = 0; i < (pat.size()); ++i) cout << pat[i] + 1 << " ";
  return 0;
}
