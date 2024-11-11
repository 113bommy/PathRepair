#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int t;
int dep[maxn];
int f[maxn], vis[maxn];
vector<int> e[maxn];
void dfs(int u, int fa) {
  for (int v : e[u]) {
    if (!dep[v]) {
      dep[v] = dep[u] + 1;
      f[v] = u;
      dfs(v, u);
    } else {
      if (dep[v] - dep[u] + 1 >= t) {
        printf("2\n");
        int len = dep[v] - dep[u] + 1;
        printf("%d\n", len);
        int cnt = 0;
        while (v) {
          if (cnt == len) break;
          cnt++;
          printf("%d ", v);
          v = f[v];
        }
        exit(0);
      }
    }
  }
  for (int v : e[u]) {
    if (!vis[u]) vis[v] = 1;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  t = ceil(sqrt(n));
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dep[1] = 1;
  dfs(1, 0);
  printf("1\n");
  int cnt0 = 0;
  int cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      cnt1++;
    else
      cnt0++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt == t) break;
    if (!vis[i]) {
      printf("%d ", i);
      cnt++;
    }
  }
}
