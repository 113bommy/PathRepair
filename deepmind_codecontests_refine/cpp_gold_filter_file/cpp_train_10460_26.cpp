#include <bits/stdc++.h>
using namespace std;
int cont = 1;
int dp[200010];
int Map[200010];
int RMap[200010];
int level[200010];
int st[800010];
int kth[20][100010];
vector<vector<int> > adj;
void constructST(int l = 1, int r = cont - 1, int i = 0) {
  if (l == r) {
    st[i] = l;
    return;
  }
  int mid = (l + r) >> 1;
  constructST(l, mid, i * 2 + 1);
  constructST(mid + 1, r, i * 2 + 2);
  int L = st[i * 2 + 1];
  int R = st[i * 2 + 2];
  st[i] = (level[L] <= level[R]) ? L : R;
}
int rmq(int s, int e, int l = 1, int r = cont - 1, int i = 0) {
  if (s > r or l > e) return -1;
  if (s <= l and r <= e) return st[i];
  int mid = (l + r) >> 1;
  int L = rmq(s, e, l, mid, i * 2 + 1);
  int R = rmq(s, e, mid + 1, r, i * 2 + 2);
  if (L == -1) return R;
  if (R == -1) return L;
  int ans = (level[L] <= level[R]) ? L : R;
  return ans;
}
int lca(int u, int v);
pair<int, int> dist(int u, int v) {
  int x = lca(u, v);
  int d = level[Map[u]] + level[Map[v]] - 2 * level[Map[x]];
  return pair<int, int>(d, x);
}
int lca(int u, int v) {
  int L = min(Map[u], Map[v]);
  int R = max(Map[u], Map[v]);
  int ind = rmq(L, R);
  return RMap[ind];
}
void dfs(int u, int lev) {
  level[cont] = lev;
  Map[u] = cont;
  RMap[cont] = u;
  dp[u] = 1;
  cont++;
  for (auto v : adj[u]) {
    if (!Map[v]) {
      kth[0][v] = u;
      dfs(v, lev + 1);
      dp[u] += dp[v];
      RMap[cont] = u;
      level[cont] = lev;
      cont++;
    }
  }
}
int query(int u, int k) {
  for (int i = 0; i < 20; i++) {
    if (k & (1 << i)) u = kth[i][u];
  }
  return u;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  adj.assign(n + 5, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  constructST();
  for (int i = 1; i <= log2(n); i++) {
    for (int u = 1; u <= n; u++) {
      kth[i][u] = kth[i - 1][kth[i - 1][u]];
    }
  }
  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    pair<int, int> aux = dist(u, v);
    int d = aux.first;
    int l = aux.second;
    if (d & 1)
      cout << 0 << "\n";
    else if (d == 0)
      cout << n << "\n";
    else {
      if (level[Map[u]] == level[Map[v]]) {
        int len = d >> 1;
        cout << dp[1] - dp[query(u, len - 1)] - dp[query(v, len - 1)] << "\n";
      } else {
        if (level[Map[u]] > level[Map[v]]) {
          int len = d >> 1;
          cout << dp[query(u, len)] - dp[query(u, len - 1)] << "\n";
        } else {
          int len = d >> 1;
          cout << dp[query(v, len)] - dp[query(v, len - 1)] << "\n";
        }
      }
    }
  }
}
