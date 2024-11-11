#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = (int)1e5 + 10;
const int P1 = (int)1e9 + 7, P2 = (int)1e9 + 9;
long long dist[2][MAXN];
vector<pair<int, int> > adj[2][MAXN];
long long npaths[2][MAXN][2];
int n, m, s, t;
void dijkstra(int i, int o) {
  memset(dist[i], INF, sizeof(dist[i]));
  dist[i][o] = 0;
  set<pair<long long, long long> > pq;
  pq.insert(pair<long long, long long>(0, o));
  while (!pq.empty()) {
    int v;
    v = pq.begin()->second;
    pq.erase(pq.begin());
    for (pair<int, int> edge : adj[i][v]) {
      int nxt, cst;
      tie(nxt, cst) = edge;
      if (dist[i][nxt] > dist[i][v] + cst) {
        pq.erase(pair<long long, long long>(dist[i][nxt], nxt));
        dist[i][nxt] = dist[i][v] + cst;
        pq.insert(pair<long long, long long>(dist[i][nxt], nxt));
      }
    }
  }
}
int indeg[MAXN];
void count_paths(int i, int o, long long mindist) {
  memset(indeg, 0, sizeof(indeg));
  for (int v = 1; v <= n; v++) {
    for (pair<int, int> edge : adj[i][v]) {
      int nxt, cst;
      tie(nxt, cst) = edge;
      if (dist[i][v] + cst + dist[i ^ 1][nxt] == mindist) indeg[edge.first]++;
    }
  }
  queue<int> fila;
  for (int v = 1; v <= n; v++)
    if (indeg[v] == 0) fila.push(v);
  memset(npaths[i], 0, sizeof(npaths[i]));
  npaths[i][o][0] = npaths[i][o][1] = 1;
  while (!fila.empty()) {
    int v = fila.front();
    fila.pop();
    for (pair<int, int> edge : adj[i][v]) {
      int nxt, cst;
      tie(nxt, cst) = edge;
      if (dist[i][v] + cst + dist[i ^ 1][nxt] != mindist) continue;
      npaths[i][nxt][0] += npaths[i][v][0];
      npaths[i][nxt][1] += npaths[i][v][1];
      npaths[i][nxt][0] %= P1;
      npaths[i][nxt][1] %= P2;
      if (--indeg[nxt] == 0) fila.push(nxt);
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  vector<tuple<int, int, int> > edges;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[0][u].push_back(pair<int, int>(v, c));
    adj[1][v].push_back(pair<int, int>(u, c));
    edges.push_back(tuple<int, int, int>(u, v, c));
  }
  dijkstra(0, s);
  dijkstra(1, t);
  count_paths(0, s, dist[0][t]);
  count_paths(1, t, dist[0][t]);
  for (tuple<int, int, int> edge : edges) {
    int u, v, c;
    tie(u, v, c) = edge;
    if (dist[0][u] + c + dist[1][v] != dist[0][t]) {
      if (dist[0][u] + 1 + dist[1][v] < dist[0][t]) {
        cout << "CAN " << dist[0][u] + c + dist[1][v] - dist[0][t] + 1 << endl;
      } else
        printf("NO\n");
    } else {
      if ((npaths[0][u][0] * npaths[1][v][0]) % P1 == npaths[0][t][0] &&
          (npaths[0][u][1] * npaths[1][v][1]) % P2 == npaths[0][t][1]) {
        printf("YES\n");
      } else if (c > 1)
        printf("CAN 1\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
