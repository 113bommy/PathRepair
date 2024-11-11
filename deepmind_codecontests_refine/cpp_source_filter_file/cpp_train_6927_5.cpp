#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
const int MAXN = 5555;
int n, m;
int dis[MAXN], vis[MAXN], dp[MAXN], chk[MAXN];
queue<int> Q;
vector<int> adj[MAXN], radj[MAXN];
int calc(int s) {
  for (int i = 1; i <= n; i++) {
    dis[i] = 0;
  }
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < ((int)(adj[u].size())); i++) {
      int v = adj[u][i];
      if (!dis[v]) {
        dis[v] = dis[u] + 1;
        Q.push(v);
      }
    }
  }
  return dis[s];
}
int q[MAXN], qn;
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < ((int)(adj[u].size())); i++) {
    int v = adj[u][i];
    if (!vis[v]) {
      dfs(v);
    }
  }
  q[qn++] = u;
}
int cnt;
void rdfs(int u) {
  vis[u] = cnt;
  for (int i = 0; i < ((int)(radj[u].size())); i++) {
    int v = radj[u][i];
    if (!vis[v]) {
      rdfs(v);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  memset(vis, 0, sizeof vis);
  for (int i = n - 1; i >= 0; i--) {
    int u = q[i];
    if (!vis[u]) {
      cnt++;
      rdfs(u);
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    chkmin(dp[vis[i]], calc(i));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < ((int)(adj[i].size())); j++) {
      if (vis[adj[i][j]] != vis[i]) {
        chk[vis[i]] = 1;
      }
    }
  }
  int ans = n;
  for (int i = 1; i <= cnt; i++) {
    if (!chk[i]) {
      ans += dp[i] * 998 + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
