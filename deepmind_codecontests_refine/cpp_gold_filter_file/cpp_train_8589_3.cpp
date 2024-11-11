#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
vector<int> G[MAXN];
int d[MAXN], n, x, y, u, v, root;
bool f[MAXN];
int dfs(int x, int fa) {
  int cur = 0, tot = 0;
  for (auto i : G[x])
    if (i != fa) {
      cur += dfs(i, x);
      if (!f[i]) tot++;
    }
  if (tot == 1) cur++;
  if (tot > 1) cur += 2, f[x] = 1;
  return cur;
}
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    d[u]++;
    d[v]++;
  }
  root = 1;
  for (int i = 1; i <= n; ++i)
    if (d[i] > d[root]) root = i;
  long long ans;
  if (x >= y) {
    if (d[root] == n - 1)
      ans = 1LL * x + 1LL * (n - 2) * y;
    else
      ans = 1LL * (n - 1) * y;
  } else
    ans = 1LL * dfs(root, root) * (x - y) + 1LL * (n - 1) * y;
  cout << ans << endl;
  return 0;
}
