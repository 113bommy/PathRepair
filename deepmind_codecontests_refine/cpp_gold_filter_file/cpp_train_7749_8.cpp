#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
vector<pair<int, int>> edge[402];
map<pair<int, int>, int> edgeinfo;
vector<vector<int>> d[402];
vector<vector<int>> p[402];
int w[402];
int ja[402];
int dab[402];
int dabi;
int par[402];
void preback(int now, int parent) {
  int i, j, k;
  int pos = 0, mpos = 0;
  int jai = 0;
  w[now] = 0;
  par[now] = parent;
  for (auto e : edge[now]) {
    if (e.first == parent) continue;
    jai++;
    preback(e.first, now);
    w[now] += w[e.first];
  }
  ja[now] = jai;
  w[now]++;
  d[now].emplace_back(w[now] + 1);
  p[now].emplace_back(w[now] + 1);
  for (i = 0; i < edge[now].size(); i++) {
    d[now].emplace_back(w[now] + 1);
    p[now].emplace_back(w[now] + 1);
  }
}
void back(int now, int parent) {
  int i, j, k;
  int pos = 0, mpos = 1;
  d[now][0][1] = 0;
  for (auto e : edge[now]) {
    int next = e.first;
    if (e.first == parent) continue;
    pos++;
    back(e.first, now);
    for (i = 1; i <= mpos; i++) {
      for (j = 0; j <= w[next]; j++) {
        if (d[now][pos][i + j] > d[now][pos - 1][i] + d[next][ja[next]][j]) {
          d[now][pos][i + j] = d[now][pos - 1][i] + d[next][ja[next]][j];
          p[now][pos][i + j] = j;
        }
      }
    }
    mpos += w[next];
  }
  d[now][ja[now]][0] = 1;
}
void ansback(int now, int x, int parent) {
  int i, j;
  int pos = ja[now];
  for (i = edge[now].size(); i >= 1; i--) {
    if (edge[now][i - 1].first == par[now]) continue;
    if (p[now][pos][x] == 0) {
      dab[dabi++] = edge[now][i - 1].second;
    } else {
      ansback(edge[now][i - 1].first, p[now][pos][x], now);
      x -= p[now][pos][x];
    }
    pos--;
  }
}
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    edge[x].push_back(pair<int, int>(y, i + 1));
    edge[y].push_back(pair<int, int>(x, i + 1));
    edgeinfo[pair<int, int>(x, y)] = i + 1;
    edgeinfo[pair<int, int>(y, x)] = i + 1;
  }
  preback(0, -1);
  for (i = 0; i < n; i++) {
    for (j = 0; j < d[i].size(); j++)
      for (k = 0; k < d[i][j].size(); k++) d[i][j][k] = ((1 << 30) - 1);
  }
  back(0, -1);
  int mi = ((1 << 30) - 1), mii;
  for (i = 0; i < n; i++) {
    if (m >= d[i][ja[i]].size()) continue;
    int x = d[i][ja[i]][m] + (i != 0);
    if (x < mi) {
      mi = x;
      mii = i;
    }
  }
  if (mii != 0) {
    dab[dabi++] = edgeinfo[pair<int, int>(mii, par[mii])];
  }
  ansback(mii, m, -1);
  printf("%d\n", dabi);
  for (i = 0; i < dabi; i++) printf("%d ", dab[i]);
  return 0;
}
