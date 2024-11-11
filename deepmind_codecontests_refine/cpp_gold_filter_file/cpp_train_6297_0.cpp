#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int> > g[100005];
int vis[100005];
long long ans;
void dfs(int u) {
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].first, w = g[u][i].second;
    if (vis[v] == -1) {
      if (w) {
        vis[v] = vis[u];
      } else {
        vis[v] = vis[u] ^ 1;
      }
      dfs(v);
    }
    if (w) {
      if (vis[v] != vis[u]) {
        ans = -1;
      }
    } else {
      if (vis[v] == vis[u]) {
        ans = -1;
      }
    }
  }
}
long long pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int main() {
  memset(vis, -1, sizeof(vis));
  int n, m, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }
  for (int i = 1; i <= n && ans >= 0; i++) {
    if (vis[i] == -1) {
      vis[i] = 1;
      ans++;
      dfs(i);
    }
  }
  if (ans != -1)
    ans = pow(2LL, 1LL * ans - 1);
  else
    ans = 0;
  cout << ans << endl;
  return 0;
}
