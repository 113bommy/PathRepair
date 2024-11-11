#include <bits/stdc++.h>
using namespace std;
const int DIM = 405;
const int INF = 2e9;
int N, M;
int d[DIM];
bool rail[DIM][DIM], inq[DIM];
vector<int> a[DIM], b[DIM];
queue<int> Q;
void solve(vector<int> v[]) {
  for (int i = 2; i <= N; ++i) d[i] = INF;
  Q.push(1);
  inq[1] = 1;
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    inq[node] = 0;
    for (vector<int>::iterator it = v[node].begin(); it != v[node].end();
         ++it) {
      int v = *it;
      if (d[v] > d[node] + 1) {
        d[v] = d[node] + 1;
        if (!inq[v]) {
          Q.push(v);
          inq[v] = 1;
        }
      }
    }
  }
  cout << (d[N] != INF ? d[N] : INF);
}
int main() {
  cin >> N >> M;
  if (M == 0 || M == (N * (N - 1)) / 2) {
    cout << -1;
    return 0;
  }
  for (int i = 1, x, y; i <= M; ++i) {
    cin >> x >> y;
    rail[x][y] = 1;
    rail[y][x] = 1;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 1; i < N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      if (!rail[i][j]) {
        b[i].push_back(j);
        b[j].push_back(i);
      }
    }
  }
  if (rail[1][N])
    solve(b);
  else
    solve(a);
  return 0;
}
