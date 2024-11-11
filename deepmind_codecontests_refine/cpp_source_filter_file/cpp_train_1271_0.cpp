#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int T, n, m, a[3003], siz[3003];
pair<int, long long> dp[3003][3003];
vector<int> G[3003];
pair<int, long long> operator+(const pair<int, long long> &a,
                               const pair<int, long long> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
void dfs(int u, int fa) {
  dp[u][0] = make_pair(0, a[u]);
  for (int i = 1; i <= n; ++i) dp[u][i] = make_pair(0, -inf);
  siz[u] = 1;
  for (auto v : G[u]) {
    if (v == fa) continue;
    dfs(v, u);
    pair<int, long long> g[3003];
    for (int i = 1; i <= siz[u] + siz[v]; ++i) {
      g[i] = make_pair(0, -inf);
    }
    for (int i = 0; i <= siz[u]; ++i) {
      for (int j = 0; j <= siz[v]; ++j) {
        g[i + j] = max(g[i + j], dp[u][i] + dp[v][j]);
        g[i + j + 1] = max(
            g[i + j + 1],
            make_pair(dp[u][i].first + dp[v][j].first + (dp[v][j].second > 0),
                      dp[u][i].second));
      }
    }
    siz[u] += siz[v];
    for (int i = 0; i <= siz[u]; ++i) {
      dp[u][i] = g[i];
    }
  }
}
void Solve() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    G[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = read() - a[i];
  }
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  printf("%d\n", dp[1][m - 1].first + (dp[1][m - 1].second > 0));
}
int main() {
  T = read();
  while (T--) {
    Solve();
  }
  return 0;
}
