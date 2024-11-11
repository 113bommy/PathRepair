#include <bits/stdc++.h>
using namespace std;
const int size = 25e4;
vector<int> g[size];
bool vis[size];
vector<int> path;
int pre[size];
int cir;
bool find_path(int v, int sz) {
  vis[v] = 1;
  path.push_back(v);
  if (path.size() >= sz) return true;
  for (auto u : g[v]) {
    if (!vis[u])
      if (find_path(u, sz)) return true;
  }
  path.pop_back();
  return false;
}
void dfs(int v, int f) {
  vis[v] = 1;
  pre[v] = path.size();
  path.push_back(v);
  int flag = 0;
  for (auto u : g[v]) {
    if (!vis[u]) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    for (auto u : g[v]) {
      if (!vis[u]) {
        dfs(u, v);
      }
    }
  } else if (cir > 0) {
    int fax = -1, fay = -1;
    for (auto u : g[v]) {
      if (u == f) continue;
      if (fax == -1)
        fax = u;
      else if (fay == -1) {
        fay = u;
        break;
      }
    }
    if (pre[fax] < pre[fay]) swap(fax, fay);
    int ori = -1;
    if ((pre[v] - pre[fax]) % 3 != 2) ori = fax;
    if ((pre[v] - pre[fay]) % 3 != 2) ori = fay;
    if (ori != -1) {
      printf("%d\n", pre[v] - pre[ori] + 1);
      for (int i = pre[v]; i >= pre[ori]; i--) {
        printf("%d%c", path[i], i == pre[ori] ? '\n' : ' ');
      }
    } else {
      printf("%d\n", pre[fax] - pre[fay] + 2);
      int point = pre[fax];
      printf("%d ", v);
      for (; point >= pre[fay]; point--) {
        printf("%d%c", path[point], point == pre[fay] ? '\n' : ' ');
      }
    }
    cir--;
  }
  path.pop_back();
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int sz = n / k;
  if (n % k) sz += 1;
  if (find_path(1, sz)) {
    printf("PATH\n");
    printf("%d\n", path.size());
    for (int i = 0; i < path.size(); i++) {
      printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
    }
    return 0;
  }
  path.clear();
  memset(vis, 0, sizeof(vis));
  printf("CYCLES\n");
  cir = k;
  dfs(1, 0);
  return 0;
}
