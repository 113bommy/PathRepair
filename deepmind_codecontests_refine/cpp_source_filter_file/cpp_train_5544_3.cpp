#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int tot = 0;
int d[100005];
int vis[100005];
int fa[100005];
int sum[100005];
int lim;
void dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < v[x].size(); i++) {
    int u = v[x][i];
    if (u == fa[x]) continue;
    if (vis[u] && d[u] - d[x] <= lim && d[u] - d[x] > 0) {
      vector<int> v1;
      while (u != x) {
        v1.push_back(u);
        u = fa[u];
      }
      v1.push_back(u);
      printf("2\n%d\n", v1.size());
      for (int j = 0; j < v1.size(); j++) {
        printf("%d ", v1[j]);
      }
      printf("\n");
      exit(0);
    } else if (!vis[u]) {
      d[u] = d[x] + 1;
      fa[u] = x;
      dfs(u);
    } else if (vis[u] && d[u] - d[x] > lim) {
      vector<int> v1;
      while (u != x) {
        v1.push_back(u);
        u = fa[u];
      }
      v1.push_back(u);
      int cnt = 0;
      printf("1\n");
      for (int j = 0; j < v1.size(); j += 2) {
        printf("%d ", v1[j]);
        cnt++;
        if (cnt == (lim + 1) / 2) {
          printf("\n");
          exit(0);
        }
      }
    }
  }
}
void work() {
  int n, m;
  scanf("%d%d%d", &n, &m, &lim);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1);
  printf("1\n");
  for (int i = 1; i <= n; i++) {
    sum[d[i] % 2]++;
  }
  int ans = 0;
  for (int i = 1; i <= 1; i++) {
    if (sum[ans] < sum[i]) {
      ans = i;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] % 2 == ans) {
      cnt++;
      printf("%d ", i);
      if (cnt == (lim + 1) / 2) break;
    }
  }
  printf("\n");
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    work();
  }
}
