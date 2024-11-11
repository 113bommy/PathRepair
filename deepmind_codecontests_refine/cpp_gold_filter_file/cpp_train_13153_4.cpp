#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int MAXM = 5005;
const int MAXD = 205;
const int MAXN = 2 * N + 2 * MAXM;
int id;
vector<int> lft[N], rht[N];
int deg[MAXN];
int degposta[2 * N];
struct EC {
  vector<pair<int, int> > has[2][MAXN];
  int deg[2][MAXN], color[MAXM], c[2];
  void prep(int d) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < MAXN; j++) has[i][j].resize(d + 1, {0, 0});
  }
  void dfs(int x, int p) {
    auto i = has[p][x][c[!p]];
    if (has[!p][i.first][c[p]].second)
      dfs(i.first, !p);
    else
      has[!p][i.first][c[!p]] = {0, 0};
    has[p][x][c[p]] = i;
    has[!p][i.first][c[p]] = {x, i.second};
    color[i.second] = c[p];
  }
  int solve(vector<pair<int, int> > &e, vector<int> &res) {
    int m = ((int)e.size()), ans = 0;
    for (int i = 0; i < m; i++)
      ans = max({ans, ++deg[0][e[i].first + 1], ++deg[1][e[i].second + 1]});
    prep(ans);
    for (int i = 0; i < m; i++) {
      int x[2] = {e[i].first + 1, e[i].second + 1};
      for (int d = 0; d < 2; d++)
        for (c[d] = 1; has[d][x[d]][c[d]].second; c[d]++)
          ;
      if (c[0] != c[1]) dfs(x[1], 1);
      for (int d = 0; d < 2; d++) has[d][x[d]][c[0]] = {x[!d], i + 1};
      color[i + 1] = c[0];
    }
    res.resize(m);
    for (int i = 0; i < m; i++) res[i] = color[i + 1];
    return ans;
  }
};
int main() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  id = n + m;
  vector<pair<int, int> > orden;
  map<pair<int, int>, int> colors;
  for (int i = 0; i < n; i++) lft[i].push_back(i);
  for (int i = 0; i < m; i++) rht[i].push_back(i + n);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    degposta[x]++, degposta[y + n]++;
    int xid = lft[x].back(), yid = rht[y].back();
    orden.push_back({xid, yid});
    if (++deg[xid] == t) lft[x].push_back(id++);
    if (++deg[yid] == t) rht[y].push_back(id++);
  }
  vector<int> res;
  EC ec;
  ec.solve(orden, res);
  int r = 0;
  for (int i = 0; i < n + m; i++) r += degposta[i] % t != 0;
  cout << r << '\n';
  for (auto e : res) cout << e << " ";
  cout << '\n';
  return 0;
}
