#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
vector<int> gg[200009], g[200009];
bool isSpecial[200009];
int special[200009];
int dfs1(int v, int pr) {
  int res = 0;
  for (auto to : gg[v]) {
    if (to == pr) continue;
    auto c = dfs1(to, v);
    if (c) {
      g[v].push_back(to);
      res += c;
    }
  }
  res += isSpecial[v];
  return res;
}
long long dp[200009][2];
long long dfs2(int v, int back) {
  auto &res = dp[v][back];
  if (res == -1) {
    long long sum = 0;
    for (auto to : g[v]) sum += dfs2(to, 1) + 2;
    res = sum;
    if (!back) {
      for (auto to : g[v])
        res = min(res, sum - (dfs2(to, 1) + 2) + (dfs2(to, 0) + 1));
    }
  }
  return res;
}
pair<long long, int> RES((1ll << 60ll), -1);
void dfs(int v, long long b, long long nb) {
  long long sum = b;
  for (auto to : g[v]) sum += dfs2(to, 1) + 2;
  pair<long long, int> res1(sum - b + nb, -1), res2((1ll << 60ll), -1);
  for (auto to : g[v]) {
    pair<long long, int> tmp(sum - (dfs2(to, 1) + 2) + (dfs2(to, 0) + 1), to);
    if (tmp.first <= res1.first)
      res2 = res1, res1 = tmp;
    else if (tmp.first <= res2.first)
      res2 = tmp;
  }
  RES = min(RES, make_pair(res1.first, v));
  for (auto to : g[v]) {
    long long nnb = (res1.second == to ? res2 : res1).first - (dfs2(to, 1) + 2);
    dfs(to, sum - dfs2(to, 1), nnb + 1);
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, m, i, j, a, b;
  scanf("%d %d", &n, &m);
  for (i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    a--, b--;
    gg[a].push_back(b);
    gg[b].push_back(a);
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &special[i]);
    special[i]--;
    isSpecial[special[i]] = 1;
  }
  dfs1(special[0], -1);
  dfs(special[0], 0, 0);
  cout << (RES.second + 1) << endl << RES.first << endl;
}
