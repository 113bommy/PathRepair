#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int n, dp[maxn], son[maxn];
long long ans, cb, cw;
vector<int> tree[maxn];
void dfs(int u, int fa, int d) {
  if (d & 1)
    cb++;
  else
    cw++;
  son[u] = 1;
  for (int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i];
    if (v == fa) continue;
    dfs(v, u, d + 1);
    son[u] += son[v];
  }
  dp[u] = son[u] * (n - son[u]);
  ans += dp[u];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1, -1, 1);
  cout << (ans + cb * cw) / 2 << endl;
}
