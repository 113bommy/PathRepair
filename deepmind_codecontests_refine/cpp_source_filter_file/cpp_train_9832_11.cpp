#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100 * 2 + 152;
int n, m, x, y, z, q, mark[maxn], k = 1, par1[maxn], sum[maxn], h[maxn];
pair<long long, long long> par[17][maxn];
vector<pair<long long, long long> > v[maxn];
pair<long long, pair<long long, long long> > edg[maxn];
void dfs(int x) {
  mark[x] = k;
  for (int i = 0; i < v[x].size(); i++)
    if (!mark[v[x][i].first]) {
      sum[k] += v[x][i].second;
      par[0][v[x][i].first] = make_pair(x, v[x][i].second);
      h[v[x][i].first] = h[x] + 1;
      dfs(v[x][i].first);
    }
}
int find_par(int x) {
  if (x == par1[x]) return x;
  return par1[x] = find_par(par1[x]);
}
long long LCA(int x, int y) {
  if (h[x] > h[y]) swap(x, y);
  long long fa = h[y] - h[x], jack = 0, MAX = 0;
  for (int i = 0; i < 17; i++)
    if ((1 << i) & fa) {
      MAX = max(MAX, par[i][y].second);
      y = par[i][y].first;
    }
  for (int i = 16; i >= 0; i--)
    if (par[i][x].first != par[i][y].first) {
      MAX = max(MAX, max(par[i][x].second, par[i][y].second));
      x = par[i][x].first;
      y = par[i][y].first;
    }
  if (x != y) MAX = max(MAX, max(par[0][x].second, par[0][y].second));
  return MAX;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> edg[i].second.first >> edg[i].second.second >> edg[i].first;
  for (int i = 1; i <= n; i++) par1[i] = i;
  sort(edg, edg + m);
  for (int i = 0; i < m; i++) {
    int x = find_par(edg[i].second.first), y = find_par(edg[i].second.second);
    if (x == y) continue;
    v[edg[i].second.first].push_back(
        make_pair(edg[i].second.second, edg[i].first));
    v[edg[i].second.second].push_back(
        make_pair(edg[i].second.first, edg[i].first));
    par1[x] = y;
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      dfs(i);
      k++;
    }
  for (int i = 1; i < 17; i++)
    for (int j = 1; j <= n; j++)
      par[i][j] = make_pair(
          par[i - 1][par[i - 1][j].first].first,
          max(par[i - 1][j].second, par[i - 1][par[i - 1][j].first].second));
  cin >> q;
  while (q--) {
    cin >> x >> y;
    if (k > 3 || (k == 3 && mark[x] == mark[y])) {
      cout << -1 << endl;
      continue;
    }
    if (k == 3) {
      cout << sum[1] + sum[2] << endl;
      continue;
    }
    long long jack = LCA(x, y);
    cout << sum[1] - jack << endl;
  }
  return 0;
}
