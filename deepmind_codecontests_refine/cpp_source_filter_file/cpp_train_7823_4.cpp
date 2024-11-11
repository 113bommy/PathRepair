#include <bits/stdc++.h>
using namespace std;
int n;
bool ok[500005];
long long size[500005], ans[500005];
vector<int> G[500005];
void Dfs(int u, int fa) {
  size[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    Dfs(v, u);
    size[u] += size[v];
  }
}
void dfs(int u, int fa) {
  if (!fa)
    ans[u] = n * (n - 1) / 2;
  else {
    ans[u] = ans[fa];
    ans[u] =
        ans[u] - (n - size[fa]) * size[fa] - (size[fa] * (size[fa] - 1)) / 2;
    ans[u] = ans[u] + (n - (size[fa] - size[u])) * (size[fa] - size[u]) +
             ((size[fa] - size[u]) * (size[fa] - size[u] - 1)) / 2;
    ans[u] = ans[u] + (n - size[u]) * size[u] + (size[u] * (size[u] - 1)) / 2;
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs(v, u);
  }
}
long long Solve() {
  long long Max1 = 0;
  int First = 0;
  Dfs(1, 0);
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    if (ans[i] > Max1) {
      Max1 = ans[i];
      First = i;
    }
  }
  memset(ans, 0, sizeof ans);
  Dfs(First, 0);
  dfs(First, 0);
  long long Max2 = 0;
  int Second = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] > Max2) {
      Max2 = ans[i];
      Second = i;
    }
  }
  return Max2;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v), G[v].push_back(u);
  }
  printf("%lld\n", Solve());
  return 0;
}
