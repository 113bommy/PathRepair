#include <bits/stdc++.h>
using namespace std;
const int N = 250000 + 5;
int n, m, k, f[N], dep[N], maxd, maxp;
vector<int> G[N], lev;
void addedge(int x, int y) {
  G[x].push_back(y);
  G[y].push_back(x);
}
void dfs(int u, int fa) {
  int flag = 0;
  for (auto v : G[u]) {
    if (v == fa || dep[v]) continue;
    flag = 1;
    f[v] = u;
    dep[v] = dep[u] + 1;
    if (dep[v] > maxd) {
      maxd = dep[v];
      maxp = v;
    }
    dfs(v, u);
  }
  if (!flag) lev.push_back(u);
}
int main() {
  memset(f, -1, sizeof f);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    addedge(x, y);
  }
  dep[1] = 1, dfs(1, -1);
  if (maxd > n / k) {
    printf("PATH\n%d\n", maxd);
    while (f[maxp] != -1) {
      printf("%d ", maxp);
      maxp = f[maxp];
    }
    printf("%d\n", maxp);
  } else {
    puts("CYCLES");
    for (int i = 0; i < k; i++) {
      int u = lev[i], f1 = 0, f2 = 0;
      for (auto v : G[u]) {
        if (v != f[u] && !f1) {
          f1 = v;
          continue;
        }
        if (v != f[u] && f1 && !f2) {
          f2 = v;
          break;
        }
      }
      if (dep[f1] > dep[f2]) swap(f1, f2);
      if ((dep[u] - dep[f1] + 1) % 3) {
        printf("%d\n", dep[u] - dep[f1] + 1);
        for (int j = u; j != f[f1]; j = f[j]) printf("%d ", j);
      } else if ((dep[u] - dep[f2] + 1) % 3) {
        printf("%d\n", dep[u] - dep[f2] + 1);
        for (int j = u; j != f[f2]; j = f[j]) printf("%d ", j);
      } else {
        printf("%d\n%d ", dep[f2] - dep[f1] + 2, u);
        for (int j = f2; j != f[f1]; j = f[j]) printf("%d ", j);
      }
      puts("");
    }
  }
  return 0;
}
