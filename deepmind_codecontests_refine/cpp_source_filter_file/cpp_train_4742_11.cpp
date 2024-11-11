#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 30;
vector<vector<char>> mat;
long long n, m;
vector<vector<long long>> graph;
vector<bool> u;
void KingtoGraph(char wall) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long k = i * m + j;
      if (i != 0 && mat[i - 1][j] != wall) graph[k].push_back(k - m);
      if (j != 0 && mat[i][j - 1] != wall) graph[k].push_back(k - 1);
      if (i != n - 1 && mat[i + 1][j] != wall) graph[k].push_back(k + m);
      if (j != m - 1 && mat[i][j + 1] != wall) graph[k].push_back(k + 1);
    }
  }
}
void DFS(long long s) {
  u[s] = 1;
  for (long long i = 0; i < graph[s].size(); i++) {
    long long to = graph[s][i];
    if (!u[to]) DFS(to);
  }
}
int main() {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  graph.resize(n * m);
  u.resize(n * m);
  char c;
  mat.resize(n, vector<char>(m));
  vector<long long> w;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> c;
      mat[i][j] = c;
      if (c == 'B') w.push_back(i * m + j);
    }
  }
  KingtoGraph('.');
  long long k = 0;
  for (long long i = 0; i < w.size(); i++) {
    if (!u[i]) {
      DFS(i);
      k++;
    }
  }
  cout << k;
}
