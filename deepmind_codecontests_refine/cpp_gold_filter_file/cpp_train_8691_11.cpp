#include <bits/stdc++.h>
using namespace std;
const long long MOD = 2000 * 1000 * 1000 + 11;
int n, m, s, t;
long long lg_edge[100001];
vector<pair<int, int> > ls_edges;
vector<pair<int, int> > v[100001][2];
long long d[100001][2];
long long memo_shortest[100001][2];
long long nb_shortest(int u, int dest) {
  if (memo_shortest[u][dest] != -1) return memo_shortest[u][dest];
  const int k = 1 - dest;
  memo_shortest[u][dest] = 0;
  for (int i = 0; i < (int)v[u][k].size(); i++)
    if (d[u][dest] == d[v[u][k][i].first][dest] + v[u][k][i].second)
      memo_shortest[u][dest] =
          (memo_shortest[u][dest] + nb_shortest(v[u][k][i].first, dest)) % MOD;
  return memo_shortest[u][dest];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 0; i < m; i++) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    ls_edges.push_back(make_pair(a, b));
    lg_edge[i] = l;
    v[a][0].push_back(make_pair(b, l));
    v[b][1].push_back(make_pair(a, l));
  }
  for (int i = 1; i <= n; i++) d[i][0] = d[i][1] = -1;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  for (int k = 0; k < 2; k++) {
    pq.push(make_pair(0, (k == 0) ? s : t));
    while (!pq.empty()) {
      const long long d_act = pq.top().first;
      const int x_act = pq.top().second;
      pq.pop();
      if (d[x_act][k] == -1) {
        d[x_act][k] = d_act;
        for (int i = 0; i < (int)v[x_act][k].size(); i++)
          if (d[v[x_act][k][i].first][k] == -1)
            pq.push(
                make_pair(d_act + v[x_act][k][i].second, v[x_act][k][i].first));
      }
    }
  }
  for (int i = 1; i <= n; i++) memo_shortest[i][0] = memo_shortest[i][1] = -1;
  memo_shortest[s][0] = memo_shortest[t][1] = 1;
  const long long nb_SP = nb_shortest(s, 1);
  const long long lg_trajet = d[s][1];
  for (int i = 0; i < m; i++) {
    if ((d[ls_edges[i].first][0] == -1) || (d[ls_edges[i].second][1] == -1))
      printf("NO\n");
    else if (((nb_shortest(ls_edges[i].first, 0) *
               nb_shortest(ls_edges[i].second, 1)) %
                  MOD ==
              nb_SP) &&
             (lg_trajet ==
              d[ls_edges[i].first][0] + lg_edge[i] + d[ls_edges[i].second][1]))
      printf("YES\n");
    else {
      long long nouv_lg =
          lg_trajet - d[ls_edges[i].first][0] - d[ls_edges[i].second][1] - 1;
      if (nouv_lg < 1)
        printf("NO\n");
      else
        printf("CAN %I64d\n", lg_edge[i] - nouv_lg);
    }
  }
  return 0;
}
