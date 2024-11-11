#include <bits/stdc++.h>
using namespace std;
const int N = 30005, K = 205;
int n, k, fa[N];
int d[K][N], p[K];
int at[K][N];
vector<pair<int, int> > vec[N];
void GG() {
  puts("-1");
  exit(0);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (int)(1); i <= (int)(k); i++)
    for (int j = (int)(1); j <= (int)(n); j++) scanf("%d", &d[i][j]);
  for (int i = (int)(1); i <= (int)(k); i++) {
    for (int j = (int)(1); j <= (int)(n); j++)
      if (!d[i][j])
        if (p[i])
          GG();
        else
          p[i] = j;
    if (!p[i]) GG();
  }
  fa[p[1]] = -1;
  for (int i = (int)(2); i <= (int)(k); i++) {
    if (d[1][p[i]] != d[i][p[1]]) GG();
    for (int j = (int)(1); j <= (int)(n); j++)
      if (d[1][j] + d[i][j] == d[1][p[i]])
        if (at[i][d[1][j]])
          GG();
        else
          at[i][d[1][j]] = j;
    for (int j = (int)(0); j <= (int)(d[1][p[i]]); j++)
      if (!at[j]) GG();
    for (int j = (int)(1); j <= (int)(d[1][p[i]]); j++) {
      int x = at[i][j], y = at[i][j - 1];
      if (!fa[x])
        fa[x] = y;
      else if (fa[x] != y)
        GG();
    }
  }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (fa[i]) vec[i].push_back(pair<int, int>(0, i));
  at[1][0] = 1;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!fa[i]) {
      int id = 1, v = 0;
      for (int j = (int)(2); j <= (int)(k); j++) {
        int val = (d[1][i] + d[1][p[j]] - d[j][i]) / 2;
        if (val > v) v = val, id = j;
      }
      vec[at[id][v]].push_back(pair<int, int>(d[1][i] - v, i));
    }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (vec[i].size()) {
      sort(vec[i].begin(), vec[i].end());
      pair<int, int> la = vec[i][0];
      for (int j = (int)(1); j <= (int)(vec[i].size() - 1); j++) {
        pair<int, int> x = vec[i][j];
        if (x.first > la.first + 1) la = vec[i][j - 1];
        if (x.first > la.first + 1) GG();
        fa[x.second] = la.second;
      }
    }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (fa[i] != -1) printf("%d %d\n", i, fa[i]);
}
