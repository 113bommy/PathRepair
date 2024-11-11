#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 1e6 + 50, LG = 17, MOD = 1e9 + 7;
const int SQ = 225;
const long double EPS = 1e-7;
int f[105][105];
int n, m, u, v;
int xs[1005], a[1005], fu[1005];
int xb[1005], d[1005];
int s, b, k, h;
vector<int> adj[1005];
bitset<1005> vis;
int match[1005];
bool canMatch(int u) {
  if (vis[u]) return false;
  vis[u] = true;
  for (auto v : adj[u])
    if (match[v] == -1 || canMatch(match[v])) {
      match[v] = u;
      return true;
    }
  return false;
}
int khun() {
  memset(match, -1, sizeof match);
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    vis.reset();
    ans += canMatch(i);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < n + 1; j++) {
      if (i == j)
        f[i][j] = 0;
      else
        f[i][j] = 1e9 + 1;
    }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    f[u][v] = f[v][u] = min(f[u][v], 1);
  }
  for (int k = 1; k < n + 1; k++)
    for (int i = 1; i < n + 1; i++)
      for (int j = 1; j < n + 1; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  cin >> s >> b >> k >> h;
  for (int i = 0; i < s; i++) {
    cin >> xs[i] >> a[i] >> fu[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> xb[i] >> d[i];
  }
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < b; j++) {
      if (f[xs[i]][xs[j]] <= fu[i] && a[i] >= d[j]) {
        adj[i].push_back(j);
      }
    }
  }
  int matching = khun();
  ll ans = 1ll * k * matching;
  for (int i = s - matching + 1; i < s + 1; i++) {
    ans = min(ans, (s - i) * 1ll * k + i * 1ll * h);
  }
  cout << ans << '\n';
  return 0;
}
