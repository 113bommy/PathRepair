#include <bits/stdc++.h>
using namespace std;
void addto(int &a, int b) { a += b, a %= 1000000007; }
struct Edge {
  int to, w;
} ed[100 * 100 + 5];
struct edge {
  int u, v, k;
} e[100 * 100 + 5];
vector<int> V[100 * 100 + 5], G[100 + 5][2];
bool fff = 0;
int n, m, mp[100 + 5][100 + 5], dp[100 + 5][100 + 5][100 + 5],
    res[100 + 5][100 + 5], g[100 + 5][100 + 5][100 + 5], ans[100 + 5],
    last[100 + 5], ecnt = 0;
void add(int u, int v, int len, bool flag) {
  int p = ++ecnt;
  ed[p].to = v, ed[p].w = len;
  G[u][flag].push_back(p);
  if (len < 6 && fff) printf("%d %d %d %d\n", u, v, len, flag);
}
int solve(int x, int now, bool flag, int &len) {
  queue<int> q;
  int u;
  if (!flag) {
    u = e[x].u, len++;
    for (int i = now - 1; i >= 0; i--) q.push(V[x][i]);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (!mp[v][u]) return -1;
      int y = mp[v][u];
      len++;
      if (len > (n << 1 | 1)) return -1;
      for (int i = e[y].k - 1; i >= 0; i--) q.push(V[y][i]);
      u = v;
    }
    return u;
  } else {
    u = e[x].v, len++;
    for (int i = now + 1; i < e[x].k; i++) q.push(V[x][i]);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (!mp[u][v]) return -1;
      int y = mp[u][v];
      len++;
      if (len > (n << 1 | 1)) return -1;
      for (int i = 0; i < e[y].k; i++) q.push(V[y][i]);
      u = v;
    }
    return u;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].k);
    mp[e[i].u][e[i].v] = i;
    for (int j = 1; j <= e[i].k; j++) {
      int x;
      scanf("%d", &x);
      V[i].push_back(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!e[i].k) continue;
    int s, t, len = 0;
    bool flag = 0;
    for (int j = 1; j < e[i].k; j++)
      if (V[i][j - 1] == e[i].u && V[i][j] == e[i].v) {
        s = solve(i, j - 1, 0, len), t = solve(i, j, 1, len), flag = 1;
        break;
      }
    if (V[i][0] == e[i].v) {
      int l1 = 0, tmp = solve(i, 0, 1, l1);
      if (tmp != -1) {
        add(e[i].u, tmp, l1, 0);
      }
    }
    if (V[i][e[i].k - 1] == e[i].u) {
      int l2 = 0, tmp = solve(i, e[i].k - 1, 0, l2);
      if (tmp != -1) {
        add(e[i].v, tmp, l2, 1);
      }
    }
    if (flag && s != -1 && t != -1) {
      dp[s][t][len]++;
    }
  }
  for (int len = 2; len <= (n << 1 | 1); len++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dp[i][j][len])
          for (int k = 0; k < G[j][0].size(); k++) {
            int x = G[j][0][k];
            if (len + ed[x].w <= (n << 1 | 1))
              addto(dp[i][ed[x].to][len + ed[x].w], dp[i][j][len]);
          }
  for (int len = 2; len <= (n << 1 | 1); len++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dp[i][j][len])
          for (int k = 0; k < G[i][1].size(); k++) {
            int x = G[i][1][k];
            if (len + ed[x].w <= (n << 1 | 1))
              addto(dp[ed[x].to][j][len + ed[x].w], dp[i][j][len]);
          }
  for (int len = 2; len <= (n << 1 | 1); len++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dp[i][j][len])
          for (int k = 1; k <= n; k++)
            if (mp[k][i] && !e[mp[k][i]].k) addto(g[k][j][len], dp[i][j][len]);
  for (int len = 2; len <= (n << 1 | 1); len++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dp[i][j][len]) addto(res[j][len], dp[i][j][len]);
  for (int len = 2; len <= (n << 1 | 1); len++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k + len <= (n << 1 | 1); k++)
          addto(res[j][len + k], res[i][len] * 1ll * g[i][j][k] % 1000000007);
  for (int len = 2; len <= (n << 1 | 1); len++)
    for (int i = 1; i <= n; i++) addto(ans[len], res[i][len]);
  for (int i = 1; i <= (n << 1); i++) printf("%d\n", ans[i + 1]);
  return 0;
}
