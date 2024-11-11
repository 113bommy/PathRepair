#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
long long vis[maxn], num[maxn], res, k;
vector<int> G[maxn];
void dfs1(int u, int fa) {
  if (vis[u]) num[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs1(v, u);
      num[u] += num[v];
    }
  }
}
void dfs2(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      res += min(num[v], 2 * k - num[v]);
      dfs2(v, u);
    }
  }
}
int main(void) {
  int n, a;
  cin >> n >> k;
  for (int i = 0; i < 2 * k; i++) {
    scanf("%d", &a);
    vis[a] = 1;
  }
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  cout << res;
}
