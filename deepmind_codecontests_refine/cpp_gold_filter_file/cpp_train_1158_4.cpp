#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> deep(n + 1);
  vector<vector<int>> E(n + 1);
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  bool flag = false;
  vector<bool> vis(n + 1);
  fill(vis.begin(), vis.end(), false);
  vector<int> a(n + 1);
  function<void(int)> path_dfs;
  path_dfs = [&](int now) {
    vis[now] = true;
    a[deep[now]] = now;
    if (deep[now] == n / k) {
      flag = true;
      printf("PATH\n%d\n", deep[now] + 1);
      for (int i = 0; i <= deep[now]; i++) printf("%d ", a[i]);
      printf("\n");
      return;
    }
    for (auto it : E[now]) {
      if (vis[it]) continue;
      deep[it] = deep[now] + 1;
      path_dfs(it);
      if (flag) return;
    }
  };
  deep[1] = 0;
  path_dfs(1);
  if (flag) return 0;
  fill(vis.begin(), vis.end(), false);
  function<void(int, int)> dfs;
  dfs = [&](int now, int fa) {
    vis[now] = true;
    a[deep[now]] = now;
    int cnt = 0;
    for (auto it : E[now]) {
      if (vis[it]) continue;
      cnt++;
      dfs(it, now);
      if (k == 0) return;
    }
    if (cnt) return;
    k--;
    sort(E[now].begin(), E[now].end(),
         [&](const int& a, const int& b) { return deep[a] > deep[b]; });
    int u = 0, v = 0;
    for (auto it : E[now]) {
      if (it == fa) continue;
      if (!u)
        u = it;
      else {
        v = it;
        break;
      }
    }
    if ((deep[now] - deep[u] + 1) % 3) {
      printf("%d\n", deep[now] - deep[u] + 1);
      printf("%d ", now);
      for (int i = deep[u]; i < deep[now]; i++) printf("%d ", a[i]);
    } else if ((deep[now] - deep[v] + 1) % 3) {
      printf("%d\n", deep[now] - deep[v] + 1);
      printf("%d ", now);
      for (int i = deep[v]; i < deep[now]; i++) printf("%d ", a[i]);
    } else {
      printf("%d\n", deep[u] - deep[v] + 2);
      printf("%d ", now);
      for (int i = deep[v]; i <= deep[u]; i++) printf("%d ", a[i]);
    }
    printf("\n");
  };
  printf("CYCLES\n");
  dfs(1, 0);
  return 0;
}
