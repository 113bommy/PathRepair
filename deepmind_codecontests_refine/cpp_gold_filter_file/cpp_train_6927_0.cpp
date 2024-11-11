#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5010;
const int INF = 1e9;
vector<int> bi[N];
int dis[N][N], nei[N][N];
int cnt, sum, len[N];
queue<int> Q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    bi[a].push_back(b);
    nei[a][b] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) dis[i][j] = INF;
    dis[i][i] = 0;
    Q.push(i);
    while (!Q.empty()) {
      int t = Q.front();
      Q.pop();
      for (int j = 0; j < bi[t].size(); ++j)
        if (dis[i][bi[t][j]] > dis[i][t] + 1)
          dis[i][bi[t][j]] = dis[i][t] + 1, Q.push(bi[t][j]);
    }
  }
  for (int i = 1; i <= n; ++i) len[i] = INF;
  for (int i = 1; i <= n; ++i) {
    int GG = 0, F = -1;
    for (int j = 1; j <= n; ++j)
      if (dis[i][j] != INF && dis[j][i] == INF)
        GG = 1;
      else if (dis[i][j] != INF && F == -1)
        F = j;
    if (i != F) len[i] = -1;
    if (GG || !bi[i].size()) {
      len[F] = -1;
      continue;
    }
    if (F == i) cnt++;
    for (int j = 1; j <= n; ++j)
      if (nei[j][i]) len[F] = min(len[F], dis[i][j] + 1);
  }
  for (int i = 1; i <= n; ++i)
    if (len[i] != -1) sum += len[i];
  cout << n + 998 * sum + cnt << endl;
}
