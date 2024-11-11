#include <bits/stdc++.h>
using namespace std;
const int MN = 105, INF = 200;
int n, m, dis[MN][MN], d[MN][MN], st[MN], fn[MN], mark[MN];
vector<int> good[MN], all[MN], vec[INF];
void floyd() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dis[i][j] = INF;
  for (int i = 0; i < n; i++) dis[i][i] = 0;
  for (int i = 0; i < n; i++)
    for (int j : all[i])
      if (!mark[i] && !mark[j]) dis[i][j] = 1;
  for (int k = 0; k < n; k++)
    for (int u = 0; u < n; u++)
      for (int v = 0; v < n; v++)
        dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
}
int main() {
  int s, e;
  cin >> n >> m >> s >> e;
  s--, e--;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    all[--u].push_back(--v);
  }
  floyd();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) d[i][j] = dis[i][j];
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> st[i] >> fn[i];
    st[i]--, fn[i]--;
    for (int i = 0; i < INF; i++) vec[i].clear();
    for (int v = 0; v < n; v++)
      if (dis[st[i]][v] + dis[v][fn[i]] == dis[st[i]][fn[i]])
        vec[dis[st[i]][v]].push_back(v);
    for (int l = 0; l < INF; l++)
      if (vec[l].size() == 1) good[i].push_back(vec[l][0]);
  }
  mark[e] = 1;
  floyd();
  for (int mrk = 2; mrk <= 2 + n; mrk++, floyd())
    for (int i = 0; i < k; i++)
      for (int j : good[i])
        if (!mark[j])
          if (dis[j][fn[i]] != d[j][fn[i]]) mark[j] = mrk;
  cout << mark[s] - 1;
}
