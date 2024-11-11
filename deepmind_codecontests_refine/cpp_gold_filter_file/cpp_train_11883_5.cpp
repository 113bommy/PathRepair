#include <bits/stdc++.h>
using namespace std;
int n, m, c[200010], cnt = 0, js[200010];
long long dp[200010][2], selected[200010];
bool is_leaf[200010], is_ans[200010], vis[200010][2];
struct node {
  int x, type;
  node(int x, int type) : x(x), type(type) {}
};
vector<node> road[200010];
void dfs(int k, int fa) {
  int len = road[k].size();
  is_leaf[k] = 1;
  dp[k][1] = 200000000000000;
  long long sum = 0;
  for (int i = 0; i < len; i++) {
    int son = road[k][i].x;
    if (son != fa) {
      dfs(son, k);
      sum += dp[son][0];
      is_leaf[k] = 0;
    } else
      road[k][i].type = -1;
  }
  if (is_leaf[k]) {
    dp[k][0] = c[k];
    dp[k][1] = 0;
    return;
  }
  for (int i = 0; i < len; i++) {
    int son = road[k][i].x;
    if (son != fa) dp[k][1] = min(dp[k][1], sum - dp[son][0] + dp[son][1]);
  }
  for (int i = 0; i < len; i++) {
    int son = road[k][i].x;
    if (son != fa) {
      if (dp[k][1] == sum - dp[son][0] + dp[son][1]) {
        road[k][i].type = 1;
        js[k]++;
      }
    }
  }
  dp[k][0] = min(sum, dp[k][1] + c[k]);
  selected[k] = sum - (dp[k][1] + c[k]);
}
void bfs() {
  queue<node> q;
  q.push(node(1, 1));
  vis[1][1] = 1;
  for (int i = 1; i <= n; i++) is_ans[i] = 0;
  while (!q.empty()) {
    node tmp = q.front();
    q.pop();
    int k = tmp.x, type = tmp.type;
    int len = road[k].size();
    if (type == 1 && selected[k] >= 0) {
      is_ans[k] = 1;
      cnt++;
    }
    for (int i = 0; i < len; i++) {
      if (road[k][i].type == -1) continue;
      int t1 = 0, t0 = 0;
      if (road[k][i].type == 0 || (type == 1 && selected[k] <= 0) || js[k] > 1)
        t1 = 1;
      if (road[k][i].type == 1 &&
          ((type == 1 && selected[k] >= 0) || type == 0))
        t0 = 1;
      if (t1 && !vis[road[k][i].x][1]) {
        q.push(node(road[k][i].x, 1));
        vis[road[k][i].x][1] = 1;
      }
      if (t0 && !vis[road[k][i].x][0]) {
        q.push(node(road[k][i].x, 0));
        vis[road[k][i].x][0] = 1;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    road[u].push_back(node(v, 0));
    road[v].push_back(node(u, 0));
  }
  dfs(1, 0);
  bfs();
  printf("%lld %d\n", dp[1][0], cnt);
  for (int i = 1; i <= n; i++)
    if (is_ans[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
