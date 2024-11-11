#include <bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int ans[100010 * 4];
bool vis[100010], c[100010];
int cnt;
void v(int x) {
  ans[cnt++] = x;
  c[x] ^= 1;
}
void dfs(int x) {
  vis[x] = 1;
  v(x);
  for (int i = 0; i < G[x].size(); i++) {
    if (vis[G[x][i]]) continue;
    dfs(G[x][i]);
    v(x);
    if (c[G[x][i]]) {
      v(G[x][i]);
      v(x);
    }
  }
}
bool judge(int n) {
  for (int i = 1; i <= n; i++)
    if (c[i]) return false;
  return true;
}
int main() {
  int n, m, u, v;
  cnt = 0;
  memset(vis, 0, sizeof(vis));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int st = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &u);
    c[i] = u;
    if (st == -1 && u) {
      st = i;
    }
  }
  dfs(st);
  if (c[st]) {
    c[st] = 0;
    cnt--;
  }
  if (judge(n)) {
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  } else
    printf("-1\n");
  return 0;
}
