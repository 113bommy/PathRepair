#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m, d;
vector<int> ve[maxn + 10];
string s[maxn + 10];
int color[maxn + 10], dfn[maxn + 10], low[maxn + 10], stack_in[maxn + 10],
    vis[maxn + 10], cnt[maxn + 10];
bool flag[maxn + 10][55];
vector<int> zu[maxn + 10];
queue<pair<int, int> > q;
int top, sum, deep;
int dp[maxn][55];
void init() {
  memset(dfn, -1, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(dp, -1, sizeof(dp));
  top = 0, sum = 0, deep = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= maxn; i++) ve[i].clear(), zu[i].clear();
}
void tarjan(int u) {
  dfn[u] = ++deep;
  low[u] = deep;
  vis[u] = 1;
  stack_in[++top] = u;
  int sz = ve[u].size();
  for (int i = 0; i < sz; i++) {
    int v = ve[u][i];
    if (dfn[v] == -1) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else {
      if (vis[v]) {
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (dfn[u] == low[u]) {
    color[u] = ++sum;
    vis[u] = 0;
    while (stack_in[top] != u) {
      color[stack_in[top]] = sum;
      vis[stack_in[top--]] = 0;
    }
    top--;
  }
}
int bfs(int u, int day) {
  for (int i = 0; i < zu[color[u]].size(); i++) {
    memset(flag[zu[color[u]][i]], false, sizeof(flag[zu[color[u]][i]]));
  }
  q.push(make_pair(u, day));
  flag[u][day] = true;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    int uu = node.first;
    int step = node.second;
    for (int i = 0; i < ve[uu].size(); i++) {
      int vv = ve[uu][i];
      int cur_step = (step + 1) % d;
      if (color[vv] == color[u] && (!flag[vv][cur_step])) {
        flag[vv][cur_step] = true;
        q.push(make_pair(vv, cur_step));
      }
    }
  }
  int res = 0;
  for (auto v : zu[color[u]]) {
    for (int i = 0; i < d; i++) {
      if (flag[v][i] && s[v][i] == '1') {
        res++;
        break;
      }
    }
  }
  return res;
}
int dfs(int u, int day) {
  if (dp[u][day] != -1) return dp[u][day];
  int res = bfs(u, day);
  int ret = 0;
  for (int i = 0; i < zu[color[u]].size(); i++) {
    int v = zu[color[u]][i];
    for (int j = 0; j < d; j++) {
      if (flag[v][j]) {
        for (auto v1 : ve[v]) {
          if (color[v1] != color[u]) {
            ret = max(ret, dfs(v1, (j + 1) % d));
          }
        }
      }
    }
  }
  for (int i = 0; i < zu[color[u]].size(); i++) {
    int v = zu[color[u]][i];
    for (int j = 0; j < d; j++) {
      if (flag[v][j]) {
        dp[v][j] = (res + ret);
      }
    }
  }
  return dp[u][day];
}
int main() {
  while (cin >> n >> m >> d) {
    init();
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      ve[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) {
      if (dfn[i] == -1) {
        tarjan(i);
      }
    }
    for (int i = 1; i <= n; ++i) {
      zu[color[i]].push_back(i);
    }
    int ans = dfs(1, 0);
    cout << dp[1][0] << endl;
  }
  return 0;
}
