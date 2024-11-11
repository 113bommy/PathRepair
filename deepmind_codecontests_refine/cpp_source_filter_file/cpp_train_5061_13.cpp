#include <bits/stdc++.h>
using namespace std;
int V, E, src, snk;
vector<int> la, nxt, oppo, capa;
void init() {
  E = 0;
  la.clear();
  nxt.clear();
  oppo.clear();
  capa.clear();
  la = vector<int>(V, -1);
}
void add(int u, int v, int c) {
  nxt.push_back(la[u]);
  la[u] = E++;
  oppo.push_back(v);
  capa.push_back(c);
}
vector<int> dist;
queue<int> q;
bool bfs() {
  dist = vector<int>(V, -1);
  q.push(src);
  dist[src] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = la[u]; i != -1; i = nxt[i]) {
      int v = oppo[i];
      if (capa[i] && dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist[snk] != -1;
}
vector<int> laa;
int dfs(int u, int f) {
  if (u == snk) return f;
  for (int i = laa[u]; i != -1; i = nxt[i]) {
    laa[u] = i;
    int v = oppo[i];
    if (capa[i] && dist[v] == dist[u] + 1) {
      if (int tmp = dfs(v, min(capa[i], f))) {
        capa[i] -= tmp;
        capa[i ^ 1] += tmp;
        return tmp;
      }
    }
  }
  return 0;
}
int dinic() {
  int tf = 0;
  while (bfs()) {
    laa = la;
    while (int tmp = dfs(src, 1e9)) tf += tmp;
  }
  return tf;
}
int N, M, P, K;
vector<int> S;
vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;
vector<vector<int> > Rdist;
void dijkstra(int s) {
  Rdist[s] = vector<int>(N, 1e9);
  pq.push(pair<int, int>(0, S[s]));
  Rdist[s][S[s]] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    int ud = -pq.top().first;
    pq.pop();
    if (ud > Rdist[s][u]) continue;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int vd = adj[u][i].second;
      if (Rdist[s][v] > Rdist[s][u] + vd) {
        Rdist[s][v] = Rdist[s][u] + vd;
        pq.push(pair<int, int>(-Rdist[s][v], v));
      }
    }
  }
}
int main() {
  scanf("%d %d %d %d", &N, &M, &P, &K);
  S.resize(P);
  for (int i = 0; i < P; i++) {
    scanf("%d", &S[i]);
    S[i]--;
  }
  adj.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    adj[u].push_back(pair<int, int>(v, w));
    adj[v].push_back(pair<int, int>(u, w));
  }
  Rdist.resize(P);
  for (int i = 0; i < P; i++) {
    dijkstra(i);
  }
  int s = 0, e = 1e9;
  int p = -1;
  while (s <= e) {
    int m = (s + e) >> 1;
    V = 2 * N + 2, src = V - 2, snk = V - 1;
    init();
    for (int i = 0; i < P; i++) {
      add(src, S[i], 1);
      add(S[i], src, 0);
    }
    for (int i = 0; i < N; i++) {
      add(N + i, snk, 1);
      add(snk, N + i, 0);
    }
    for (int i = 0; i < P; i++) {
      for (int j = 0; j < N; j++) {
        if (Rdist[i][j] <= m) {
          add(S[i], N + j, 1);
          add(N + j, S[i], 0);
        }
      }
    }
    if (dinic() >= K) {
      p = m;
      e = m - 1;
    } else
      s = m + 1;
  }
  printf("%d", p);
}
