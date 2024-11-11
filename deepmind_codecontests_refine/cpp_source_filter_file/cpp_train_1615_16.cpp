#include <bits/stdc++.h>
using namespace std;
int const maxn = 123460;
vector<int> gr[maxn];
int d[maxn];
int mask[maxn];
int isfree[maxn];
pair<int, int> dfs(int v, int p = -1, int deep = 0) {
  pair<int, int> ans = make_pair(-deep, v);
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (isfree[nv] == 0 && nv != p) {
      pair<int, int> tmp = dfs(nv, v, deep + 1);
      if (ans > tmp) ans = tmp;
    }
  }
  return ans;
}
int isleaves[maxn];
int minans = maxn;
void dfs_all(int v, int need_deep, int deep = 0, int p = -1) {
  if (deep == need_deep && v < minans && isleaves[v] == 1) minans = v;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv != p && isfree[nv] == 0) {
      dfs_all(nv, need_deep, deep + 1, v);
    }
  }
}
vector<int> path;
bool dfs_find(int v, int needv, int p = -1) {
  if (v == needv) {
    path.push_back(needv);
    return true;
  }
  bool ans = false;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv != p && isfree[nv] == 0) {
      ans |= dfs_find(nv, needv, v);
      if (ans) {
        path.push_back(v);
        return true;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
    gr[b].push_back(a);
    ++d[a];
    ++d[b];
  }
  queue<int> vert;
  for (int i = 1; i <= n; ++i)
    if (d[i] <= 1) vert.push(i);
  for (int i = 0; i < m; ++i) {
    int cur;
    cin >> cur;
    mask[cur] = 1;
  }
  int cnt_edges = n - 1;
  while (!vert.empty()) {
    int v = vert.front();
    vert.pop();
    if (mask[v] == 0) {
      for (int i = 0; i < gr[v].size(); ++i) {
        int nv = gr[v][i];
        if (d[nv] > 0) {
          --d[v];
          --d[nv];
          --cnt_edges;
          isfree[v] = 1;
          if (d[nv] == 0) {
            vert.push(nv);
          }
        }
      }
    } else {
      isleaves[v] = 1;
    }
  }
  int s = 0;
  for (int i = 1; i <= n; ++i)
    if (isfree[i] == 0) s = i;
  pair<int, int> tmp = dfs(s);
  pair<int, int> tmp_len = dfs(tmp.second);
  dfs_find(tmp.second, tmp_len.second);
  int ans2 = cnt_edges * 2 + tmp_len.first;
  if (path.size() % 2 == 0) {
    int tt = path.size() / 2;
    dfs_all(path[tt], tt);
    dfs_all(path[tt + 1], tt);
  } else {
    int tt = path.size() / 2;
    dfs_all(path[tt], tt);
  }
  cout << minans << endl << ans2 << endl;
}
