#include <bits/stdc++.h>
using namespace std;
const int maxn = 25e4 + 100;
const int maxm = 5e5 + 100;
int head[maxn], Next[2 * maxm], to[2 * maxm];
int n, m, sz, k, goal, cir;
vector<int> path;
void init() {
  sz = 0;
  memset(head, -1, sizeof(head));
}
void add_edge(int a, int b) {
  ++sz;
  to[sz] = b;
  Next[sz] = head[a];
  head[a] = sz;
}
int vis[maxn];
bool find_path(int u, int fa) {
  vis[u] = 1;
  path.push_back(u);
  if (path.size() > goal) return true;
  for (int i = head[u]; i != -1; i = Next[i]) {
    int v = to[i];
    if (vis[v]) continue;
    if (find_path(v, u)) return true;
  }
  path.pop_back();
  return false;
}
int depth[maxn];
void dfs(int u, int fa) {
  vis[u] = 1;
  depth[u] = path.size();
  path.push_back(u);
  int flag = 0;
  for (int i = head[u]; i != -1; i = Next[i]) {
    int v = to[i];
    if (!vis[v]) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    for (int i = head[u]; i != -1; i = Next[i]) {
      int v = to[i];
      if (!vis[v]) dfs(v, u);
    }
  } else {
    if (cir) {
      cir--;
      int fax = -1, fay = -1;
      for (int i = head[u]; i != -1; i = Next[i]) {
        int v = to[i];
        if (v == fa) continue;
        if (fax == -1)
          fax = v;
        else if (fay == -1) {
          fay = v;
          break;
        }
      }
      if (depth[fax] < depth[fay]) swap(fax, fay);
      int ori = -1;
      if ((depth[u] - depth[fax] + 1) % 3) ori = fax;
      if ((depth[u] - depth[fay] + 1) % 3) ori = fay;
      if (ori == -1) {
        printf("%d\n", depth[fax] - depth[fay] + 3);
        printf("%d ", u);
        for (int i = depth[fax]; i >= depth[fay]; i--) {
          printf("%d ", path[i]);
        }
        printf("\n");
      } else {
        printf("%d\n", depth[u] - depth[fax] + 2);
        for (int i = depth[u]; i >= depth[ori]; i--) {
          printf("%d ", path[i]);
        }
        printf("\n");
      }
    }
  }
  path.pop_back();
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  goal = n / k;
  if (n % k) goal++;
  init();
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  if (find_path(1, 0)) {
    printf("PATH\n");
    printf("%d\n", path.size());
    for (int i = 0; i < path.size(); i++) {
      printf("%d ", path[i]);
    }
  } else {
    cir = k;
    memset(vis, 0, sizeof(vis));
    path.clear();
    printf("CYCLES\n");
    dfs(1, 0);
  }
  return 0;
}
