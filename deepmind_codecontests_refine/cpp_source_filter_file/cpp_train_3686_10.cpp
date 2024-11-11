#include <bits/stdc++.h>
using namespace std;
const int N = 100100, LOG_N = 20, SQRT_M = 317;
int n, m, t, u, v, col[N], dis[N], ans[N];
int F[N], ST[LOG_N][N << 1], LOG[N];
vector<int> E, L, reds, newReds, edges[N];
void bfs() {
  queue<int> q;
  memset(ans, -1, sizeof(ans));
  for (int u : reds) {
    q.push(u);
    ans[u] = 0;
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : edges[u]) {
      if (ans[v] == -1) {
        ans[v] = ans[u] + 1;
        q.push(v);
      }
    }
  }
}
void dfs(int u = 1, int par = 0, int lvl = 0) {
  dis[u] = lvl;
  F[u] = E.size();
  E.push_back(u);
  L.push_back(lvl);
  for (int v : edges[u]) {
    if (v != par) {
      dfs(v, u, lvl + 1);
      E.push_back(u);
      L.push_back(lvl);
    }
  }
}
void buildRMQ() {
  int i, j, x, y;
  for (i = 0, LOG[0] = -1; i < L.size(); ++i) {
    ST[0][i] = i;
    LOG[i + 1] = LOG[i] + !(i & (i + 1));
  }
  for (j = 1; (1 << j) <= L.size(); ++j) {
    for (i = 0; (i + (1 << j)) <= L.size(); ++i) {
      x = ST[j - 1][i];
      y = ST[j - 1][i + (1 << (j - 1))];
      ST[j][i] = (L[x] < L[y]) ? x : y;
    }
  }
}
int query(int l, int r) {
  if (l > r) swap(l, r);
  int g = LOG[r - l + 1];
  int x = ST[g][l];
  int y = ST[g][r - (1 << g) + 1];
  return (L[x] < L[y]) ? x : y;
}
int getLCA(int u, int v) { return E[query(F[u], F[v])]; }
int getDistance(int u, int v) {
  return dis[u] + dis[v] - 2 * dis[getLCA(u, v)];
}
int solve(int v) {
  int ret = ans[v];
  for (int u : newReds) {
    ret = min(ret, getDistance(u, v));
  }
  return ret;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs();
  buildRMQ();
  col[1] = 1;
  newReds.push_back(1);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &t, &v);
    if (i % SQRT_M == 0 && newReds.size() > 0) {
      reds.insert(reds.end(), newReds.begin(), newReds.end());
      newReds.clear();
      bfs();
    }
    if (t == 1) {
      if (col[v] == 0) {
        col[v] = 1;
        newReds.push_back(v);
      }
    } else {
      printf("%d\n", solve(v));
    }
  }
  return 0;
}
