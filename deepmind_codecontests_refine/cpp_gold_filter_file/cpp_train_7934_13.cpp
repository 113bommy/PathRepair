#include <bits/stdc++.h>
using namespace std;
vector<vector<string> > G;
bool was[16][16][16];
int dj[9] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
int di[9] = {0, 0, 0, 1, -1, 1, -1, -1, 1};
bool okay(pair<int, int> v, int t) {
  return v.first >= 0 && v.second >= 0 && v.first < 8 && v.second < 8 &&
         (t == 8 || G[t][v.first][v.second] == '.');
}
bool dfs(pair<int, int> v, int t) {
  if (v == make_pair(0, 7) || t == 8) return true;
  if (was[v.first][v.second][t]) return false;
  was[v.first][v.second][t] = 1;
  for (int i = (0); i < (9); ++i) {
    pair<int, int> to = make_pair(v.first + dj[i], v.second + di[i]);
    if (okay(to, t) && okay(to, t + 1) && dfs(to, t + 1)) return true;
  }
  return false;
}
int main() {
  G.resize(8);
  for (int i = (0); i < (G.size()); ++i) G[i].resize(8);
  for (int i = (0); i < (8); ++i) cin >> G[0][i];
  G[0][0][7] = G[0][7][0] = '.';
  for (int k = (1); k < (8); ++k) {
    G[k] = G[k - 1];
    for (int i = (0); i < (8); ++i) G[k][7][i] = '.';
    for (int j = 6; j >= 0; --j)
      for (int i = (0); i < (8); ++i)
        if (G[k][j][i] == 'S') {
          G[k][j][i] = '.';
          G[k][j + 1][i] = 'S';
        }
  }
  memset(was, 0, sizeof(was));
  if (dfs(make_pair(7, 0), 0))
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
