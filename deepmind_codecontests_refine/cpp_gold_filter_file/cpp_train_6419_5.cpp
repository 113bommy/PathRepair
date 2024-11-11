#include <bits/stdc++.h>
using namespace std;
vector<int> A[1011];
int W[1011][1011];
int T[1011];
int C[1011];
long long D[1011][1011];
int N, M;
bool visited[1011];
void find(int u, int len) {
  set<pair<int, int> > Q;
  Q.insert(make_pair(0, u));
  memset(visited, 0, sizeof visited);
  while (!Q.empty()) {
    pair<int, int> t = *Q.begin();
    Q.erase(Q.begin());
    int v = t.second;
    int cost = t.first;
    if (cost > len) return;
    if (visited[v]) continue;
    visited[v] = 1;
    D[u][v] = cost;
    for (int i = 0; i < A[v].size(); i++) {
      int vv = A[v][i];
      if (!visited[vv]) {
        Q.insert(make_pair(cost + W[v][vv], vv));
      }
    }
  }
}
int WW[1011][1011];
vector<int> Adj[1011];
long long djikstra(int src, int dest) {
  set<pair<long long, int> > Q;
  Q.insert(make_pair(0, src));
  memset(visited, 0, sizeof visited);
  while (!Q.empty()) {
    pair<long long, int> t = *Q.begin();
    Q.erase(Q.begin());
    int v = t.second;
    long long cost = t.first;
    if (visited[v]) continue;
    visited[v] = 1;
    if (v == dest) return cost;
    for (int i = 0; i < Adj[v].size(); i++) {
      int vv = Adj[v][i];
      if (!visited[vv]) {
        Q.insert(make_pair(cost + WW[v][vv], vv));
      }
    }
  }
  return -1;
}
int main() {
  for (int i = 1; i < 1011; i++)
    for (int j = 1; j < 1011; j++) D[i][j] = (long long)1e15;
  scanf("%d %d", &N, &M);
  int first, second;
  scanf("%d %d", &first, &second);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if (W[u][v] == 0) {
      W[u][v] = W[v][u] = w;
      A[u].push_back(v);
      A[v].push_back(u);
    } else
      W[u][v] = W[v][u] = min(W[u][v], w);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &T[i], &C[i]);
    find(i, T[i]);
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (D[i][j] != (long long)1e15 && i != j) {
        WW[i][j] = C[i];
        Adj[i].push_back(j);
      }
    }
  }
  long long ret = djikstra(first, second);
  cout << ret << endl;
  return 0;
}
