#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 10;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m;
vector<int> v[N], v1[N];
int vis[N];
bool flag, ans[N], vis1[N];
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < v[u].size(); i++) {
    int j = v[u][i];
    if (vis[u] == 1)
      flag = 1;
    else if (!vis[j])
      dfs(j);
  }
  vis[u] = 2;
}
void dfs1(int u) {
  vis1[u] = 1;
  for (int i = 0; i < v1[u].size(); i++) {
    int j = v1[u][i];
    if (!vis1[j]) dfs1(j);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v1[b].push_back(a);
  }
  flag = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);
  if (flag)
    puts("-1");
  else {
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && !vis1[i]) {
        ans[i] = 1;
        cnt++;
      } else
        ans[i] = 0;
      if (!vis[i]) dfs(i);
      if (!vis1[i]) dfs1(i);
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
      if (ans[i])
        printf("A");
      else
        printf("E");
  }
}
