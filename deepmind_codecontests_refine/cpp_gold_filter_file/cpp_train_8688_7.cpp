#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 205;
int hh[maxn][2], tt[maxn][2], n[2], r;
char col[maxn][maxn];
int dis[maxn][maxn];
vector<pair<int, int> > vv;
int dfs(int h, int t) {
  col[h][t] = 1;
  int i, j, h1, t1;
  for (j = 0; j < 2; j++)
    for (i = 0; i < n[j]; i++) {
      h1 = h;
      t1 = t;
      if (j)
        t1 -= (i + 1);
      else
        h1 -= (i + 1);
      if (t1 < 0 || h1 < 0) continue;
      h1 += hh[i][j];
      t1 += tt[i][j];
      if (h1 + t1 > r || col[h1][t1] == 2) continue;
      if (col[h1][t1] == 1) return 1;
      if (dfs(h1, t1)) return 1;
    }
  col[h][t] = 2;
  vv.push_back(make_pair(h, t));
  return 0;
}
void new_dfs() {
  int i, j, k, h, t, h1, t1;
  for (i = 0; i < (int)vv.size(); i++) dis[vv[i].first][vv[i].second] = 0;
  for (k = 0; k < (int)vv.size(); k++) {
    h = vv[k].first;
    t = vv[k].second;
    for (j = 0; j < 2; j++)
      for (i = 0; i < n[j]; i++) {
        h1 = h;
        t1 = t;
        if (j)
          t1 -= (i + 1);
        else
          h1 -= (i + 1);
        if (t1 < 0 || h1 < 0) continue;
        h1 += hh[i][j];
        t1 += tt[i][j];
        if (h1 + t1 > r) continue;
        dis[h1][t1] = max(dis[h1][t1], dis[h][t] + 1);
      }
  }
}
void obr_bfs() {
  int i, j, h1, t1, h, t;
  queue<pair<int, int> > qq;
  col[0][0] = 1;
  qq.push(make_pair(0, 0));
  while (!qq.empty()) {
    h = qq.front().first;
    t = qq.front().second;
    qq.pop();
    for (j = 0; j < 2; j++)
      for (i = 0; i < n[j]; i++)
        if (h >= hh[i][j] && t >= tt[i][j]) {
          h1 = h - hh[i][j];
          t1 = t - tt[i][j];
          if (j)
            t1 += i + 1;
          else
            h1 += i + 1;
          if (h1 + t1 > r) continue;
          if (!col[h1][t1]) {
            col[h1][t1] = 1;
            dis[h1][t1] = dis[h][t] + 1;
            qq.push(make_pair(h1, t1));
          }
        }
  }
}
int main() {
  int h, t, i, j, mx;
  cin >> h >> t >> r;
  for (j = 0; j < 2; j++) {
    cin >> n[j];
    for (i = 0; i < n[j]; i++) cin >> hh[i][j] >> tt[i][j];
  }
  obr_bfs();
  if (col[h][t]) {
    printf("Ivan\n%d", dis[h][t]);
    return 0;
  }
  if (dfs(h, t)) {
    printf("Draw");
    return 0;
  }
  reverse(vv.begin(), vv.end());
  new_dfs();
  mx = 0;
  for (i = 0; i < (int)vv.size(); i++)
    if (mx < dis[vv[i].first][vv[i].second])
      mx = dis[vv[i].first][vv[i].second];
  printf("Zmey\n%d", mx + 1);
}
