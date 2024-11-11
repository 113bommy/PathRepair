#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f;
const double eps = 1e-9;
int n, m, k;
int tot;
int ans[maxn * 2];
int temp[maxn * 2];
int vis[maxn];
vector<int> vec[maxn];
void dfs(int u) {
  vis[u] = 1;
  ans[tot++] = u;
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (vis[v] == 1) continue;
    dfs(v);
    ans[tot++] = u;
  }
}
int main() {
  int u, v;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    memset((vis), (0), sizeof(vis));
    for (int i = 1; i <= n; i++) {
      vec[i].clear();
    }
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      vec[u].push_back(v);
      vec[v].push_back(u);
    }
    tot = 0;
    dfs(1);
    int num = 0;
    int len = 2 * n / k;
    if (2 * n % k == 0) len++;
    int i = 0, cnt = 0;
    while (i < tot) {
      if (cnt < len) {
        temp[cnt++] = ans[i++];
      } else {
        num++;
        printf("%d", len);
        for (int j = 0; j < cnt; j++) {
          printf(" %d", temp[j]);
        }
        puts("");
        cnt = 0;
      }
    }
    if (cnt > 0) {
      num++;
      printf("%d", cnt);
      for (int j = 0; j < cnt; j++) {
        printf(" %d", temp[j]);
      }
      puts("");
    }
    while (num < k) {
      puts("1 1");
      num++;
    }
  }
  return 0;
}
