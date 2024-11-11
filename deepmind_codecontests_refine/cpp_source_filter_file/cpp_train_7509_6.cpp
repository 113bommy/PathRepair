#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> G[N];
vector<int> Com[N];
int n, m, d;
int cnt;
int components;
int componentdegree[N];
int DFN[N];
int low[N];
int que[N], top;
bool inque[N];
bool vis[N][55];
int dp[N][55];
int ans[N][55];
bool isopen[N][55];
void tarjan(int now) {
  DFN[now] = low[now] = ++cnt;
  que[++top] = now;
  inque[now] = true;
  for (int i = 0; i < G[now].size(); i++) {
    int j = G[now][i];
    if (DFN[j] == -1) {
      tarjan(j);
      low[now] = min(low[now], low[j]);
    } else if (inque[j] && low[now] > low[j])
      low[now] = low[j];
  }
  if (low[now] == DFN[now]) {
    components++;
    componentdegree[now] = components;
    while (que[top] != now) {
      int x = que[top];
      inque[x] = false;
      componentdegree[x] = components;
      top--;
    }
    inque[now] = false;
    top--;
  }
  return;
}
void solve() {
  components = 0;
  top = 0;
  cnt = 0;
  memset(inque, false, sizeof(inque));
  memset(DFN, -1, sizeof(DFN));
  for (int i = 1; i <= n; i++)
    if (DFN[i] == -1) {
      tarjan(i);
    }
}
void init(int x) {
  for (int i = 0; i < Com[x].size(); i++)
    memset(vis[Com[x][i]], false, sizeof(vis[0]));
}
void bfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = true;
  for (int i = 0; i < G[x].size(); i++) {
    int v = G[x][i];
    if (componentdegree[v] == componentdegree[x]) bfs(v, (y + 1) % d);
  }
}
int ddfs(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  init(componentdegree[x]);
  bfs(x, y);
  int cnt = 0;
  int cps = componentdegree[x];
  for (int i = 0; i < Com[cps].size(); i++) {
    int tmp = Com[cps][i];
    for (int j = 0; j < d; j++)
      if (vis[tmp][j] && isopen[tmp][j]) {
        cnt++;
        break;
      }
  }
  int mx = 0;
  for (int i = 0; i < Com[cps].size(); i++) {
    int tmp = Com[cps][i];
    for (int j = 0; j < d; j++) {
      if (vis[tmp][j]) {
        for (int k = 0; k < G[tmp].size(); k++) {
          int v = G[tmp][k];
          if (componentdegree[v] != cps) mx = max(mx, ddfs(v, j + 1));
        }
      }
    }
  }
  cnt += mx;
  for (int i = 0; i < Com[cps].size(); i++) {
    int tmp = Com[cps][i];
    for (int j = 0; j < d; j++) {
      if (vis[tmp][j]) dp[tmp][j] = cnt;
    }
  }
  return dp[x][y];
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
  }
  solve();
  for (int i = 1; i <= n; i++) {
  }
  for (int i = 1; i <= n; i++) {
    char st[55];
    scanf("%s", st);
    for (int j = 0; j < d; j++) isopen[i][j] = st[j] == '1';
  }
  for (int i = 1; i <= n; i++) {
    Com[componentdegree[i]].push_back(i);
  }
  ddfs(1, 0);
  printf("%d\n", dp[1][0]);
  return 0;
}
