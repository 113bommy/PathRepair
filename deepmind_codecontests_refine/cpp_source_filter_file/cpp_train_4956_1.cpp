#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<map<int, int> > G;
vector<pair<int, int> > P;
vector<int> vis;
vector<int> chk;
int ccnt = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int> > rseg, cseg;
int dest;
bool con(int a, int b) {
  if (rseg[b].first <= rseg[a].first && rseg[a].first <= rseg[b].second)
    return true;
  if (rseg[b].first <= rseg[a].second && rseg[a].second <= rseg[b].second)
    return true;
  if (cseg[b].first <= cseg[a].first && cseg[a].first <= cseg[b].second)
    return true;
  if (cseg[b].first <= cseg[a].second && cseg[a].second <= cseg[b].second)
    return true;
  return false;
}
int main() {
  scanf("%d %d %d", &N, &M, &K);
  G.resize(N + 1);
  P.resize(K + 3);
  for (int i = 0; i < K; i++) {
    int r, c;
    scanf("%d %d", &r, &c);
    r--;
    c--;
    G[r][c] = i;
    P[i] = pair<int, int>(r, c);
  }
  G[N - 1][M] = K;
  P[K] = pair<int, int>(N - 1, M);
  G[N][M - 1] = K + 1;
  P[K + 1] = pair<int, int>(N, M - 1);
  G[N][M] = K + 2;
  P[K + 2] = pair<int, int>(N, M);
  vis = vector<int>(K + 3, -1);
  for (int i = 0; i < K + 3; i++) {
    if (vis[i] != -1) continue;
    queue<int> q;
    q.push(P[i].first * (M + 1) + P[i].second);
    vis[i] = ccnt;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int r = u / (M + 1);
      int c = u % (M + 1);
      for (int k = 0; k < 4; k++) {
        int nr = r + dy[k];
        int nc = c + dx[k];
        if (nr < 0 || N < nr) continue;
        if (G[nr].find(nc) == G[nr].end()) continue;
        if (vis[G[nr][nc]] != -1) continue;
        q.push(nr * (M + 1) + nc);
        vis[G[nr][nc]] = ccnt;
      }
    }
    ccnt++;
  }
  rseg = vector<pair<int, int> >(ccnt, pair<int, int>(1e9, -1e9));
  cseg = vector<pair<int, int> >(ccnt, pair<int, int>(1e9, -1e9));
  for (int i = 0; i < K + 3; i++) {
    rseg[vis[i]].first = min(rseg[vis[i]].first, P[i].first);
    rseg[vis[i]].second = max(rseg[vis[i]].second, P[i].first);
    cseg[vis[i]].first = min(cseg[vis[i]].first, P[i].second);
    cseg[vis[i]].second = max(cseg[vis[i]].second, P[i].second);
  }
  dest = vis[G[N][N]];
  for (int i = 0; i < ccnt; i++) {
    if (i == dest && G[N - 1].find(M - 1) == G[N - 1].end()) continue;
    rseg[i].first--;
    rseg[i].second++;
    cseg[i].first--;
    cseg[i].second++;
  }
  queue<int> q;
  chk = vector<int>(ccnt, -1);
  q.push(vis[G[0][0]]);
  chk[vis[G[0][0]]] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == dest) {
      printf("%d", chk[u]);
      return 0;
    }
    for (int i = 0; i < ccnt; i++) {
      if (i == u) continue;
      if (chk[i] != -1) continue;
      if (con(u, i)) {
        q.push(i);
        chk[i] = chk[u] + 1;
        if (i == dest) {
          printf("%d", chk[i]);
          return 0;
        }
      }
    }
  }
  printf("-1");
  return 0;
}
