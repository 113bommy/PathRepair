#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
const int MAXN = 1005;
long long int fac[MAXN];
const int mod = 1e9 + 7;
long long int expo(long long int a, long long int b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0) {
    long long int y = expo(a, b / 2);
    return (y * y) % mod;
  } else
    return (a * expo(a, b - 1)) % mod;
}
long long int modinv(long long int n) { return expo(n, mod - 2); }
long long int C(int n, int r) {
  long long int ans =
      (fac[n] * ((modinv(fac[r]) * modinv(fac[n - r])) % mod)) % mod;
  return ans;
}
vector<int> adj[MAXN];
int dis[MAXN][MAXN];
int vis[MAXN];
void dfs(int s, int i) {
  vis[s] = 1;
  for (auto u : adj[s]) {
    if (!vis[u]) {
      dis[i][u] = 1 + dis[i][s];
      dfs(u, i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(dis, 0, sizeof(dis));
    for (int i = 1; i <= n; i++) {
      dis[i][i] = 0;
      memset(vis, 0, sizeof(vis));
      dfs(i, i);
    }
    cout << "? " << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    int u, d;
    cin >> u >> d;
    int l = d / 2, r = 0;
    for (int i = 1; i <= n; i++) r = max(r, dis[u][i]);
    vector<int> vec;
    int node = u;
    while (l <= r) {
      int m = (l + r) / 2;
      for (int i = 1; i <= n; i++)
        if (dis[u][i] == m) vec.push_back(i);
      cout << "? ";
      cout << vec.size() << endl;
      for (int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
      cout << endl;
      int v, d1;
      cin >> v >> d1;
      if (d1 == d) {
        l = m + 1;
        node = v;
      } else
        r = m - 1;
      vec.clear();
    }
    for (int i = 1; i <= n; i++)
      if (dis[node][i] == d) vec.push_back(i);
    cout << "? " << vec.size() << endl;
    for (auto u : vec) cout << u << " ";
    cout << endl;
    int node1, d3;
    cin >> node1 >> d3;
    cout << "! " << node << " " << node1 << endl;
    string s;
    cin >> s;
    if (s[0] == 'I') return 0;
    for (int i = 0; i <= 1000; i++) adj[i].clear();
  }
  return 0;
}
