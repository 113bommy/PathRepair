#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
vector<pair<int, int> > a[MAXN];
int ptr[MAXN], b[MAXN], e_v[MAXN], sz[MAXN], total;
bool markv[MAXN], mark[MAXN], mark2[MAXN];
pair<int, int> e[MAXN];
void dfs(int v, int u, int id) {
  while (ptr[v] < a[v].size()) {
    pair<int, int> u2 = a[v][ptr[v]];
    ptr[v]++;
    if (!mark[u2.second]) {
      mark[u2.second] = true;
      dfs(u2.first, v, u2.second);
    }
  }
  if (u != -1) {
    b[u]++;
    if (u < v)
      e_v[id] = 0;
    else
      e_v[id] = 1;
  }
}
void dfs2(int v) {
  markv[v] = true;
  for (auto u : a[v]) {
    if (!markv[u.first]) {
      markv[u.first] = true;
      dfs2(u.first);
      int mn = min(sz[u.first], total - sz[u.first]);
      if (mn % 2 == 1) e_v[u.second] = 1 - e_v[u.second];
      sz[v] += sz[u.first];
    }
  }
  if (mark2[v] == true) sz[v]++;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x > y) swap(x, y);
    a[x].push_back({y, i});
    a[y].push_back({x, i});
    e[i] = make_pair(x, y);
  }
  vector<int> v;
  for (int i = 0; i < n; i++)
    if (a[i].size() % 2 == 1) v.push_back(i);
  int cnt = m;
  while (v.size()) {
    int x1 = v.back();
    v.pop_back();
    int x2 = v.back();
    v.pop_back();
    if (x1 > x2) swap(x1, x2);
    a[x1].push_back({x2, cnt});
    a[x2].push_back({x1, cnt});
    e[cnt++] = make_pair(x1, x2);
  }
  if (cnt % 2 == 1) a[0].push_back({0, cnt}), a[0].push_back({0, cnt++});
  dfs(0, -1, -1);
  for (int i = 0; i < n; i++)
    if (b[i] % 2 == 1) mark2[i] = 1, total++;
  dfs2(0);
  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    if (e_v[i] == 0)
      cout << e[i].first + 1 << ' ' << e[i].second + 1 << '\n';
    else
      cout << e[i].second + 1 << ' ' << e[i].first + 1 << '\n';
  }
  return 0;
}
