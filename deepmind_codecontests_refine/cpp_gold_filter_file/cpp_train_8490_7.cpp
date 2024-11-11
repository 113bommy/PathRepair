#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int aa[200000];
vector<vector<pair<int, long long> > > g;
int up[20][200000];
long long len[20][200000];
int le[200000], ri[200000];
void dfs(int v, int p, long long cost) {
  a.push_back(v);
  le[v] = a.size() - 1;
  up[0][v] = p;
  for (int i = 1; i < 20; i++) up[i][v] = up[i - 1][up[i - 1][v]];
  len[0][v] = cost;
  for (int i = 1; i < 20; i++)
    len[i][v] = len[i - 1][v] + len[i - 1][up[i - 1][v]];
  for (int i = 0; i < (int)g[v].size(); i++)
    dfs(g[v][i].first, v, g[v][i].second);
  a.push_back(v);
  ri[v] = a.size() - 1;
}
int t[10000000];
void update(int v, int tl, int tr, int x, int y) {
  if (tl == tr) {
    t[v] += y;
    return;
  }
  int tm = (tl + tr) / 2;
  if (x <= tm)
    update(v * 2 + 1, tl, tm, x, y);
  else
    update(v * 2 + 2, tm + 1, tr, x, y);
  t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[v];
  int tm = (tl + tr) / 2;
  return get(v * 2 + 1, tl, tm, l, min(tm, r)) +
         get(v * 2 + 2, tm + 1, tr, max(tm + 1, l), r);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> aa[i];
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    g[x].push_back({i, y});
  }
  dfs(0, 0, 0);
  for (int i = 1; i < n; i++) {
    int v = i;
    long long c = 0;
    for (int j = 19; j >= 0; j--) {
      if (c + len[j][v] <= aa[i]) {
        c += len[j][v];
        v = up[j][v];
      }
    }
    if (v == i) continue;
    update(0, 0, (int)a.size() - 1, le[up[0][i]], 1);
    if (v != 0) update(0, 0, (int)a.size() - 1, le[up[0][v]], -1);
  }
  for (int i = 0; i < n; i++) {
    cout << get(0, 0, (int)a.size() - 1, le[i], ri[i]) << ' ';
  }
  cout << '\n';
  return 0;
}
