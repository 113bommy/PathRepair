#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, lg = 20;
int LCA[MAXN][lg], n, m, h[MAXN], s = 1, st[MAXN], en[MAXN], t1, t2, t3;
long long dp[MAXN], csum[MAXN], LCAS[MAXN][lg];
vector<pair<long long, pair<int, int> > > pv[MAXN];
vector<pair<int, int> > hv[MAXN];
vector<int> ch[MAXN];
void dfs(int v, int p) {
  h[v] = h[p] + 1;
  hv[h[v]].push_back({s, v});
  st[v] = s;
  s++;
  for (int i = 0; i < ch[v].size(); i++) dfs(ch[v][i], v);
  en[v] = s - 1;
}
pair<int, long long> getLCA(int v1, int v2) {
  long long sum = 0;
  if (h[v2] < h[v1]) swap(v1, v2);
  int tf = h[v2] - h[v1], i = 0;
  sum += csum[v2];
  while (tf != 0) {
    if (tf % 2 == 1) sum += LCAS[v2][i], v2 = LCA[v2][i];
    tf /= 2;
    i++;
  }
  if (v1 == v2) return {v1, sum};
  sum += csum[v1];
  for (int o = lg - 1; o >= 0; o--)
    if (LCA[v1][o] != LCA[v2][o])
      sum += LCAS[v2][o], sum += LCAS[v1][o], v1 = LCA[v1][o], v2 = LCA[v2][o];
  sum += csum[LCA[v2][0]] - dp[v1] - dp[v2];
  return {LCA[v1][0], sum};
}
void dfsup(int v) {
  for (int i = 0; i < ch[v].size(); i++) {
    dfsup(ch[v][i]);
    csum[v] += dp[ch[v][i]];
  }
  dp[v] = csum[v];
  for (int i = 0; i < ch[v].size(); i++)
    LCAS[ch[v][i]][0] = csum[v] - dp[ch[v][i]];
  for (int j = 1; j < lg; j++) {
    int trh = h[v] + (1 << j);
    if (trh > MAXN || hv[trh].empty()) break;
    vector<pair<int, int> >::iterator bg =
        upper_bound(hv[trh].begin(), hv[trh].end(), make_pair(st[v], 0));
    vector<pair<int, int> >::iterator eo =
        upper_bound(hv[trh].begin(), hv[trh].end(), make_pair(en[v], 0));
    for (; bg != eo; bg++)
      LCAS[(*bg).second][j] =
          LCAS[(*bg).second][j - 1] + LCAS[LCA[(*bg).second][j - 1]][j - 1];
  }
  for (int j = 0; j < pv[v].size(); j++)
    dp[v] =
        max(dp[v],
            pv[v][j].first +
                getLCA(pv[v][j].second.first, pv[v][j].second.second).second);
}
int main() {
  cin >> n >> m;
  for (int i = 2; i <= n; i++) cin >> LCA[i][0], ch[LCA[i][0]].push_back(i);
  dfs(1, 1);
  for (int j = 1; j < lg; j++)
    for (int i = 1; i <= n; i++) LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
  for (int i = 0; i < m; i++) {
    cin >> t1 >> t2 >> t3;
    pv[getLCA(t1, t2).first].push_back({t3, {t1, t2}});
  }
  dfsup(1);
  cout << dp[1];
}
