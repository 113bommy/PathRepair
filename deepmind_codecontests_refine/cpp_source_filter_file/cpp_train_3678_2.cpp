#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
long long k, ans = 1;
vector<int> edge[N];
int sz[N], cnt;
void dfs(int x, int f) {
  sz[x] = 1;
  for (auto &to : edge[x]) {
    if (to == f) continue;
    if (sz[to]) continue;
    dfs(to, x);
    sz[x] += sz[to];
  }
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u].emplace_back(v), edge[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!sz[i]) dfs(i, 0), (ans *= sz[i]) %= k, cnt++;
  if (cnt == 1)
    ans = 1;
  else if (cnt != 2)
    for (int i = 1; i <= cnt - 2; i++) (ans *= n) %= k;
  printf("%lld\n", ans);
  return 0;
}
