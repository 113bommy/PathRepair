#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 300010;
int v[MAXN][26];
int qtd[MAXN];
int ans[MAXN];
int dfs(int x) {
  int ans = 1;
  for (int i = 0; i < (26); ++i)
    if (v[x][i]) ans += dfs(v[x][i]);
  return qtd[x] = ans;
}
vector<pair<int, int> > newvtxs;
int beg;
int n;
void dfs2(int v1, int v2) {
  for (int i = 0; i < (26); ++i)
    if (v[v1][i]) {
      if (!v[v2][i]) {
        newvtxs.push_back(make_pair(v2, i));
        v[v2][i] = beg++;
      }
      dfs2(v[v1][i], v[v2][i]);
    }
}
int solve(int x) {
  int maxvtx = -1, maxqtd = -1;
  int oldtot = qtd[x];
  for (int i = 0; i < (26); ++i) {
    if (v[x][i] && qtd[v[x][i]] > maxqtd) {
      maxqtd = qtd[v[x][i]];
      maxvtx = i;
    }
  }
  if (maxvtx == -1) return 0;
  newvtxs.clear();
  beg = n + 1;
  for (int i = 0; i < (26); ++i)
    if (i != maxvtx && v[x][i]) {
      dfs2(v[x][i], v[x][maxvtx]);
    }
  int newtot = maxqtd + (int)((newvtxs).size());
  for (int i = (int)((newvtxs).size()) - 1; i >= 0; --i) {
    v[newvtxs[i].first][newvtxs[i].second] = 0;
  }
  return newtot - oldtot;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < (n - 1); ++i) {
    int x, y;
    char w;
    cin >> x >> y >> w;
    v[x][w - 'a'] = y;
  }
  dfs(1);
  queue<pair<int, int> > q;
  q.push({1, 0});
  for (int i = 0; i < (n); ++i) ans[i] = n;
  int pans, minans = 0x3f3f3f3f;
  while (!q.empty()) {
    int lvl = q.front().second;
    int vtx = q.front().first;
    ans[lvl] += solve(vtx);
    if (ans[lvl] < minans) {
      minans = ans[lvl];
      pans = lvl;
    } else if (ans[lvl] == minans)
      pans = min(pans, lvl);
    q.pop();
    for (int i = 0; i < (26); ++i)
      if (v[vtx][i]) q.push({v[vtx][i], lvl + 1});
  }
  cout << minans << endl << pans + 1 << endl;
  return 0;
}
