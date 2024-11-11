#include <bits/stdc++.h>
using namespace std;
char arr[1010][15][15];
int nn, mm, kk, ww;
vector<int> g2[1010];
vector<pair<int, int> > anss;
bool used[1010];
void dfs(int v, int p) {
  used[v] = 1;
  if (v != 0) {
    anss.push_back(make_pair(v, p));
  }
  for (int i = 0; i < g2[v].size(); i++) {
    int to = g2[v][i];
    if (!used[to]) {
      dfs(to, v);
    }
  }
}
int get(int f, int s) {
  int ret = 0;
  for (int i = 1; i <= nn; i++) {
    for (int j = 1; j <= mm; j++) {
      if (arr[f][i][j] != arr[s][i][j]) ++ret;
    }
  }
  return ret * ww;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> nn >> mm >> kk >> ww;
  for (int i = 1; i <= kk; ++i) {
    for (int j = 1; j <= nn; j++) {
      for (int z = 1; z <= mm; z++) {
        cin >> arr[i][j][z];
      }
    }
  }
  vector<pair<int, pair<int, int> > > g;
  for (int i = 1; i <= kk; i++) {
    g.push_back(make_pair(mm * nn, make_pair(0, i)));
    g.push_back(make_pair(mm * nn, make_pair(i, 0)));
  }
  for (int i = 1; i <= kk; i++) {
    for (int j = 1; j <= kk; j++) {
      if (i == j) continue;
      int cnt = get(i, j);
      g.push_back(make_pair(cnt, make_pair(i, j)));
      g.push_back(make_pair(cnt, make_pair(j, i)));
    }
  }
  int cost = 0;
  vector<pair<int, int> > res;
  sort(g.begin(), g.end());
  vector<int> tree_id(kk + 1);
  for (int i = 0; i <= kk; ++i) tree_id[i] = i;
  for (int i = 0; i < g.size(); ++i) {
    int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
    if (tree_id[a] != tree_id[b]) {
      cost += l;
      res.push_back(make_pair(a, b));
      int old_id = tree_id[b], new_id = tree_id[a];
      for (int j = 0; j <= kk; ++j)
        if (tree_id[j] == old_id) tree_id[j] = new_id;
    }
  }
  cout << cost << endl;
  for (int i = 0; i < res.size(); i++) {
    g2[res[i].first].push_back(res[i].second);
    g2[res[i].second].push_back(res[i].first);
  }
  dfs(0, -1);
  for (int i = 0; i < anss.size(); i++) {
    cout << anss[i].first << " " << anss[i].second << endl;
  }
  return 0;
}
