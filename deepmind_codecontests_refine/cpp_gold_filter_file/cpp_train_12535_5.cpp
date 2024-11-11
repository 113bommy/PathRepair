#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
int N, M, K, S1, S2, F;
vector<vector<int> > adj;
vector<int> U, V, W, lval;
vector<long long int> dist;
void dijkstra(int S) {
  dist.clear();
  dist = vector<long long int>(N, INF);
  priority_queue<pair<long long int, long long int> > pq;
  pq.push(pair<long long int, long long int>(0, S));
  dist[S] = 0;
  while (!pq.empty()) {
    long long int now = pq.top().second;
    long long int nowD = -pq.top().first;
    pq.pop();
    if (nowD > dist[now]) continue;
    for (int i = 0; i < adj[now].size(); i++) {
      int e = adj[now][i];
      int nxt = V[e], nxtD = W[e];
      if (dist[nxt] > dist[now] + (long long int)nxtD) {
        dist[nxt] = dist[now] + (long long int)nxtD;
        pq.push(pair<long long int, long long int>(-dist[nxt], nxt));
      }
    }
  }
}
vector<long long int> dist1, dist2;
void relax() {
  dist1.clear();
  dist2.clear();
  dijkstra(S1);
  dist1 = dist;
  dijkstra(S2);
  dist2 = dist;
  for (int i = 0; i < K; i++) {
    int a = U[i + M];
    if (dist1[a] < dist2[a]) {
      W[i + M] = lval[i];
    }
  }
}
long long int f1, f2;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  scanf("%d %d %d", &S1, &S2, &F);
  S1--;
  S2--;
  F--;
  adj.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    U.push_back(--a);
    V.push_back(--b);
    W.push_back(c);
    adj[a].push_back(U.size() - 1);
  }
  lval.resize(K);
  for (int i = 0; i < K; i++) {
    int a, b, l, r;
    scanf("%d %d %d %d", &a, &b, &l, &r);
    U.push_back(--a);
    V.push_back(--b);
    W.push_back(r);
    adj[a].push_back(U.size() - 1);
    lval[i] = l;
  }
  for (int i = 0; i < K; i++) relax();
  dijkstra(S1);
  f1 = dist[F];
  dijkstra(S2);
  f2 = dist[F];
  if (f1 > f2)
    printf("LOSE");
  else if (f1 == f2) {
    printf("DRAW\n");
    for (int i = 0; i < K; i++) {
      printf("%d ", W[i + M]);
    }
  } else {
    printf("WIN\n");
    for (int i = 0; i < K; i++) {
      printf("%d ", W[i + M]);
    }
  }
}
