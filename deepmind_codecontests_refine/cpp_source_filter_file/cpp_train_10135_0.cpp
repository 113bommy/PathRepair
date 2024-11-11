#include <bits/stdc++.h>
#pragma GCC optimize("O3")
std::pair<int, int> DR[] = {{-1, 0}, {0, 1},   {1, 0}, {0, -1},
                            {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
using namespace std;
int sz[1 << 17], depth[1 << 17], cnt[1 << 17], p[1 << 17][20];
vector<int> vec[1 << 17];
int ans[1 << 17], n, m, nod, dist, x;
vector<int> trees;
vector<pair<int, int>> qry[1 << 17];
void prep(int nod, int par) {
  sz[nod] = 1;
  depth[nod] = depth[par] + 1;
  if (par) p[nod][0] = par;
  for (int i = 1; i <= 17; i++) p[nod][i] = p[p[nod][i - 1]][i - 1];
  for (auto it : vec[nod]) {
    prep(it, nod);
    sz[nod] += sz[it];
  }
}
void add(int nod) {
  cnt[depth[nod]]++;
  for (auto it : vec[nod]) add(it);
}
void nadd(int nod) {
  cnt[depth[nod]]--;
  for (auto it : vec[nod]) nadd(it);
}
int up(int nod, int dist) {
  for (int i = 0; i <= 17; i++) {
    if (dist & (1 << i)) nod = p[nod][i];
  }
  return nod;
}
void dfs(int nod, int par, bool keep) {
  pair<int, int> mx = {-1, -1};
  for (auto it : vec[nod]) mx = max(mx, make_pair(sz[it], it));
  for (auto it : vec[nod]) {
    if (it != mx.second) dfs(it, nod, 0);
  }
  if (mx.second != -1) dfs(mx.second, nod, 1);
  for (auto it : vec[nod])
    if (it != mx.second) add(it);
  cnt[depth[nod]]++;
  for (auto it : qry[nod]) {
    ans[abs(it.second)] += (it.second / abs(it.second)) * cnt[it.first] - 1;
  }
  if (keep) return;
  nadd(nod);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == 0)
      trees.push_back(i);
    else
      vec[x].push_back(i);
  }
  for (auto it : trees) {
    for (int i = 0; i <= 17; i++) p[0][i] = p[it][i] = it;
    prep(it, 0);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> nod >> dist;
    if (depth[nod] - 1 > dist)
      ans[i] = 0;
    else {
      qry[up(nod, dist)].push_back(make_pair(depth[nod], i));
    }
  }
  for (auto it : trees) {
    dfs(it, 0, 0);
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << ' ';
  }
}
