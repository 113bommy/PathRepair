#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1005;
int l[maxn], r[maxn], sz[maxn], val[maxn][maxn], dp[maxn];
vector<int> g[maxn];
void dfs(int u) {
  if (u != 1) sz[u] = 1;
  for (auto v : g[u]) {
    dfs(v);
    l[u] = min(l[u], l[v]);
    r[u] = max(r[u], r[v]);
    sz[u] += sz[v];
  }
  val[l[u]][r[u]] = max(val[l[u]][r[u]], sz[u]);
}
int main() {
  int n, a;
  scanf("%d", &n);
  for (int st = 0; st < 2; st++) {
    scanf("%d", &a);
    for (int i = 0; i <= a; i++) {
      g[i].clear();
      l[i] = a + 1;
      r[i] = sz[i] = 0;
    }
    for (int i = 2, v; i <= a; i++) {
      scanf("%d", &v);
      g[v].push_back(i);
    }
    for (int i = 1, x; i <= n; i++) {
      scanf("%d", &x);
      l[x] = r[x] = i;
    }
    dfs(1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) dp[i] = max(dp[i], dp[j - 1] + val[j][i]);
  }
  cout << dp[n] << endl;
  return 0;
}
