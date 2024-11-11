#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 3;
int par[2][maxn];
int sz[2][maxn];
vector<int> e[2][maxn];
int fst[2][maxn], lst[2][maxn];
int rnk[2][maxn];
int minrnk[2][maxn];
int cur;
int m[2];
void dfs(int tr, int v) {
  sz[tr][v] = 1;
  for (int u : e[tr][v]) {
    dfs(tr, u);
    sz[tr][v] += sz[tr][u];
  }
  sort(e[tr][v].begin(), e[tr][v].end(),
       [&](int x, int y) { return rnk[tr][x] < rnk[tr][y]; });
  if (!e[tr][v].empty()) {
    rnk[tr][v] = rnk[tr][e[tr][v].back()];
    minrnk[tr][v] = minrnk[tr][e[tr][v][0]];
  } else {
    minrnk[tr][v] = rnk[tr][v];
  }
}
int loc[2][maxn];
int dp[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int k = 0; k <= 1; k++) {
    cin >> m[k];
    par[k][1] = 0;
    for (int i = 2; i <= m[k]; i++) {
      int p;
      cin >> p;
      e[k][p].push_back(i);
      par[k][i] = p;
    }
    for (int i = 1; i <= n; i++) {
      int v;
      cin >> v;
      rnk[k][v] = i;
      loc[k][i] = v;
    }
    dfs(k, 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= 1; k++) {
      for (int v = loc[k][i]; v != 0 && rnk[k][v] <= i; v = par[k][v]) {
        int pre = minrnk[k][v] - 1;
        int s = (v == 1) ? m[k] - 1 : sz[k][v];
        dp[i] = max(dp[i], dp[pre] + s);
      }
    }
  }
  cerr << dp[n] << '\n';
  return 0;
}
