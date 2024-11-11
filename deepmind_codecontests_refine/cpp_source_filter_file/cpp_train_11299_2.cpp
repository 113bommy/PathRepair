#include <bits/stdc++.h>
using namespace std;
int N, M;
int dist[2][3000][3000];
vector<vector<int> > adj[2];
vector<vector<pair<int, int> > > vt[2];
void dijkstra(int start, int flag) {
  dist[flag][start][start] = 0;
  priority_queue<pair<int, int> > pq;
  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if (dist[flag][start][here] < cost) continue;
    for (int i = 0; i < adj[flag][here].size(); i++) {
      int there = adj[flag][here][i];
      int nextDist = cost + 1;
      if (dist[flag][start][there] > nextDist) {
        dist[flag][start][there] = nextDist;
        pq.push(make_pair(-nextDist, there));
      }
    }
  }
  for (int i = 0; i < N; i++)
    if (dist[flag][start][i] != 0x3f3f3f3f)
      vt[flag][start].push_back(make_pair(dist[flag][start][i], i));
  sort(vt[flag][start].begin(), vt[flag][start].end(),
       greater<pair<int, int> >());
}
int main() {
  scanf("%d %d", &N, &M);
  adj[0].resize(N);
  adj[1].resize(N);
  vt[0].resize(N);
  vt[1].resize(N);
  int from, to;
  while (M--) {
    scanf("%d %d", &from, &to);
    from--;
    to--;
    adj[0][from].push_back(to);
    adj[1][to].push_back(from);
  }
  memset(dist, 0x3f, sizeof(dist));
  for (int i = 0; i < N; i++) {
    dijkstra(i, 0);
    dijkstra(i, 1);
  }
  int curMax = -1;
  int v1, v2, v3, v4;
  v1 = v2 = v3 = v4 = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (dist[0][i][j] == 0x3f3f3f3f) continue;
      for (int ss = 0; (ss < 3) && (ss < vt[1][i].size()); ss++) {
        int s = vt[1][i][ss].second;
        if (s == i || s == j) continue;
        if (dist[1][s][i] == 0x3f3f3f3f) continue;
        for (int ee = 0; (ee < 4) && (ee < vt[0][j].size()); ee++) {
          int e = vt[0][j][ee].second;
          if (e == i || e == j || e == s) continue;
          if (dist[0][j][e] == 0x3f3f3f3f) continue;
          int curDist = dist[1][i][s] + dist[0][i][j] + dist[0][j][e];
          if (curMax < curDist) {
            curMax = curDist;
            v1 = s;
            v2 = i;
            v3 = j;
            v4 = e;
          }
        }
      }
    }
  }
  printf("%d %d %d %d\n", v1 + 1, v2 + 1, v3 + 1, v4 + 1);
  return 0;
}
