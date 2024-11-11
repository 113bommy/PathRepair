#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int g[N][N], arr[N], vis[N], n, sz;
vector<int> ans[N];
bool prime(int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}
int find_path() {
  vector<int> pa(n + 5, -1);
  queue<int> q;
  q.push(0);
  pa[0] = 0;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int i = 0; i <= n + 1; i++) {
      if (g[k][i] > 0 && pa[i] == -1) {
        pa[i] = k;
        q.push(i);
      }
    }
  }
  int mn = 5000, i;
  i = n + 1;
  if (pa[n + 1] == -1) return 0;
  while (i != 0) {
    mn = min(mn, g[pa[i]][i]);
    i = pa[i];
  }
  i = n + 1;
  while (i != 0) {
    g[pa[i]][i] -= mn;
    g[i][pa[i]] += mn;
    i = pa[i];
  }
  return mn;
}
void dfs(int a, int p) {
  vis[a] = 1;
  ans[sz].push_back(a);
  int c = 0;
  if (arr[a] % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      if (i != p && !vis[i] && g[a][i] == 1) {
        dfs(i, a);
        c = 1;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (i != p && !vis[i] && g[i][a] == 1) {
        dfs(i, a);
        c = 1;
      }
    }
  }
}
int main() {
  int o, e;
  o = e = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for (int i = 1; i <= n; i++) {
    if (arr[i] & 1)
      g[0][i] = 2, o++;
    else
      g[i][n + 1] = 2, e++;
  }
  if (o != e) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] & 1) {
      for (int j = 1; j <= n; j++) {
        if (arr[j] % 2 == 0 && prime(arr[i] + arr[j])) g[i][j] = 1;
      }
    }
  }
  int flow = 0;
  while (1) {
    int f = find_path();
    if (f == 0) break;
    flow += f;
  }
  if (flow != n) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
      sz++;
    }
  }
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    printf("%d ", ans[i].size());
    for (int j : ans[i]) printf("%d ", j);
    printf("\n");
  }
  return 0;
}
