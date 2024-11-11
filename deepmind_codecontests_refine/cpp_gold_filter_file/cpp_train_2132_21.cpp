#include <bits/stdc++.h>
using namespace std;
int a[202];
bool vis[20000 + 10];
bool v[202];
vector<int> q[202];
int linkx[202], linky[202];
vector<int> ans[202];
int cnt;
bool dfs(int x) {
  for (int i = 0; i < q[x].size(); i++) {
    int to = q[x][i];
    if (v[to] || to == linky[x]) continue;
    v[to] = 1;
    if (!linky[to] || dfs(linky[to])) {
      linky[to] = x, linkx[x] = to;
      return 1;
    }
  }
  return 0;
}
int main() {
  for (int i = 2; i <= 20000; i++) {
    if (!vis[i]) {
      for (int j = i + i; j <= 20000; j += i) vis[j] = 1;
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i] + a[j] <= 20000 && !vis[a[i] + a[j]]) {
        q[i].push_back(j);
      }
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    memset(v, 0, sizeof v);
    if (dfs(i)) ret++;
  }
  if (ret != n)
    printf("Impossible\n");
  else {
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n; i++) {
      if (v[i]) continue;
      cnt++;
      int x = i;
      while (1) {
        v[x] = 1;
        ans[cnt].push_back(x);
        x = linkx[x];
        if (v[x]) break;
      }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
      printf("%d ", ans[i].size());
      for (int j = 0; j < ans[i].size(); j++) {
        int to = ans[i][j];
        printf("%d ", to);
      }
      printf("\n");
    }
  }
  return 0;
}
