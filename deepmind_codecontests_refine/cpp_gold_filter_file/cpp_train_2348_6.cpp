#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, P = 1e9 + 7;
int n, m, sz[N], L[N], R[N], vis[N], deg[N];
vector<pair<int, int>> g[N];
void add(int &a, int64_t b) { a = (a + b) % P; }
array<int, 2> solve1(int x) {
  int dp[2][2][2];
  memset(dp, 0, sizeof dp);
  if (sz[x] == 2) {
    if (g[x][0].second) {
      dp[0][0][1] = dp[0][1][1] = 1;
      dp[0][1][0] = 2;
    } else {
      dp[0][0][0] = dp[0][1][0] = 1;
      dp[0][1][1] = 2;
    }
  } else {
    if (g[x][0].second)
      dp[0][0][1] = dp[0][1][0] = 1;
    else
      dp[0][0][0] = dp[0][1][1] = 1;
  }
  vis[x] = 1;
  x = g[x][0].first;
  int cur = 0;
  array<int, 2> c{};
  while (1) {
    cur ^= 1;
    memset(dp[cur], 0, sizeof dp[0]);
    vis[x] = 1;
    if (g[x].size() == 1 && vis[g[x][0].first]) {
      if (sz[x] == 2) {
        for (int u = 0; u < 2; ++u)
          for (int v = 0; v < 2; ++v) {
            int w = dp[cur ^ 1][u][v];
            add(c[u ^ v], w), add(c[u ^ 1], w);
          }
      } else {
        for (int u = 0; u < 2; ++u)
          for (int v = 0; v < 2; ++v) add(c[u ^ v], dp[cur ^ 1][u][v]);
      }
      break;
    } else {
      int tp = vis[g[x][0].first];
      for (int u = 0; u < 2; ++u)
        for (int v = 0; v < 2; ++v) {
          int w = dp[cur ^ 1][u][v];
          if (g[x][tp].second) {
            add(dp[cur][u ^ v][1], w);
            add(dp[cur][u ^ 1][0], w);
          } else {
            add(dp[cur][u ^ v][0], w);
            add(dp[cur][u ^ 1][1], w);
          }
        }
      x = g[x][tp].first;
    }
  }
  return c;
}
array<int, 2> solve2(int x) {
  if (g[x][0].first == g[x][1].first) {
    vis[x] = vis[g[x][0].first] = 1;
    if (g[x][0].second == 0 && g[x][1].second == 0) return {4, 0};
    return {2, 2};
  }
  int dp[2][2][2][2];
  memset(dp, 0, sizeof dp);
  if (g[x][0].second == 0 && g[x][1].second == 0) {
    dp[0][0][0][0] = dp[0][1][1][0] = dp[0][1][0][1] = dp[0][1][1][1] = 1;
  } else if (g[x][0].second && g[x][1].second == 0) {
    dp[0][0][1][0] = dp[0][1][0][0] = dp[0][1][1][1] = dp[0][1][0][1] = 1;
  } else if (g[x][0].second == 0 && g[x][1].second) {
    dp[0][0][0][1] = dp[0][1][1][1] = dp[0][1][0][0] = dp[0][1][1][0] = 1;
  } else {
    dp[0][0][1][1] = dp[0][1][0][1] = dp[0][1][1][0] = dp[0][1][0][0] = 1;
  }
  vis[x] = 1;
  x = g[x][0].first;
  int cur = 0;
  array<int, 2> c{};
  while (1) {
    cur ^= 1;
    memset(dp[cur], 0, sizeof dp[0]);
    vis[x] = 1;
    int tp;
    if (!vis[g[x][0].first])
      tp = 0;
    else if (!vis[g[x][1].first])
      tp = 1;
    else {
      for (int u = 0; u < 2; ++u)
        for (int v = 0; v < 2; ++v)
          for (int z = 0; z < 2; ++z) add(c[u ^ (v | z)], dp[cur ^ 1][u][v][z]);
      break;
    }
    for (int z = 0; z < 2; ++z) {
      for (int u = 0; u < 2; ++u)
        for (int v = 0; v < 2; ++v) {
          int w = dp[cur ^ 1][u][v][z];
          if (g[x][tp].second) {
            add(dp[cur][u ^ v][1][z], w);
            add(dp[cur][u ^ 1][0][z], w);
          } else {
            add(dp[cur][u ^ v][0][z], w);
            add(dp[cur][u ^ 1][1][z], w);
          }
        }
    }
    x = g[x][tp].first;
  }
  return c;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int t, x;
    scanf("%d", &t);
    sz[i] = t;
    while (t--) {
      scanf("%d", &x);
      if (L[abs(x)] == 0) {
        if (x < 0)
          L[abs(x)] = -i;
        else
          L[x] = i;
      } else {
        if (x < 0)
          R[abs(x)] = -i;
        else
          R[x] = i;
      }
    }
  }
  int cnt = 0;
  for (int x = 1; x <= m; ++x) {
    if (!L[x])
      ++cnt;
    else if (R[x]) {
      if (L[x] == R[x]) {
        deg[abs(L[x])] = -1;
        continue;
      } else if (L[x] == -R[x]) {
        deg[abs(L[x])] = -2;
        continue;
      }
      if (L[x] < 0 && R[x] < 0) L[x] = -L[x], R[x] = -R[x];
      if (L[x] > 0 && R[x] > 0) {
        g[L[x]].push_back({R[x], 0});
        g[R[x]].push_back({L[x], 0});
        ++deg[L[x]];
        ++deg[R[x]];
      } else {
        L[x] = abs(L[x]), R[x] = abs(R[x]);
        g[L[x]].push_back({R[x], 1});
        g[R[x]].push_back({L[x], 1});
        ++deg[L[x]];
        ++deg[R[x]];
      }
    }
  }
  array<int64_t, 2> c{};
  c[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0 && sz[i] == 2) {
      c = {(c[0] + c[1] * 3) % P, (c[0] * 3 + c[1]) % P};
      vis[i] = 1;
    } else if (deg[i] == 0 || deg[i] == -1) {
      c = {(c[0] + c[1]) % P, (c[0] + c[1]) % P};
      vis[i] = 1;
    } else if (deg[i] == -2) {
      c = {2 * c[1] % P, 2 * c[0] % P};
      vis[i] = 1;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 1 && !vis[i]) {
      auto t = solve1(i);
      c = {(c[0] * t[0] + c[1] * t[1]) % P, (c[0] * t[1] + c[1] * t[0]) % P};
    }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      auto t = solve2(i);
      c = {(c[0] * t[0] + c[1] * t[1]) % P, (c[0] * t[1] + c[1] * t[0]) % P};
    }
  for (int i = 1; i <= cnt; ++i) c[1] = c[1] * 2 % P;
  printf("%lld\n", c[1]);
}
