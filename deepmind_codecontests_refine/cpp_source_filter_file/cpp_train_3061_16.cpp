#include <bits/stdc++.h>
using namespace std;
int n, m, e[2][55][55], g[2][2][55][55][2 * 55], f[55][2 * 55][2];
int pway[55][55][55 * 2], away[55][55][55 * 2];
vector<int> edge[55 * 55][2];
vector<pair<int, int> > G[2][55];
pair<int, int> walk(vector<int> &path, int t, int u) {
  for (int i = 0, v; i < path.size(); i++) {
    if (!e[t][u][v = path[i]] || path.size() > 2 * n)
      return make_pair(0x3f3f3f3f, -1);
    int p = e[t][u][v];
    for (int j : edge[p][t]) path.push_back(j);
    u = v;
  }
  return make_pair(path.size(), u);
}
void Solve(int t) {
  for (int i = (1), LIM = (n); i <= LIM; i++)
    for (pair<int, int> o : G[t][i])
      for (int j = (0), LIM = (edge[o.second][t].size() - 1); j <= LIM; j++)
        if (edge[o.second][t][j] == o.first) {
          vector<int> path, path2;
          for (int k = (j + 1), LIM = (edge[o.second][t].size() - 1); k <= LIM;
               k++)
            path.push_back(edge[o.second][t][k]);
          pair<int, int> ret = walk(path, t, o.first);
          ret.first++;
          if (ret.second == -1) continue;
          if (j == 0)
            pway[i][ret.second][ret.first]++;
          else if (edge[o.second][t][j - 1] == i) {
            for (int k = (j - 2), LIM = (0); k >= LIM; k--)
              path2.push_back(edge[o.second][t][k]);
            pair<int, int> anr = walk(path2, t ^ 1, i);
            if (anr.second != -1) {
              away[anr.second][ret.second][anr.first + ret.first]++;
            }
          }
        }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1), LIM = (m); i <= LIM; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int K;
    scanf("%d", &K);
    edge[i][0].resize(K);
    for (int j = (0), LIM = (K - 1); j <= LIM; j++) scanf("%d", &edge[i][0][j]);
    edge[i][1] = edge[i][0], reverse(edge[i][1].begin(), edge[i][1].end());
    G[0][u].push_back(make_pair(v, i));
    G[1][v].push_back(make_pair(u, i));
    e[0][u][v] = e[1][v][u] = i;
    if (!K) g[0][0][u][v][1] = 1;
  }
  Solve(0);
  for (int i = (1), LIM = (n); i <= LIM; i++)
    for (int j = (1), LIM = (n); j <= LIM; j++)
      for (int k = (1), LIM = (2 * n); k <= LIM; k++)
        g[1][1][i][j][k] = away[i][j][k], away[i][j][k] = 0,
        g[0][1][i][j][k] = pway[i][j][k], pway[i][j][k] = 0;
  Solve(1);
  for (int i = (1), LIM = (n); i <= LIM; i++)
    for (int j = (1), LIM = (n); j <= LIM; j++)
      for (int k = (1), LIM = (2 * n); k <= LIM; k++)
        g[1][0][i][j][k] = pway[j][i][k];
  for (int i = (1), LIM = (n); i <= LIM; i++)
    for (int j = (1), LIM = (2 * n); j <= LIM; j++)
      for (int k = (0), LIM = (1); k <= LIM; k++)
        for (int p = (1), LIM = (n); p <= LIM; p++)
          f[j][i][k] = (f[j][i][k] + g[1][k][p][i][j]) % 1000000007;
  for (int L = (1), LIM = (2 * n); L <= LIM; L++) {
    int ans = 0;
    for (int i = (1), LIM = (n); i <= LIM; i++)
      ans = (ans + f[L][i][1]) % 1000000007;
    for (int aL = (1), LIM = (2 * n - L); aL <= LIM; aL++)
      for (int i = (1), LIM = (n); i <= LIM; i++)
        for (int j = (1), LIM = (n); j <= LIM; j++)
          for (int p = (0), LIM = (1); p <= LIM; p++)
            for (int ap = (0), LIM = (1); ap <= LIM; ap++)
              f[L + aL][j][ap] = (f[L + aL][j][ap] +
                                  1ll * f[L][i][p] * g[p ^ 1][ap][i][j][aL]) %
                                 1000000007;
    printf("%d\n", (ans + 1000000007) % 1000000007);
  }
}
