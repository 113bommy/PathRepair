#include <bits/stdc++.h>
using namespace std;
int dist[609][609];
vector<int> to[209];
int from[609];
bool vis[209];
bool taken[209];
bool try_kuhn(int v) {
  if (vis[v]) return false;
  vis[v] = true;
  for (int u : to[v]) {
    if (from[u] == -1 || try_kuhn(from[u])) {
      from[u] = v;
      return true;
    }
  }
  return false;
}
int main() {
  int n, e, m, K;
  scanf("%d %d %d %d", &n, &e, &m, &K);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dist[j][i] = dist[i][j] = 100000000;
    }
  }
  vector<int> V;
  for (int i = 0; i < m; i++) {
    int s;
    scanf("%d", &s);
    V.push_back(s);
  }
  while (e--) {
    int u, v, x;
    scanf("%d %d %d", &u, &v, &x);
    dist[u][v] = min(dist[u][v], x);
    dist[v][u] = dist[u][v];
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  int L = 0, R = 1731311;
  int ans = R;
  while (L <= R) {
    int M = (L + R) / 2;
    for (int i = 1; i <= n; i++) {
      from[i] = -1;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      vis[i] = taken[i] = false;
      to[i].clear();
      int u = V[i - 1];
      for (int v = 1; v <= n; v++) {
        if (dist[u][v] <= M) {
          to[i].push_back(v);
          if (!taken[i] && from[v] == -1) {
            taken[i] = true;
            from[v] = i;
            cnt++;
          }
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      if (taken[i]) continue;
      memset(vis, 0, sizeof vis);
      if (try_kuhn(i)) cnt++;
    }
    if (cnt >= K) {
      ans = M;
      R = M - 1;
    } else {
      L = M + 1;
    }
  }
  cout << ans << endl;
}
